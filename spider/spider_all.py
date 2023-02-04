import urllib.request as UR
import random, time, re
from lxml import etree
import json, os
import urllib.parse as urlParse

def delay(n=1):
   time.sleep(random.random()*n)
   return None

def random_headers(isPc, cookie = None): #isPc: 是否是PC端 有的时候，random_headers函数可以不用使用，headers单独写。
    if isPc:
        ua = [ "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.84 Safari/537.36","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36",   "Mozilla/5.0 (X11; Ubuntu; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2919.83 Safari/537.36",   "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.19582" ] 
    else:
         ua = [ "Mozilla/5.0 (iPhone; CPU iPhone OS 13_2_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.0.3 Mobile/15E148 Safari/604.1","Mozilla/5.0 (iPad; CPU OS 13_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) CriOS/87.0.4280.77 Mobile/15E148 Safari/604.1","Mozilla/5.0 (Linux; Android 8.0.0; SM-G955U Build/R16NW) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.141 Mobile Safari/537.36","Mozilla/5.0 (iPhone; CPU iPhone OS 13_2_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.0.3 Mobile/15E148 Safari/604.1"]
    
    if cookie == None:
        headers = {"User-Agent": random.choice(ua)}
    else:
        headers = {"User-Agent": random.choice(ua), "cookie":cookie}
    
    
    return headers

def get_htmlData(url, Method, decodel=None, headers=None, encodel=None, data_dic=None, cnt=None):
    if cnt == None:
        cnt = 3
    if decodel == None:
        decodel = "utf-8"
    data = None
    out_time = 5
    n = 1
    while True:
        if n>=cnt:
            break
        try:
            if n > 1:            
                print("第%s次请求开始%s"%(n, url))
            if Method == "POST":
                if data_dic == None:
                    print("data_dic is empty !")
                    break
                if encodel == None:
                    encodel = "utf-8"
                formdata = urlParse.urlencode(data_dic).encode(encodel,"ignore")
                response = UR.Request(url=url, headers=headers, method=Method)
                pre_data = UR.urlopen(response, formdata, timeout=out_time)   #POST
                charset = pre_data.info().get_param("charset")
                if charset != None:
                    decodel = charset
            elif Method == "GET":
                request  = UR.Request(url=url, headers=headers, method=Method)  #GET
                pre_data = UR.urlopen(request, timeout=out_time)
                charset = pre_data.info().get_param("charset")
                if charset != None:
                    decodel = charset
            else:
                print("目前只支持GET和POST这两种方式")
                break
            data = pre_data.read().decode(decodel,"ignore") #
        except Exception as error:
            print(error)
        #循环判断
        if data != None:
            break
        else:
            out_time += 2
            n += 1
            delay(1)
    return data

def html_lxml(data, xpath):   #lxml方式
    if data != None:
        node = etree.HTML(data)
        item = node.xpath(xpath)
        return item         #返回列表
    else:
        return None

def html_re(data, pattern, returnList, num=0):  #正则表达
    info = re.compile(pattern, re.S) #预编译
    if data == None:
        return None
    if returnList:
        item = info.findall(data)
        return item           #返回列表
    else:
        item = info.search(data)
        if item != None:
            return item.group(num)  #返回字符串

def File_output(file, content, Mode):
    if content == None:
        print("数据为空！")
        return None
    with open(file, Mode,  encoding="utf-8") as out_txt:        
        out_txt.write(content)
    out_txt.close()

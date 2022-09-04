"""爬虫基本方法集合"""
import urllib.request as UR
import urllib.parse as urlParse
from lxml import etree
import re

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

class Spider(object):
    url = None
    __timeout = 5
    __decode = "UTF-8"
    __encode = __decode
    __headers = None
    
    def __init__(self, url, headers=None):
        Spider.url = url
        Spider.__headers = headers
    
    """设置参数"""
    def set_decode(self, decode):
        Spider.__decode = decode
        
    def set_encode(self, encode):
        Spider.__encode = encode
    
    def set_headers(self, headers):
        Spider.__headers = headers
    
    """获取数据"""
    def get(self):
        DATA = None
        try:
            request = UR.Request(url=self.url, headers=self.__headers, method="GET")
            DATA = UR.urlopen(request, timeout=self.__timeout).read().decode(self.__decode)
        except Exception as error:
            print(error)
        return DATA
    
    def post(self, _dic):
        DATA = None
        try:
            formdata = urlParse.urlencode(_dic).encode(self.__encode)
            response = UR.Request(url=self.url, headers=self.__headers, method="POST")
            DATA = UR.urlopen(response, formdata, timeout=self.__timeout).read().decode(self.__decode)
        except Exception as error:
            print(error)
        return DATA
            
          
            
if __name__ == "__main__":
    headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36 Edg/105.0.1343.27"}
    url = "https://blog.jtjiang.top"
    A = Spider(url)
    # A.set_headers(headers)
    #print( A.get() )
    
    headers = {
        "cookie":" __51uvsct__JdLDYHeKCcFvKg5S=1; __51vcke__JdLDYHeKCcFvKg5S=01b19ce8-ea5c-5115-bb14-482c4dd5ffec; __51vuft__JdLDYHeKCcFvKg5S=1662298745200; Hm_lvt_0c7836ac8678d921d1d4ad74e6affa81=1662298746; XSRF-TOKEN=eyJpdiI6ImVjR01GRnZTdW9qcVpUK1JScysveUE9PSIsInZhbHVlIjoibFlXL29KaEtDS0JMTXQvNndaczB3SlVaSk5kVEV6WXNOUG1IYUhFMDFoSjdOUzdXKzc2M2NRZEtVRzdOMmN3MmZUUXp4N2hreGsrem42cWV5Z05iKys0WHcwTmRXUjltZDI2N0crUGFDWlU3TnRkRGNTeGdBSjQ0YW8vQUxzOXkiLCJtYWMiOiI0YTY0ODM5MzYwNGU0MTdmZDg4ZGJjMGMxZTA1MjRlYjY5ZDM2NTU1N2ZmZTgxODZjYjEyYTUzMDU0N2QzNTI1IiwidGFnIjoiIn0%3D; _session=eyJpdiI6IndjRWR3WWZIS0FOejhzaEhBdmd3cGc9PSIsInZhbHVlIjoiRnhCM1FISGVBaVc0YlUxbGNKcDg0TGVqUXlGZnRIM1l0RmZ0UlkrVis4bHhFNGUvUVBGdkJveXZkZlZoeFhtTXdJQ0wzODNlUWhERzd2bE1hWDJnbnl4L0IzVlNydFNFRFFqSkdHL3NsTnNHU3N3R0dwYkNQOVUrMGVTK0hnVm4iLCJtYWMiOiIxYTFlY2I0MzZmZWI3MTI5N2E2N2M2OWM0NTE5N2IyNzZkOGNkNmE5NWM5ZDAwYTQzMzg4NzA1MzNkNzhjMWUyIiwidGFnIjoiIn0%3D; __vtins__JdLDYHeKCcFvKg5S=%7B%22sid%22%3A%20%2276494493-a165-5977-8d75-e7a3491a8869%22%2C%20%22vd%22%3A%203%2C%20%22stt%22%3A%2019677%2C%20%22dr%22%3A%2013342%2C%20%22expires%22%3A%201662300564871%2C%20%22ct%22%3A%201662298764871%7D; Hm_lpvt_0c7836ac8678d921d1d4ad74e6affa81=1662298765",
        "origin":"https://www.foreverblog.cn",
        "referer": "https://www.foreverblog.cn/blogs.html",
        "sec-ch-ua": '"Microsoft Edge";v="105", " Not;A Brand";v="99", "Chromium";v="105"',
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36 Edg/105.0.1343.27",
        "x-csrf-token": "lyrnEwaTqfnIOEN0pyLzWZomPbMFbMl5u338Tg3h",
        "x-requested-with": "XMLHttpRequest"
    }
    url = "https://www.foreverblog.cn/blogs"
    A.url = url
    DIC = {"page":"2","year": "2019"}
    A.set_headers(headers)
    print ( A.post(DIC) )
    
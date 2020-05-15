import urllib.request
from lxml import etree
import urllib.error
import random
import ssl

class text_con(object):
    
    def get_keyinfo(self, url):
        ua_list = [
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:72.0) Gecko/20100101 Firefox/72.0",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.29 Safari/537.36",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.18362",
            "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3741.400 QQBrowser/10.5.3863.400"
            ]
        ua = random.choice(ua_list)
        headers = {'User-Agent': ua}

        ssl._create_default_https_context = ssl._create_unverified_context
        file = open('blogroll.html', 'a', encoding='utf-8')
        try:
            request = urllib.request.Request(url=url, headers=headers)
            data = urllib.request.urlopen(request, timeout=5).read().decode('utf8', 'ignore')      
        
            node = etree.HTML(data)
            title = node.xpath('/html/head/title/text()')
            keyword = node.xpath('//meta[@name="keywords"]/@content')
            if (len(keyword) == 0):
                keyword =[""]
            description = node.xpath('//meta[@name="description"]/@content')
            if (len(description) == 0):
                description =[""]
        
            file.write("<p>"+ '<a><a href="'+ url + '" target="blank">' + title[0] + "</a>"+"<br>"+ "keywords："+keyword[0].replace(",", "&nbsp;&nbsp;") +"<br>" +"description："+description[0]+"</p>"+"\n")
            file.close()
            print('写入中..')
        except :
            file.write("<p>error：" + "&nbsp;&nbsp;" + url +"</p>"+"\n")
            file.close()
            print("error")
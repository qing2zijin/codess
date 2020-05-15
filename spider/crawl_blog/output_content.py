import urllib.request
from lxml import etree
import urllib.error
import ssl

class text_con(object):
    
    def get_keyinfo(self, url):
    
        ssl._create_default_https_context = ssl._create_unverified_context

        file = open('blogroll.html', 'a', encoding='utf-8')

        try:
            res = urllib.request.urlopen(url, timeout=5)
                  
            data = res.read().decode('utf8', 'ignore')
        
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
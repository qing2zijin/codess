import urllib.request
from lxml import etree
import random

class replace_url(object):
    
    def blog_url(self, temp_url, xpath_pat):
        
        try:
            
            request = urllib.request.Request(url=temp_url)
            data = urllib.request.urlopen(request).read().decode('utf8')
            node = etree.HTML(data)
            real_url = node.xpath(xpath_pat)
            return real_url[0]
        except:
            print("error")
            return temp_url
            
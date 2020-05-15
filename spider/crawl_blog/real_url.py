import urllib.request
from lxml import etree
import random

class replace_url(object):
    
    def blog_url(self, temp_url, xpath_pat):
        ua_list = [
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:72.0) Gecko/20100101 Firefox/72.0",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.29 Safari/537.36",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.18362",
            "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3741.400 QQBrowser/10.5.3863.400"
            ]
        ua = random.choice(ua_list)
        headers = {'User-Agent': ua}

        try:
            request = urllib.request.Request(url=temp_url, headers=headers)
            data = urllib.request.urlopen(request, timeout=5).read().decode('utf8')
            node = etree.HTML(data)
            real_url = node.xpath(xpath_pat)
            return real_url[0]
        except:
            print("error")
            return temp_url
            
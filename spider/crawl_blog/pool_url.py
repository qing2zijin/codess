import urllib.request
import urllib.parse
import re
import random
import json

class url_addr(object):
    
    def crawl_url(self, api_url, max_pagenum):
        ua_list = [
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:72.0) Gecko/20100101 Firefox/72.0",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.29 Safari/537.36",
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.18362",
            "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3741.400 QQBrowser/10.5.3863.400"
            ]
        ua = random.choice(ua_list)
        headers = {'User-Agent': ua}
        for i in range(max_pagenum, 0, -1):
            try:
                values = {
                    'page': str(i)
                }
                formdata = urllib.parse.urlencode(values).encode('utf8')
                response = urllib.request.Request(url=api_url, headers=headers)
                data = urllib.request.urlopen(response, formdata, timeout=5).read().decode('utf8')
                
                pat = '"url":"(.*?)"}\S'
                url_addr = re.compile(pat, re.S).findall(data)
                
                #整理url
                for j in range(len(url_addr)-1, -1, -1):
                        url_addr[j] = json.loads(json.dumps(url_addr[j].encode('utf8').decode("unicode_escape").replace("\/", "/")))
                        yield  url_addr[j]
            except:
               yield api_url
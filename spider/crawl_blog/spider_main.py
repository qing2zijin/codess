import pool_url
import real_url
import output_content

class SpiderMain:   
    
    def __init__(self):
        self.roll_urls = pool_url.url_addr()    #通过十年之约api接口获得URL
        self.get_real = real_url.replace_url() #替换URL并且爬取对应网址信息
        self.outputer = output_content.text_con()  #保存到文件中
    
    def crawl(self,root_url, max_pagenum):
        temp_url = self.roll_urls.crawl_url(root_url, max_pagenum)
        for i in temp_url:
            url = self.get_real.blog_url(i, '//div[@class="cleft"]/a/@href')
            self.outputer.get_keyinfo(url)
            
if __name__ == '__main__':
    root_url = 'https://foreverblog.cn/api/blogs'
    max_pagenum = 5
    
    file = open('blogroll.html', 'w', encoding='utf-8')
    file.write('<html><head><meta charset="utf-8"><title>blogroll</title><link rel="icon" href="/favicon.ico"></head><body><h1>Blogroll</h1><hr>'+"\n")
    file.close()
    
    obj_spider = SpiderMain()
    obj_spider.crawl(root_url, max_pagenum)
    
    file_2 = open('blogroll.html', 'a', encoding='utf8')
    file_2.write('</body></html>')
    file_2.close()

import urllib.request as UR
import urllib.error  as UE
from lxml import etree
import re

url = ["http://blog.jtjiang.top/index.html", "http://blog.jtjiang.top/pages/2.html"]
header = {'User-Agent':'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.54 Safari/537.36'}
Rurl = []

#获取网页里面需要的链接
for i in url:
    try:
        request = UR.Request(i, headers=header)
        data = UR.urlopen(request, timeout=5).read().decode('utf-8')
        node = etree.HTML(data)
        Rurl_r = node.xpath('//span[@class="archive-post-title"]/a/@href')
    except UE.URLError as e:
        print(e)
        continue
    for j in Rurl_r:
        Rurl.append(j.replace("..", ""))

#输出
import html2text 

pattern_title = '<title>(.*?)</title>'                            #标题
pattern_keywords = '<meta name="keywords" content="(.*?)">'       #关键词
pattern_description = '<meta name="description" content="(.*?)">' #摘要
pattern_date = '<time class="post-time">(.*?)</time>'             #时间
pattern_tags = 'class="post-tags"> <span>(.*?)</span>'            #标签
pattern_content = '<div class="post-content">(.*?)</div>'         #内容

for k in Rurl:
    article_url = 'http://blog.jtjiang.top/' + k.replace("/posts", "posts") #特殊路径，不具有代表性
    try:
        requests = UR.Request(article_url, headers=header)
        data = UR.urlopen(requests, timeout=5).read().decode('utf-8')
    except UE.URLError as exp:
        print(exp)    
        continue
    title = re.search(pattern_title, data, re.S).group(1)
    keywords = re.search(pattern_keywords, data, re.S).group(1)
    description = re.search(pattern_description, data, re.S).group(1)
    date = re.search(pattern_date, data, re.S).group(1)
    tags = re.search(pattern_tags, data,re.S).group(1)
    contents_html = re.search(pattern_content, data.replace("\n", ""), re.S).group(1) #这里的替换是一个关键，要不然匹配不到
    
    contents = html2text.html2text(contents_html)                                         #html转markdown
    out_path = 'test/source/'+k.replace("/posts/", "").replace("posts/", "").replace("html", "md") #特殊路径，不具有代表性
    with open(out_path, "w", encoding='utf-8', errors='xmlcharrefreplace') as md_content:
        '''专门针对个别网页进行的优化'''        
        md_content.write( \
        "---\ntitle:" + title + "\nkeywords:" + \
        keywords.replace(",月牙博客", "") + "\ndescription:" + \
        description + "\ndate:" + \
        date + "\ntags:" + \
        tags + "\n---\n" + \
        contents)
    md_content.close()

# 当然上面的第二段代码可以改成多线程的，运行速度可以快点。
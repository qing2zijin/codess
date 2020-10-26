
# vector

可变长动态数组 vector [learn source](http://c.biancheng.net/cplus/80/),[learn source_2](http://www.cplusplus.com/reference/vector/vector/)


vector():创建一个空vector
vector(int nSize):创建一个vector,元素个数为nSize
vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
vector(const vector&):复制构造函数
vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中

所有容器都有以下两个成员函数：

int size()：返回容器对象中元素的个数。
bool empty()：判断容器对象是否为空。


有以下成员函数：

begin()：返回指向容器中第一个元素的迭代器。
end()：返回指向容器中最后一个元素后面的位置的迭代器。
rbegin()：返回指向容器中最后一个元素的反向迭代器。
rend()：返回指向容器中第一个元素前面的位置的反向迭代器。
erase(...)：从容器中删除一个或几个元素。该函数参数较复杂，此处省略。
clear()：从容器中删除所有元素。



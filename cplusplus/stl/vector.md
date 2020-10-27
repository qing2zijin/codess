# vector

可变长动态数组 vector [learn source_1](http://c.biancheng.net/cplus/80/)，[learn source_2](http://www.cplusplus.com/reference/vector/vector/)

## vector 如何初始化

1. `vector()`:创建一个空vector
2. `vector(int nSize)`:创建一个vector,元素个数为nSize
3. `vector(int nSize,const t& t)`:创建一个vector，元素个数为nSize,且值均为t
4. `vector(const vector&)`:复制构造函数
5. `vector(begin,end)`:复制(begin,end)区间内另一个数组的元素到vector中

所有容器都有以下两个成员函数：

1. `int size()`：返回容器对象中元素的个数。
2. `bool empty()`：判断容器对象是否为空。


除此之外，还有以下成员函数：

1. `begin()`：返回指向容器中第一个元素的迭代器。
2. `end()`：返回指向容器中最后一个元素后面的位置的迭代器。
3. `rbegin()`：返回指向容器中最后一个元素的反向迭代器。
4. `rend()`：返回指向容器中第一个元素前面的位置的反向迭代器。
5. `erase(...)`：从容器中删除一个或几个元素。
6. `clear()`：从容器中删除所有元素。



// http://c.biancheng.net/view/351.html
// C++ list，STL list（双向链表）
// list 是顺序容器的一种。list 是一个双向链表。使用 list 需要包含头文件 list。
// 双向链表的每个元素中都有一个指针指向后一个元素，也有一个指针指向前一个元素，

/************* 1  ****************/

#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
class A{
	private:
		int n;
	public:
		A(int n_ ){ n = n_; }	//constructor function
		friend bool operator == (const A&a1, const A &a2);
		friend bool operator < (const A &a1, const A &a2);
		friend ostream &operator <<(ostream &o, const A &a);
};
bool operator <(const A &a1, const A & a2)
{
	return (a1.n < a2.n);
}
bool operator ==(const A &a1, const A &a2)
{
	return (a1.n == a2.n);
}
ostream & operator <<(ostream &o, const A &a)	//out put
{
	o << a.n;
	return o;
}

template <typename T>
void Print(T first, T last)
{
	for(; first != last; ++first)
		cout<< *first << " ";
	cout << endl;
}


int main(void)
{
	A a[5] = {1,3, 2, 4, 2};
	A b[7] = {10, 30, 20, 30, 30, 40, 40};
	
	list<A>  lst1(a, a+5), lst2(b, b+7);  //define two list, its length is 5 and 7.
	
	lst1.sort();
	cout << "1.(a) ";Print(lst1.begin(), lst1.end());	//output: (a) 1 2 2 3 4
	lst1.remove(2); 			//delete all elememty  equal to A(2);
	cout << "2.(a) ";Print(lst1.begin(), lst1.end()); //output: (a) 1 3 4

	lst2.pop_front();	//delete first elementy
	cout << "3.(b) ";Print(lst2.begin(), lst2.end()); //output: (b) 30 20 30 30 40 40
	lst2.unique(); 		//delete all elementy equal to before one elementy.
	cout << "4.(b) ";Print(lst2.begin(), lst2.end()); //output: (b) 30 20 30    40
	lst2.sort();	//pai xu
	
	lst1.merge(lst2); //he bing lst2 dao lst1, bing qing kong lst2.
	cout << "5.(a) ";Print(lst1.begin(), lst1.end()); //output: (a) 1 3 4 30 20 30 40
	cout << "6.(b)";Print(lst2.begin(), lst2.end()); //output: 6.(b)

	lst1.reverse();		//jiang lst1 qian hou dian dao
	cout<<"7.(a) ";Print(lst1.begin(), lst1.end());//output: 7.(a) 40 30 20 30 4 3 1

	lst2.insert(lst2.begin(), a+1, a+4); //insert 3, 2, 4 into lst2

	list<A>::iterator p1, p2, p3;
       	p1 = find(lst1.begin(), lst1.end(), 30);
	p2 = find(lst2.begin(), lst2.end(), 2);
	p3 = find(lst2.begin(), lst2.end(), 4);
	
	lst1.splice(p1, lst2, p2, p3);  //将[p2, p3)插入p1之前，并从 lst2 中删除[p2,p3)
	//void splice(iterator i, list <T> & x, iterator first, iterator last) 
	//在位置 i 前面插入链表 x 中的区间 [first, last)，并在链表 x 中删除该区间。
	//链表自身和链表 x 可以是同一个链表，只要 i 不在 [first, last) 中即可
		
	cout<<"8.(a) ";Print(lst1.begin(), lst1.end());//8(a) 40 2 30 30 20 4 3 1
	cout<< "9.(6)";Print(lst2.begin(), lst2.end());//9(b) 3 4

	return 0;
}
/*
1.(a) 1 2 2 3 4 
2.(a) 1 3 4 
3.(b) 30 20 30 30 40 40 
4.(b) 30 20 30 40 
5.(a) 1 3 4 20 30 30 40 
6.(b)
7.(a) 40 30 30 20 4 3 1 
8.(a) 40 2 30 30 20 4 3 1 
9.(6)3 4 
*/

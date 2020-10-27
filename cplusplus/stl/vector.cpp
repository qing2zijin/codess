//vector size()
/*
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	vector<int> intvec; //define a int vector
	cout<<"its size: "<<intvec.size()<<endl; //its size: 0
	
	for(int i=0; i<10; ++i)
		intvec.push_back(i);
	cout<<"its size: "<<intvec.size()<<endl;	//10

	return 0;
}
*/

//vector insert()
//summarize:
//	insert(). first factor position, second factor position, thirth factor  position 

/*
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{	
	vector<int> intvec(3, 100);  //create an int vector intvec,ite member have 3, and everyone is 100. (100 100 100)
	vector<int>::iterator it; //create an iterator , it
	it = intvec.begin();	//return begin  iterator.
	it = intvec.insert(it, 200);//insert  200 into invec at head.		(200 100 100).
	intvec.insert(it, 2, 200); //insert  three 200  into invec  at head.	(200 200 200 100 100 100)
	
	it = intvec.begin();
	
	vector<int> another_vec(2, 400);
	intvec.insert(it+2, another_vec.begin(), another_vec.end());

	int array[] = {510, 511, 512};
	intvec.insert(intvec.begin(), array, array+3);//insert an array into intvec at head.
	cout<<"intvec contains: ";
	for(it=intvec.begin(); it<intvec.end();++it)
		cout<<" "<<*it;
	cout<<endl;

	return 0;
}
/*
intvec contains:  510 511 512 200 200 400 400 200 100 100 100
*/

//vector 排序

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	vector<int> intvec;
	intvec.push_back(1);
	intvec.push_back(3);
	intvec.push_back(2);

	sort(intvec.begin(), intvec.end() );	//cong xiao dao da
	cout << "cong xiao dao da: ";
	for(int i=0; i<intvec.size(); ++i)
		cout << intvec[i] << " ";
	cout << endl;

	reverse(intvec.begin(), intvec.end() ); //cong da dao xiao
	cout<< "cong da dao xiao: ";
	for(int i=0; i<intvec.size(); ++i)
		cout << intvec[i]<<" ";
	cout<<endl;

	cout<<"use iteraor : "<<"\ncong da dao xiao: ";
	vector<int>::iterator k;//  //定义正向迭代器
	for(k=intvec.begin(); k != intvec.end(); ++k)
		cout << *k<<" ";
	cout << endl;

	return 0;
}
/*
cong xiao dao da: 1 2 3 
cong da dao xiao: 3 2 1 
use iteraor : 
cong da dao xiao: 3 2 1  
 * */

//vector 还可以嵌套以形成可变长的二维数组
/*
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char*argv[])
{
	vector<vector<int> > intv(3);	// int 后面的两个>之间需要有空格，否则有的编译器会把它们当作>>运算符，编译会出错. create a dim two vector
	
	for(int i=0; i<intv.size(); ++i)
		for(int j=0; j<4; ++j)
			intv[i].push_back(j); //insert j in every i row.

	for(int i=0; i<intv.size(); ++i)
	{
		for(int j=0; j<intv[i].size(); ++j)
			cout << intv[i][j] << " "; 
		cout << endl;
	}
	
	return 0;
}
*/
/*
0 1 2 3 
0 1 2 3 
0 1 2 3 
 * */

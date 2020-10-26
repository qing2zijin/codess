//vector size()

#include<iostream>
#include<vector>
using namespace std;
/*
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

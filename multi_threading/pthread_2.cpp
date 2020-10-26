#include<iostream>
#include<pthread.h>

using namespace std;

#define NUM_THREADS 5

void * PrintHello(void*threadid)
{
	int tid = *(int *)threadid;
	cout<<"Hello kevin ! thread id: "<<tid<<endl;
	pthread_exit(NULL);
	//return 0;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	int indexs[NUM_THREADS];
	int rec, i;

	for(i=0; i<NUM_THREADS; ++i)
	{
		cout<<"main(): create thread: "<<i<<endl;
		indexs[i] = i;
		rec =pthread_create(&threads[i], NULL, PrintHello,(void*)&(indexs[i]));
		if(rec != 0){
			cout<<"Error: create failed."<<rec<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);

	//return 0;

}
/*
 *main(): create thread: 0
main(): create thread: 1
main(): create thread: 2
main(): create thread: 3
main(): create thread: 4
Hello kevin ! thread id: 4
Hello kevin ! thread id: 3
Hello kevin ! thread id: 2
Hello kevin ! thread id: 1
Hello kevin ! thread id: 0

 * */

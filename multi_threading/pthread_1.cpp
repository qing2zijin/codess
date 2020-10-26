#include<iostream>
#include<pthread.h>
using namespace std;

#define NUM_THREADS 5

void * Hello(void *args)
{
	cout<<"Hello!"<<endl;
	return 0;
}
int main(void)
{
	pthread_t tids[NUM_THREADS];
	for(int i=0; i<NUM_THREADS;++i)
	{
		int ret = pthread_create(&tids[i], NULL, Hello, NULL);
		if(ret != 0)
			cout<<"pthread_create error: error_code"<<ret<<endl;
	}
	pthread_exit(NULL);
	return 0;
}

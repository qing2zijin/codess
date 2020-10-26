#include<iostream>
#include<cstdlib>
#include<pthread.h>

using namespace std;
#define NUM_THREADS 5

struct thread_data{
	int thread_id;
	char * message;
};
void * PrintHello(void * threadarg)
{
	struct thread_data * my_data;
	my_data = (struct thread_data *)threadarg;
	cout<<"Thread ID: "<<my_data->thread_id;
	cout<<"\tMessage: "<<my_data->message<<endl;
	pthread_exit(NULL);
}
int main(int argc, char* argv[])
{		
	pthread_t threads[NUM_THREADS];
	struct thread_data tids[NUM_THREADS];

	int rec, i;

	for(i=0; i<NUM_THREADS; ++i)
	{
		cout<<"main(): creating thread : "<<i<<endl;
		tids[i].thread_id = i;
		tids[i].message = (char*)"This is message.";
		
	       rec = pthread_create(&threads[i],NULL,PrintHello, (void*)&tids[i]);
		       if(rec)
		       {
		       	cout<<"ERROR: create failed,"<<rec<<endl;
			exit(-1);
		       }	       
	}
	pthread_exit(NULL);

	//return 0;
}

/*
 *
 *main(): creating thread : 0
main(): creating thread : 1
main(): creating thread : 2
main(): creating thread : 3
main(): creating thread : 4
Thread ID: 4Message: This is message.
Thread ID: 3Message: This is message.
Thread ID: 2Message: This is message.
Thread ID: 1Message: This is message.
Thread ID: 0Message: This is message.
 * */

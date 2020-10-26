/*
#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>

using namespace std;
#define NUM 5

void * wait(void *t)
{
	int i;
//	long tid;
//        tid = (long)t;		
	sleep(1);
	cout<<"Sleeping in thread "<<endl;

	cout<<"Thread with id: "<<(long)t <<"...exiting "<<endl;

	pthread_exit(NULL);	
}

int main(void)
{
	int rec, i;
	pthread_t threads[NUM];
	pthread_attr_t attr;
	void * status;

	//init thread, and set it joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for(i=0; i<NUM; ++i)
	{
		cout<<"main() : creating thread, "<<i <<endl;
		rec = pthread_create(&threads[i], NULL, wait, (void*)&i);
		if(rec)
		{
			cout<<"ERROR: unable to create thread "<<rec<<endl;
			exit(-1);
		}
	}

	//delete proprity await other thread.
	pthread_attr_destroy(&attr);
	for(i=0; i<NUM; ++i)
	{
		rec = pthread_join(threads[i], &status);
		if(rec)
		{
			cout<<"ERROR: unable to join."<<i;
			exit(-1);
		}
		cout<<"Main: completed thread id: "<<i;	
	       	cout<<"\texiting with status: "<<status<<endl;
		
	}
	cout<<"main, progam exiting."<<endl;


	pthread_exit(NULL);
	//return 0;
}
*/
/*main() : creating thread, 0
main() : creating thread, 1
main() : creating thread, 2
main() : creating thread, 3
main() : creating thread, 4
Sleeping in thread 
Thread with id: 140724475840448...exiting 
Sleeping in thread 
Thread with id: 140724475840448...exiting 
Sleeping in thread 
Thread with id: 140724475840448...exiting 
Sleeping in thread 
Thread with id: 140724475840448...exiting 
Sleeping in thread 
Thread with id: 140724475840448...exiting 
Main: completed thread id: 0	exiting with status: 0
Main: completed thread id: 1	exiting with status: 0
Main: completed thread id: 2	exiting with status: 0
Main: completed thread id: 3	exiting with status: 0
Main: completed thread id: 4	exiting with status: 0
main, progam exiting.
*/


#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS     5

void *wait(void *t)
{
   int i;
   long tid;

   tid = (long)t;

   sleep(1);
   cout << "Sleeping in thread " << endl;
   cout << "Thread with id : " << tid << "  ...exiting " << endl;	//gan jue guai guai de 
   pthread_exit(NULL);
}

int main ()
{
   int rc;
   int i;
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

   // 初始化并设置线程为可连接的（joinable）
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for( i=0; i < NUM_THREADS; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, wait, (void *)&i );
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

   // 删除属性，并等待其他线程
   pthread_attr_destroy(&attr);
   for( i=0; i < NUM_THREADS; i++ ){
      rc = pthread_join(threads[i], &status);
      if (rc){
         cout << "Error:unable to join," << rc << endl;
         exit(-1);
      }
      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
   }

   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);
}


#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
	int rc;
	int count=0;
	printf("Entered thread %d, getting spin lock \n",(int *) i);
	
	rc = pthread_spin_lock(&spinlock);
	printf("%d, Thread unlock the spin lock\n",(int *) i);
	
	rc = pthread_spin_unlock(&spinlock);
	printf("%d, Thread complete\n",(int *)i);
	return NULL;
};

int main()
{
	int rc=0;
	pthread_t thread, thread1;

	if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0);
	printf("Main, get spin lock\n");
	rc = pthread_spin_lock(&spinlock); 

	printf("Main, create the spin lock thread\n");
	rc = pthread_create(&thread, NULL, spinlockthread, (int *)1); 

	printf("Main, wait a bit locking the spin lock\n");
	sleep(10); 

	printf("Main, Now unlock the spin lock\n");
	rc = pthread_spin_unlock(&spinlock); 

	if(rc==0)
	printf("\n Main, Thread Successfully unlock\n");
	else
	printf("\n Main, Thread unSuccessfully unlock\n");

	printf("Main, wait for the thread to end\n");
	rc = pthread_join(thread, NULL); 

	printf("Main complete\n");
	return 0;
}

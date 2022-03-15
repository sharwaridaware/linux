#include<stdio.h>
#include<pthread.h>

int sharedvar=5;

void *thread_inc(void *arg)
{
	sharedvar++;
	printf("after incr=%d\n",sharedvar);
}

void *thread_dec(void *arg)
{
	sharedvar--;
	printf("after decr=%d\n",sharedvar);
}

int main()
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, thread_inc, NULL);
	pthread_create(&thread2, NULL, thread_dec, NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread1,NULL);

	printf("sharevar= %d\n",sharedvar);
	return 0;
}

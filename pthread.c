#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
	sleep(2);
	printf("newly created thread is executing\n");
	return NULL;
}

int main(void)
{
	int ret = pthread_create(&tid, NULL, thread1, NULL);
	if(ret)
	printf("thread is not created\n");
	else
	printf("thread is created\n");

	//sleep(2);

	pthread_join(tid, NULL);
	return 0;
}

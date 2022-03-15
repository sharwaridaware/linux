#include<stdio.h>
#include<pthread.h>

void *printhello(void *threadid)
{
	printf("\nHello World\n");
	while(1);
}

int main()
{
	pthread_t thread;
	int rc, t=0;
	printf("Creating thraed\n");

	rc = pthread_create(&thread,NULL,printhello,NULL);
	printf("\n Thread ID : %u",thread);
	sleep(6);

	t=pthread_cancel(thread);

	if(t==0)
	printf("\n cancled thread\n");

	printf("\n Thread ID : %u",thread);
	return 0;
}

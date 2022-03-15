#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

void* proc(void * param)
{
	sleep(2);
	return 0;
}

int main()
{
	pthread_attr_t attr;
	pthread_t id;
	void *stk;
	size_t siz;
	int err;

	size_t my_stksize = 300000;
	void * my_stack;

	pthread_attr_init(&attr, &siz);
	pthread_attr_init(&attr, &stk);

	printf("Default: Addr=%08x default size=%\n",stk,siz);
	my_stack = (void*)malloc(my_stksize);

	pthread_attr_setstack(&attr, my_stack, my_stksize);
	pthread_create(&id, &attr, proc, NULL);

	pthread_attr_getstack(&attr, &stk, &siz);
	printf("newly defined stack: addr=%08x and size=%d\n", stk, siz);

	sleep(3);
	
	return(0);
}


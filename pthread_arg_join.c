#include<stdio.h>
#include<pthread.h>

static void *threadFunc(void *arg)
{
	char *s = (char*) arg;
	printf("%s\n",s);
	sleep(5);
	return (void*) strlen(s);
}

int main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	pthread_create(&t1, NULL, threadFunc, "Hello World sharwari");
	printf("Message from main()\n");
	pthread_join(t1, &res);

	printf("Thread returned %ld\n",(long) res);
	exit(0);
}

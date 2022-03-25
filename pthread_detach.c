#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define NUM_THREADS     3
int i=0;
void *myfun(void *null)
{
	i++;	
	int result=0;
	result = result + i*1000;
	printf("result = %d\n",result);
	
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	const pthread_attr_t attr1;
	int rc, t, status,detach_state;
	//printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);

	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	for(t=0; t<NUM_THREADS; t++)
	{
		printf("Creating thread %d\n", t);
		rc = pthread_create(&thread[t], &attr, myfun, NULL); 
		if (rc)
		{	
			printf("ERROR; return code from pthread_create() is %d\n", rc);
         		exit(-1);
   		}
	}
	
	pthread_attr_getdetachstate(&attr1,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_destroy(&attr);
	for(t=0; t<NUM_THREADS; t++)
	{
		/* explicitly detach a thread even though it was created as joinable */
		rc = pthread_detach(thread[t]);
		if (rc)
		{
			printf("ERROR; return code from pthread_join() is %d\n", rc);
		        exit(-1);
      		}
	      printf("Completed detach with thread %d \n",t);
   	}
	printf("\n Exiting from main Thread\n");
	//pthread_exit(NULL);

}



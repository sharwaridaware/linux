#include<stdio.h>
#include<unistd.h>


int main(void)
{
int pid1;
	printf("current process pid %d\n",getpid());
	pid1 = fork();
	if(pid1==0)
	{
		printf("new child process pid is %d\n", getpid());
		printf("new child parent process ppid is %d\n", getppid());
	}
	else
	{
		execl("/bin/ls","ls","-lh",NULL);
		sleep(3);
		printf("new child process pid is %d\n", getpid());
		printf("new child parent process ppid is %d\n", getppid());
	}

	while(1);
	return 0;
}

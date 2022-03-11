#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t child_one, child_two;
	printf("current/parent pid=%d\n", getpid());
	child_one = fork();

	if (child_one == 0)
	{	
		printf("child ONE pid=%d\n",getpid());
	}
	else
	{
		child_two = fork();
		if(child_two == 0)
		{
			printf("child TWO pid=%d\n",getpid());
		}
		else
		{
			wait();
			printf("parent of ONE & TWO processes pid=%d\n",getpid());
		}
	}
}


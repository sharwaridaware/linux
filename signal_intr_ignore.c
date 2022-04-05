#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
	signal(SIGINT,SIG_IGN);

for (int i=1;;i++)
	{
	printf("%d: Inside main function\n");
	sleep(1);
	}
	return 0;
}

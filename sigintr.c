#include <stdio.h>
#include <signal.h>

void sighand(int signum){
printf("Interrupt signal rec'd.. but no termination on ctrl+c \n");
signal(SIGINT,SIG_DFL);
}

main(){
	int i;
	signal(SIGINT,sighand);
	//signal(SIGINT,SIG_DFL);
	//while(1){
	//}

	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}

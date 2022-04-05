#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int signal)
{
	if(signal == SIGUSR2)
		printf("Received a SIGUSER2 signal\n");
	
exit(0);
}

int main(int argc, const char * argv[])
{
	printf("Registering the signal handler\n");
	signal(SIGUSR2, signal_handler);
	printf("Registering a SIGUSR2 signal\n");
	raise(SIGUSR2);
	printf("Finished main\n");
	return 0;
}

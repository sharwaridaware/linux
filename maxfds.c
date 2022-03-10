#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("max fds: %d\n",getdtablesize());// will get fd table size
	return 0;
	//exit(0);
}

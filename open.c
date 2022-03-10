#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3;
	fd2 = open("lseel11.txt", O_CREAT | O_RDWR, 777);
	printf("the value is %d\n", fd2);
	int close(int fd2);
	return 0;
}

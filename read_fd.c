#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buf[300];
	fd = open("copy.txt", O_RDONLY, 777);
	printf("fd is %d\n",fd);
	read(fd,buf,50);
	printf("%s",buf);
	close(fd);
	return 0;
}

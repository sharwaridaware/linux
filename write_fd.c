#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, len;
	int x;
	char write_buf[50]="hi, are you1?, wow?";


	fd = open("linux_kernel1.txt",O_CREAT|O_RDWR,777);

	write(fd, write_buf,60); 

	printf(" return value =%d\n",len);

	close(fd);
	return 0;
}

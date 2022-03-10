#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, len;
	char write_buf[50]="hi, are you1?, wow?";
	char read_buf[50];

	fd = open("linux_kernel1.txt",O_CREAT|O_RDWR,777);

	len = write(fd, write_buf,50); //50 return, curr file off mved 50th loctn

	printf(" return value from write optn=%d\n",len);
	//close(fd1);

	lseek(fd,4,SEEK_SET); //rewind current file offset to (0 loctn) start point in file "linux_kernel.txt"
		
	// int whence .....arg

	//fd2 = open("5s10.txt",O_CREAT|O_RDWR,777);

	read(fd,read_buf,len);

	printf("data from buffer(read optn) = %s\n", read_buf);
	//print({"%d\n",len);

	close(fd);
	
	return 0;
}


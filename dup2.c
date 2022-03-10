#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fp1,fp2,fp3;

	char buf[200];
	fp1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC, 0777);
	fp2=open("P22.c",O_WRONLY|O_CREAT|O_TRUNC, 0777);
	printf("FD of FP1=%d\n",fp1);
	printf("FD of FP2=%d\n",fp2);

	fp2=dup(fp1,4);
	
	printf("f21 is our defined dup of FP1=%d\n",fp1);

	close(fp3);
	close(fp2);
	close(fp1);
}

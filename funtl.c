#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fp1,fp2,fp3;

	fp1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC, 0777);


	fp2=dup(fp1);
	printf("Value of fp2 is %d\n", fp2);

	fp3=dup2(fp1,4);	
	printf("duplicate value of fp1 is %d\n", fp3);

	int close(int fp3);
	int close(int fp1);
}

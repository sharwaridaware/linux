#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff_comm[5];
	strcpy( buff_comm, "ls -l");
	int n;

	printf(" system() library function uses fork() to create a child process\n");
	printf(" child process executes execl() which loads and run new program provided by system() argumentts\n");
	
	n= system(NULL);
	return(0);
}

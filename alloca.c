#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *name = (char *) alloca (10);

	strcpy(name, "linux");
	
	printf("the copied string data is=%s\n",name);

	return 0;
	}
	

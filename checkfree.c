#include<stdio.h>
#include<stdlib.h>
extern  int EF_PROTECT_BELOW=1;

void buggy()
{
	int *intptr;
	intptr = (int *)malloc(sizeof(int));
	
	* intptr = 100;
	printf("value at ptr intptr = %d\n",(*intptr));
	free(intptr);
	*intptr = 99;

}

int main()
{
	buggy();
	return 0;
}

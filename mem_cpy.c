#include<stdio.h>
#include<string.h>

int main()
{
	const char str1[10] = "linuxnew";
	const char str2[10];
	int ret;
	
	mymemcopy(str1,str2,10);
	
	printf("string in str2=%s\n",str2);

	return 0;
}

void mymemcopy(char *src, char *dest, int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		*dest=*src;
		dest++;
		src++;
	}
}

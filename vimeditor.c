#include<stdio.h>
#include<unistd.h>

int main()
{
	int ret;
	ret = execl("/usr/bin/vim","vim","info1.txt",0);
	if (ret == -1)
	printf("execl return error%d\n", ret);
}


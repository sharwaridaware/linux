#include<stdio.h>
#include<unistd.h>

int main(void)
{
printf("current process\n");
fork();
fork();
fork();

printf("LINUX process22\n");
printf("LINUX process33\n");

while(1);
return 0;
}

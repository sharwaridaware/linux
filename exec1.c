#include<stdio.h>
#include<unistd.h>


int main(void)
{
printf("I am going to execute an 'ls' program\n");

execl("/bin/ls","ls","-lh", NULL);

printf("i executed ls program");
printf("i executed ls program");
printf("i executed ls program");
}


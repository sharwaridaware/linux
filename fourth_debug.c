#include<stdio.h>
#include<string.h>
struct A
{
	int roll;
	char name[40],gender;
	float height;
};

int main()
{
	struct A first;
	printf("\n size of struct A %3d\n", sizeof(first));
}

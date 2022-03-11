#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

main()
{
printf("Can you see me [ONE]\n");
execl("/home/user/Documents/GUNI/Linux_Integrals_course/day3_day4/4process/live_process_demo/exectest","./exectest","linux","kernel","programming","device","drivers",NULL);
printf("Can you see me [TWO]\n");
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

#define KEY (1492)

void main()
{
int id;

union semun{
int val;
struct semid_ds *buf;
unsigned short *array;
} argument;

argument.val = 1;
id = semget(KEY, 1, 0666 | IPC_CREAT);

if(id < 0)
{
fprintf(stderr,"Unable to obtain semaphore.\n");
}

if(semctl(id,0,SETVAL,argument) < 0)
{
fprintf(stderr,"Cannot set semaphore value.\n");
}
else
{
fprintf(stderr,"Semaphore %d initialized.\n",KEY);
}
}


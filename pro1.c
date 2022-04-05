#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

int get_semaphore(void);
int release_semaphore(void);
int sem_id;
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};
struct sembuf sem_op;
union semun sem_union;

int main()
{
	int i,j;
	sem_id=semget((key_t)1234,1,0666|IPC_CREAT);
	
	for(i=0;i<=10;i++) {
			get_semaphore();
			printf("\nSEM2:%d: got the semaphore\n",getpid()); 
			for(j=0;j<=3;j++)
			{
			sleep(1);
			printf("\a");
			}

	printf("\nSEM2%d :released the semaphore\n",getpid());
			release_semaphore();
			sleep(2);
}

if(semctl(sem_id,0,IPC_RMID,sem_union)<0)
		printf("Unable delete semaphore\n");
		else
		printf("semaforce deleted\n");
}

int get_semaphore(void)
	{
	sem_op.sem_num = 0;
	sem_op.sem_op = -1;
	sem_op.sem_flg = SEM_UNDO;

	if(semop(sem_id,&sem_op,1)<0){
	printf("failed to get the semaphore\n");
	return -1;
	}
	return 0;
}


int release_semaphore(void) {
			sem_op.sem_num = 0;
			sem_op.sem_op = 1;
			sem_op.sem_flg = SEM_UNDO;

		
			if(semop(sem_id,&sem_op,1)<0) {
			printf("failed to release semaphore\n");
			return -1;
			}
		return 0;
		}


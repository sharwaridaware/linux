#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>

main(){
	int shmid;
	struct shmid_ds buf;
	shmid = shmget(48,250,IPC_CREAT|0644);
	printf("qid = %d\n", shmid);
	shmctl(shmid,IPC_RMID,NULL);
}

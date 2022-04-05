#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(){
	int qid;
	struct msqid_ds buf;
	qid = msgget(49,IPC_CREAT|0644);
	printf("qid = %d\n", qid);
	msgctl(qid,IPC_RMID,NULL);
}

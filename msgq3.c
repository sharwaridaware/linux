#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main(){
	int qid;
	struct msqid_ds buf;
	qid = msgget(32,IPC_CREAT|0644);
	printf("qid = %d/n", qid);
	msgctl(qid,IPC_STAT,&buf);
	printf("Here are the details of the queue\n");
	printf("no of msg's in q %hi\n", buf.msg_qnum);
	printf("max no of bytes in q %hi\n", buf.msg_qbytes);
	return 0;
}

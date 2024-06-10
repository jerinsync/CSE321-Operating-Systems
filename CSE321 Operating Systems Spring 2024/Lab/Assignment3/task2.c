#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h> 
#include <sys/shm.h>


struct msg{
long int type;
char txt[100];
};

int main(){
	printf("Please enter the workspace name (lowercase):\n");
	char input[100];
	scanf("%s", input);
	if (strcmp(input, "cse321") != 0){
		printf("Invalid workspace name\n");
	}
	else{
		int msg_id, snt;
		struct msg s_data;
		struct msg login;
		//queue access
		msg_id=msgget((key_t)12, 0666|IPC_CREAT);
		//struct update
		s_data.type = 2;
		strcpy(s_data.txt, input);
		//send to queue
		snt=msgsnd(msg_id,(void *)&s_data,sizeof(s_data.txt),0);
		if(snt==-1){
			printf("Error msgsnd\n");
		}
		printf("Workspace name sent to otp generator from log in: %s\n",s_data.txt);
		
		//fork child otp
		pid_t otp;
		otp = fork();
		if(otp<0){
			perror("fork");
		}

		else if(otp==0){
			struct msg r_data; 
			int cmsg_id;
			msg_id = msgget((key_t)12,0666|IPC_CREAT); //queue access
			if(msgrcv(msg_id,(void *)&r_data,sizeof(r_data.txt), 2, IPC_NOWAIT)<0) {
				perror("Error msgrcv");
			}
			printf("OTP generator received workspace name from log in: %s\n", r_data.txt);
			
			
			//child process otp write/send pid
			pid_t pid = getpid();
			char store[50];
			int csnt;
			struct msg child_write;
			msg_id = msgget((key_t)12, 0666|IPC_CREAT);//queue access
			child_write.type = 5; //different type for mail process
			sprintf(store, "%d", pid);
			strcpy(child_write.txt, store);
			//printf("OTP generator received workspace name from log in: %s\n", store);
			
			//login sent
			int lsnt;
			s_data.type = 8; //different type for login from otp process
			strcpy(s_data.txt, store);
			lsnt = msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt),0);
			printf("OTP sent to log in from OTP generator: %s\n",s_data.txt);
			//msg send
			csnt = msgsnd(msg_id, (void *)&child_write, sizeof(child_write.txt),0);
			printf("OTP sent to mail from OTP generator: %s\n",child_write.txt);
			
			//mail process
			pid_t mail;
			mail = fork();
			if(mail==0){
				struct msg mailr; 
				int msg_id;
				msg_id = msgget((key_t)12,0666|IPC_CREAT);//queue access
				if (msg_id==-1){
					printf("Error msg_id\n");
				}
				if(msgrcv(msg_id,(void *)&mailr, sizeof(mailr.txt), 5, IPC_NOWAIT)<0){
					perror("Error msgrcv");
				}
				printf("Mail received OTP from OTP generator: %s\n", mailr.txt);
				//login sent
				int lsnt;
				//mmsg_id = msgget((key_t)12, 0666|IPC_CREAT);
				s_data.type = 9;//different type for login from mail process
				strcpy(s_data.txt, store);
				lsnt = msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt),0);
				printf("OTP sent to log in from mail: %s\n",s_data.txt);
				//shmctl(mmsg_id,IPC_RMID, NULL);
				
			}
			else{
				int status1;
				wait(&status1);
				//shmctl(cmsg_id,IPC_RMID, NULL);
				}

		}
		else{
			int status;
			wait(&status);
			//otp
			if(msgrcv(msg_id,&s_data ,sizeof(s_data), 8,IPC_NOWAIT)<0) {
				perror("msgrcv");
			}
			printf("Log in received OTP from OTP generator: %s\n",s_data.txt);
			char rotp[50];
			strcpy(rotp, s_data.txt);
			
			//mail
			if(msgrcv(msg_id,&s_data ,sizeof(s_data), 9 ,IPC_NOWAIT)<0){
				perror("msgrcv");
			}
			printf("Log in received OTP from mail: %s\n",s_data.txt);
			char rmail[50];
			strcpy(rmail, s_data.txt);
			
			//compare
			if (strcmp(rotp, rmail) == 0){
			    printf("OTP Verified\n");
			} 
			else{
			    printf("OTP Incorrect\n");
			    }	
			
			
		   }
		   shmctl(msg_id,IPC_RMID, NULL);
	
	}
	
	return 0;
}

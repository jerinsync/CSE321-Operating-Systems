#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    pid_t pid, pid1;
    pid = fork();
    if (pid == 0){
        pid1 = fork();
        if(pid1==0){
        printf("I am grandchild\n");
        exit(0);
        }
        else{
            int status1;
            wait(&status1);
           printf("I am child\n");
           exit(0);
        }
    }
    else{
        int status;
        wait(&status);
        printf("I am parent\n");
    }
    return 0;
}
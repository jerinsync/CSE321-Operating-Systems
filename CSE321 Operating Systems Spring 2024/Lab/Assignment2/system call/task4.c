#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
char *sortarr[argc];
char *oddevenarr[argc];
int s=0;
for (int i=1;i<argc;i++){
   sortarr[s] = argv[i];
   s++;
}
sortarr[s] = NULL;
int e=0;
for (int i = 1; i < argc; i++) {
   oddevenarr[e] = argv[i];
   e++;
}
oddevenarr[e] = NULL;

pid_t pid;
pid=fork();
if (pid == 0){
    printf("Child...\n");
    execv("./sort", sortarr);
}

else{
   int status;
   wait(&status);
   printf("\nParent...\n");
   execv("./oddeven", oddevenarr);
}

}
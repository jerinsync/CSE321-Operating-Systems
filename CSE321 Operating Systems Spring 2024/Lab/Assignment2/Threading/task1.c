#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *funcThread(void *arg);
int num = 0;
int main(){
    pthread_t t1[5];
    for (int i = 0 ; i < 5 ; i++){
        pthread_create(&t1[i],NULL,funcThread,NULL);
        pthread_join(t1[i],NULL);
    }
    return 0;
}

void *funcThread(void *arg){
    num++;
    printf("thread-%d running\n",num);
    sleep(0.5);
    printf("thread-%d closed\n",num);
}
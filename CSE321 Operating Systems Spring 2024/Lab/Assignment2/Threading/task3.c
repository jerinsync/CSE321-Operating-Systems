#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int result;
void *asciiAdd(void *arg);
int main() {
    int value[3];
    pthread_t t1[3];
    for (int i= 0; i<3;i++) {
        pthread_create(&t1[i], NULL, asciiAdd, NULL);
        pthread_join(t1[i], NULL);
        value[i] = result;
    }
   
    int count = 1;
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            if(value[i] == value[j])
            {
                count++;
                break;
            }
        }
    }
    if (count == 3){
    printf("Youreka\n");
    }
    else if (count == 2){
    printf("Miracle\n");
    }
    else{
    printf("Hasta la vista\n");
    }
   
    return 0;
   
}


void *asciiAdd(void *arg) {
    char name[50];
    int sum = 0;
    printf("Enter name:\n");
    scanf("%s", name);
    int j;
    for (j=0;name[j]!='\0';j++) {
        sum=sum+name[j];
    }
    result = sum;
    printf("sum: %d\n", result);
}
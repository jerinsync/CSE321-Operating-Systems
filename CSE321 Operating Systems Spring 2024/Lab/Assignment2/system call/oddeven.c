#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){
    int odd[100];
    int even[100];
    int e = 0;
    int o = 0;
    for (int i=1;i<argc;i++){
        int num=atoi(argv[i]);
        if (num%2==0){
            even[e]=num;
            e++;
        }
        else{
            odd[o]=num;
            o++;
        }
    }

    printf("\nEven numbers: ");
    for (int i=0; i< e; i++){
        printf("%d ", even[i]);
    }

    printf("\nOdd numbers:");
    for (int i=0; i < o; i++){
        printf("%d ", odd[i]);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    int store[argc-1];
    int c=0;
    int temp;
    for (int i=1;i<argc;i++){
        int num=atoi(argv[i]);
        store[c] = num;
        c++;
    }
    for (int i= 0; i<c;i++){    
        for (int j =i+1; j < c; j++){  
           if(store[i]<store[j]){    
               temp = store[i];    
               store[i] = store[j];    
               store[j] = temp;    
               }
        }    
    }    
    printf("\nSorted order: ");
    for (int i=0; i<c;i++){
        printf("%d ", store[i]);
         }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char* check(char *mail){

    int length = strlen(mail);
    int i,index;
    for (i=0; i<length; i++){
        if (mail[i] == '@'){
            index=i;
            break;
        }
    }

    index++;
    char s1[10]="";
    char s2[10];
    int remain = length - index;
    for (index; index < length; index++) {
        sprintf(s2, "%c", mail[index]);
        strcat(s1, s2);
    }

    if (strcmp(s1, "sheba.xyz") == 0){
        return "Email address is okay";
    }
    else {
        return "Email address is outdated";
    }
}


int main(){
    char mail[100];
	printf("Enter email address:\n");
	scanf("%s", mail);
    char* result = check(mail);
    printf("%s\n", result);
	
}
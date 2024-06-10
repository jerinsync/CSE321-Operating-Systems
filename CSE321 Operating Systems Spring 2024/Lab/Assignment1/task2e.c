#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char str[100];
    gets(str);
    int left = 0;
    int right = strlen(str) - 1;
    int c = 0;
    while (right > left){
        for (left = 0; left < strlen(str); left++){
            if (str[left] != str[right]){
                c++;
            }
            right--;
        }
    }
    if (c == 0){
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
}
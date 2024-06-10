#include <stdio.h>
#include <string.h>
#include <stdbool.h>



int main ()
{
    FILE *input;
    FILE *output;

    input = fopen("task2b.txt", "r");
    output= fopen("output2b.txt" , "w");

    char str[100];
    fgets(str, 100, input);
    int c=0;
    size_t length = strlen(str);
    char stringarr[length];

    for (size_t i = 0; i < length; i++)
    {
        if (!(str[i] == ' ' && str[i+1] == ' ')){
            stringarr[c] = str[i];
            c++;
        }
        
    }
    int j;
    char result[100]="";
    for (j = 0; j < strlen(stringarr); j++){
        strncat(result, &stringarr[j], 1);
    }

    fputs(stringarr, output);

    fclose(input);
    fclose(output);

  }
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int file;
    char *name;
    if (argc == 1){
    name = "task1.txt";
    }
    else{
        name = argv[1];
    }
    printf("%d\n",argc);
    file = open(name, O_RDWR | O_CREAT, 0644);
    while(1){
        char string[100];
        printf("Enter string: ");
        fgets(string, sizeof(string), stdin);
        if (strcmp(string, "-1\n") == 0){
            break;
        }
        else {
            write(file, string, strlen(string));
        }
    }

    close(file);
    return 0;
}
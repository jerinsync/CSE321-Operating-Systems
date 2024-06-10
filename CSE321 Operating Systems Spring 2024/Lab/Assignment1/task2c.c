#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(){

	char password[100];
	int lowercase=0;
    int uppercase=0;
    int digit=0; 
    int scharacter=0;
    int i,c;
    char output[4];
	printf("Enter USIS password:\n");
	scanf("%s",password);
	int length = strlen(password);
	for (i=0; i < length; i++){
        if (islower(password[i])){
			lowercase = 1;
		}
		else if (isupper(password[i])){
			uppercase = 1;
		}
		else if (islower(password[i])){
			lowercase = 1;
		}
		else if (isdigit(password[i])){
			digit = 1;
		}
		else if (password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
		    scharacter = 1;
		}
	}

    int total = lowercase + uppercase + digit + scharacter;
    int missing = 4-total;
    c = missing;

    if (missing == 0){
        printf("OK\n");
    }

    else if (missing == 1){
		if (lowercase == 0){
			printf("Lowercase character missing\n");
		}
		if (uppercase == 0){
			printf("Uppercase character missing\n");
		}
		if (digit == 0){
			printf("Digit missing\n");
		}
		if (scharacter == 0){
			printf("Special character missing\n");
		}
    }


    else if (missing > 1){
        if (lowercase == 0){
            printf("Lowercase character missing");
            c--;
            if (c>=1){
                printf(", ");
            }
        }
        if (uppercase == 0){
            printf("Uppercase character missing");
            c--;
            if (c>=1){
                printf(", ");
            }
        }
        if (digit == 0){
            printf("Digit missing");
            c--;
            if (c>=1){
                printf(", ");
            }
        }
        if (scharacter == 0){
            printf("Special character missing");
            c--;
            if (c>=1){
                printf(", ");
            }
        }
    }

}


#include<stdio.h>
#include<stdlib.h>
int main() {
      int n1, n2;
      printf("Enter the starting number: ");
      scanf("%d", &n1);
      printf("Enter the ending number: ");
      scanf("%d",&n2);
      int i = n1;
      for (i; i <= n2; i++){
         int sum = 0;
         for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                  sum += j;
            }
         }
         if (sum > 0 && sum == i){
            printf("%d\n", i);
         }
      }

      return 0;
}
#include<stdio.h>
#include<stdlib.h>

int subtraction(int a, int b){
   int res;
   res = a - b;
   return res;
}

int addition(int a, int b){
   int res;
   res = a + b;
   return res;
}

int multiplication(int a, int b){
   int res;
   res = a * b;
   return res;
}


int main(){

   int n1,n2,r;
   printf("First numerical input:\n");
   scanf("%d", &n1);
   printf("Second numerical input:\n");
   scanf("%d", &n2);

   if (n1>n2){
      r = subtraction(n1,n2);
      printf("Result: %d\n", r);
   }

   else if (n1<n2){
      r = addition(n1,n2);
      printf("Result: %d\n", r);
   }

   else if (n1=n2){
      r = multiplication(n1,n2);
      printf("Result: %d\n", r);
   }
}


#include <stdio.h>
#include <stdlib.h>

struct breakfast{
   float quantity;
   float unit_price;
};

int main(){
   struct breakfast p;
   struct breakfast v;
   struct breakfast m;
   int c;
   float res;
   printf("Quantity of Paratha: ");
   scanf("%f",&p.quantity);

   printf("Unit Price: ");
   scanf("%f",&p.unit_price);

   printf("Quantity of Vegetables: ");
   scanf("%f",&v.quantity);

   printf("Unit Price: ");
   scanf("%f",&v.unit_price);

   printf("Quantity of Mineral Water: ");
   scanf("%f",&m.quantity);

   printf("Unit Price: ");
   scanf("%f",&m.unit_price);
   
   printf("Number of People: ");
   scanf("%d",&c);
   
   res = ((p.quantity * p.unit_price) +(v.quantity * v.unit_price)+(m.quantity *m.unit_price)) /c;
   printf("Individual people will pay: %.2f tk\n",res);


}
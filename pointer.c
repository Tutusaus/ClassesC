#include <stdio.h>

/* function definition to swap the values */
void swap(int *x, int *y) {

   int temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
  
   return;
}

int main () {

   int  var1;
   char var2[10];

   printf("Address of var1 variable: %x\n", &var1);
   printf("Address of var2 variable: %x\n", &var2);

   //------------------------------------------------------------------
   printf("-------------------------------------------------------\n");
   //------------------------------------------------------------------

   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n",&var);

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n",ip);

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n",*ip);

   //------------------------------------------------------------------
   printf("-------------------------------------------------------\n");
   //------------------------------------------------------------------

   int  *ptr = NULL;

   printf("The value of ptr is : %x\n", ptr  );

   //------------------------------------------------------------------
   printf("-------------------------------------------------------\n");
   //------------------------------------------------------------------
   
    /* local variable definition */
   int a = 100;
   int b = 200;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
 
   /* calling a function to swap the values */
   swap(&a, &b);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );

   //------------------------------------------------------------------
   printf("-------------------------------------------------------\n");
   //------------------------------------------------------------------

   return 0;
}
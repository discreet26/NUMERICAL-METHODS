#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
 
void main() {
 
   //Create 2D array for backward difference table
   double y[20][20], x[20];
   int i, j, k, num;
 
   //Accept inputs from the user
   printf("\nBackwad differences generation for Interpolation");
   printf("\n\nEnter the value of x and y = f(x)");
   scanf("%d", &num);
 
   for (i = 0; i < num; i++) {
      printf("\nEnter value of x%d : ", i);
      scanf("%lf", &x[i]);
      printf("\nEnter value of y%d : ", i);
      scanf("%lf", &y[i][0]);
   }
 
   //Loop is used to calculate backward difference
   k = 0;
   for (j = 1; j < num; j++) {
      k++;
      for (i = num - 1; i >= k; i--) {
         y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
      }
   }
 
   k = num;
   printf("\nBackward Difference Table\n");
   printf("\n\tx\ty\tDy\tD2y\tD3y\tD4y\tD5y\tD6y\n");
 
   for (i = 0; i < num; i++) {
      printf("\nx%d    = %4.2lf", i, x[i]);
      for (j = 0; j < i + 1; j++) {
         printf("\t%4.2lf ", y[i][j]);
      }
      printf("\n");
   }
}
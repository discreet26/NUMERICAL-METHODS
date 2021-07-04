#include<stdio.h>
#include<conio.h>

int main()
{
 float x[20], y[20][20];
 int i,j, n;
 
 /* Input Section */
 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++)
 {
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }

 /* Generating Backward Difference Table */
 for(i = 1; i < n; i++)
 {
  for(j = n-1; j > i-1; j--)
  {
   y[j][i] = y[j][i-1] - y[j-1][i-1];
  }
 }

 /* Displaying Backward Difference Table */
 printf("\nBACKWARD DIFFERENCE TABLE\n\n");
 for(i = 0; i < n; i++)
 {
  printf("%0.2f", x[i]);
  for(j = 0; j <= i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }

 getch(); /* Holding Screen */
 return 0;
}
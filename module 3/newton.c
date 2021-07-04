#include<stdio.h>
#include<conio.h>


int main()
{
 printf("Forward Difference Interpolation\n\n");
 float x[12], y[12][12],x1[12];
 int i,j, n;float f,h,d,s,p;
 printf("Enter number of data : ");
 scanf("%d", &n);
 printf("Enter data:-\n");
 for(i = 1; i <= n ; i++)
 {
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }

 for(i = 1; i <= n; i++)
 {
  for(j = 1; j <= n-i; j++)
  {
   y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }

 printf("\nFORWARD DIFFERENCE TABLE\n\n");
 printf("x\ty");
 for(i=1;i<n;i++,printf("\t%c^%d",30,i-1));
 printf("\n\n");
 for(i = 1; i <= n; i++)
 {
  printf("%0.2f", x[i]);
  for(j = 0; j <= n-i ; j++)
  {
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }

  h=x[2]-x[1];
  printf("\nEnter the value of x for which f(x) needed :");
  scanf("%f",&f);
  s=(f-x[1])/h;
  p=1;
  d=y[1][0];
  for(i=1;i<=(n-1);i++)
 {
                   for(j=1;j<=(n-i);j++)
                    {
                          y[j][0]=y[j+1][0]-y[j][0];

                    }
                    p=p*(s-i+1)/i;
                    d=d+p*y[1][0];
 }
printf("\nFor the value of x=%6.5f, f(%6.5f) = %6.5f\n",f,f,d);

}
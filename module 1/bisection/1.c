#include <stdio.h>
#include <conio.h>
#include <math.h>
int f(float x)
{
return x*x*x+x*x+x+7;
}
void main()
{
float x0,x1,x2;
float f1,err;
int i=0;
clrscr();
one:
printf("enter the values of x0 and x1 and acceptable error\n");
scanf("%f %f %f",&x0,&x1,&err);
if(f(x0)*f(x1)>0)
{
printf("the entered values of x0 and x1 will not give root value\n");
goto one;
}
do
{
x2=(x0+x1)/2;
if(f(x0)*f(x1)<0)
x1=x2;
else
x0=x2;
i++;
printf("number of iterations=%d",i);
printf("root=%f",x2);
printf("value of function=%f\n",f(x2));
}while(fabs(x1-x0)>err);
getch();
}
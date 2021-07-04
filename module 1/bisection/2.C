#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
#define e 0.001 
#define f(x) x*x*x+x-1; 
void main() 
{
int i=0; 
float x0,x1,x2,a,b,c,j; 
for (j=0; ; j++) 
{ 
x0 = j; 
x1 = j+1; 
a=f(x0); 
b=f(x1); 
if (a*b < 0) 
{ 
break; 
} 
} 
printf("initial value of x0= %f\n",x0); 
printf("initial value of x1= %f\n",x1); 
do 
{ 
a=f(x0); 
b=f(x1); 
x2=(x0+x1)/2; 
c=f(x2); 
if(a*c<0) 
{
x1=x2; 
} 
else 
{
x0=x2; 
}
i++; 
printf("number of iteration=%d\t",i); 
printf("roots=%f\t",x2); 
printf("value of function=%f\n",c); 
} while(fabs(c)>e); 
printf("total number of iteration=%d\n",i); 
printf("final root=%f\n",x2); 
printf("final value of function=%f\n",c); 
getch(); 
}
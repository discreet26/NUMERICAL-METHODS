#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,k,n;
float a[20][20],c,x[10];

printf("\n enter the size of matrix:");
scanf("%d",&n);
printf("\n enter the elements of augmented matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=(n+1);j++)
{
printf("a[%d][%d]:",i,j);
scanf("%f",&a[i][j]);
}
}
for(j=1;j<=n;j++)
{
for(i=1;i<=n;i++)
{
if(i!=j)
{
c=a[i][j]/a[j][j];
for(k=1;k<=n+1;k++)
{
a[i][k]=a[i][k]-c*a[j][k];
}
}
}
printf("\n the solution is :\n");
for(i=1;i<=n;i++)
{
x[i]=a[i][n+1]/a[i][i];
printf("\n x%d=%f\n",i,x[i]);
}
}
getch();
}

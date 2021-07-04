#include<stdio.h>
#include<math.h>

/* In this example we are solving
   3x + y + 10 z = -10
    x - y + z = -20
   15x  -y - z = 20
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   15x  -y - z = 20
    x + 10y -z = -10
    x - y + z = -20
*/
/* Equations:
   x = (20+ y + z)/15
   y = (-10- x + z)/10
   z = (-20- x + y)/1
*/

#define f1(x,y,z)  (23 - 5y - 10z)/3
#define f2(x,y,z)  (23 - x - 20z)/1
#define f3(x,y,z)  (27- 10x - 5y)/7

int main()
{
 float x0,y0,z0,x1, y1, z1, e1, e2, e3, e;
 int count=1;
 printf("***************************************************Gauss Siedel Method**************************************************\n\nGiven system of equations are :-\n15x - y - z = 20\nx + 10y -z = -10\nx - y + z = -20\n");


 printf("\n\nEnter tolerable error:\n");
 scanf("%f", &e);
 printf("Enter initial values for x0, y0 and z0 :-\n");
 scanf("%f",&x0);
 scanf("%f",&y0);
 scanf("%f",&z0);


 printf("\nIteration\t x\t          y\t         z\n");
 do
 {
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t    %0.4f\t    %0.4f\t    %0.4f\n",count, x1,y1,z1);

  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.4f, y=%0.4f and z = %0.4f\n",x1,y1,z1);

 getch();
 return 0;
}

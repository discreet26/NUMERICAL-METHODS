#include <stdio.h>
#include <math.h>
#define e 0.0001
double func(double x)
{
    return cosx - pow(e,-x);
}
void bisection(double a, double b){
    int i=0;
    if (func(a) * func(b) >= 0)
    {
        printf("You have not assumed right value of a and b\n");
    }
    double c = a;
    while ((b - a) >= e){

            c = (a + b) / 2;

            if (func(c) == 0.0)
                break;

            else if (func(c) * func(a) < 0)
                b = c;
            else
                a = c;
        i++;
        printf("no. of iteration=%d",i);
        printf("root=%lf",c);
        printf("value of functin=%lf\n",func(c));
        
    }
}    

void main()
{
    double x0, x1;
    printf("Enter value of x0,x1\n");
    scanf("%lf", &x0);
    scanf("%lf", &x1);
    bisection(x0,x1);   
}


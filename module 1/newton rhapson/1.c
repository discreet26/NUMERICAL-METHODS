/*
Title - Newton Raphson Method
Author - Vivek Nigam (IMH/100006/17)
Lab - Numerical Methods Lab - 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-4

double func (double x)
{
    return (x*x - 10);
}

double derfunc (double x)
{
    return (2*x);
}

int main()
{
    double x,x1;
    x1=10.0;
    int itr=1;
    printf("\nInitial Guess: %lf\n", x1);
    
    printf("\n x \t\t x1 \t\t f'(x) \t\t |x-x1|\n", x,x1);
    
    do
    {
        x=x1;
        printf("\n %lf \t %lf \t %lf \t %lf\n", x,x1, derfunc(x) ,(x-x1));
        
        if (fabs(derfunc(x))>=10e-8 && derfunc(x) != NAN)
        {
            x1 = x - func(x)/derfunc(x);
            itr++;
        }
        else
        {
            printf("Method Fails");
            return 0;
        }
    }while (fabs(x-x1) >= TOL);
    
    printf("\nRoot = %f\n", x1);
    printf("Number of Iterations = %d", itr);
}

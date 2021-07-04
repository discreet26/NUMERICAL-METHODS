#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) log10(x)

void simpsonsRule (){
    double a, b, h, ifx = 0.0, i;
    int n;
    printf("Enter the lower and upper limits of the integral: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("Enter the number of subintervals you want: ");
    scanf("%d", &n);
    h = fabs(b - a) / n;
    ifx = ifx + f(a) + f(b);
    for (i = a+h; i < b;){
        ifx = ifx + (4 * f(i));
        i = i + (2*h);
    }
    for (i = a+(2*h); i < b;){
        ifx = ifx + (2 * f(i));
        i = i + (2*h);
    }
    ifx = ifx * h / 3;
    printf("\nThe integral of the equation using Simpson's 1/3rd Rule is %lf\n", ifx);
}

int main (){
    simpsonsRule();
}
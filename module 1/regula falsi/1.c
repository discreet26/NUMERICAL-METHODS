
#include <iostream> 
#include<math.h>
#define func(x) x*x*x - x*x + 2

void regulaFalsi(double a, double b)

{

if (func(a) * func(b) >= 0)

{

cout <<"the initial values are wrong "<<endl; return;
}



double c = a;



for (int i=0; i < 20; i++)

{



c = (a*func(b) - b*func(a))/ (func(b) - func(a));



if (func(c)==0) break;


else if (func(c)*func(a) < 0)

b = c; else
cout<<”the roots are:”<<c<<endl;

a = c;

}

cout << "The approximated value of root is : " << c;

}



int main()

{



double a =1, b =-2; regulaFalsi(a, b); return 0;
}


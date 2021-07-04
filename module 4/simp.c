#include<stdio.h>
#include<math.h>

float f(float x){
	return exp(x);
	/*
	return sqrt(1 - 0.162 * sin(x) * sin(x));
	*/
}

int main(){
	
	float a,b,n,h,sum1=0,sum2=0,sum,y0,yn;
	int i;
	
	printf("Enter the upper limit : ");
	scanf("%f",&b);
	printf("Enter the lower limit : ");
	scanf("%f",&a);
	printf("Enter the number of intervals : ");
	scanf("%f",&n);
	
	//step length
	h=(b-a)/n;
	
	y0=f(a+0*h);
	yn=f(a+n*h);
	
	for(i=1; i<n; i++)
		if(i%2 == 0)
			sum1 = sum1 + f(a+i*h);
		else
			sum2 = sum2 + f(a+i*h);
	
	sum =(h/3)*(y0 + yn + 2*sum1 +4*sum2);
	
	printf("INTEGRAL : %.2f",sum);
	
	getch();
	return 0;
}
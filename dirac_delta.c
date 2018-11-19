#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double approx_delta(double x, double epsilon){
    double y, pi = 3.1415926;
    y = epsilon/((x*x+epsilon*epsilon)*pi);
    return (y);
}

void Simpson(double a, double b, double* I, double epsilon){
    int i, se = 1;
    double x,
    h, /* The step size */
    step_num = 20; /* The total step number */
    /*printf("Please Choose The Version of The Function\n"); scanf("%d", &se);*/
    
    h = (b - a)/step_num;
    x = a;
    
    for (i = 0; i < step_num; i++){
        *I = *I + (h/6)*(approx_delta(x, epsilon)+ approx_delta(x + h, epsilon) + 4*approx_delta(x+h/2, epsilon));
        x = x +h;
    }
    
}

int main(void){
    double a = -0.5, b = 0.5,
    epsilon, I;
    int i, funcnum = 3;
    
    for (i = 1; i <= 1000; i++){
        epsilon = i/1000.0;
        Simpson(a, b, &I, epsilon);
        printf("%lf     %lf\n", epsilon, I);
        I = 0;
    }
    return (0);
}

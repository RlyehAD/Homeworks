#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double approx_delta(double x, double y, double e_p){
    double pi = 3.1415926;
    y = e_p/((x*x+e_p*e_p)*pi);
    /*printf("%lf\n", e_p);*/
    return (y);
}

void RK45(double* x, double* y, double h, double* epsilon, double inser_e){
    /* Now input the necessary parameters */
    double c20 = 0.25, c21 = 0.25,
           c30 = 0.375, c31 = 0.09375, c32 = 0.28125,
           c40 = 12.0/13.0, c41 = 1932.0/2197.0, c42 = -7200.0/2197.0, c43 = 7296.0/2197.0,
           c51 = 439.0/216.0, c52 = -8.0, c53 = 439.0/216.0, c54 = -845.0/4104.0,
           c60 = 0.5, c61 = -8.0/27.0, c62 = 2.0, c63 = -3544.0/2565.0, c64 = 1859.0/4104.0, c65 = -0.275,
           a1 = 25.0/216.0, a2 = 0.0, a3 = 1408.0/2565.0, a4 = 2197.0/4104.0, a5 = -0.2,
           b1 = 16.0/135.0, b2 = 0.0, b3 = 6656.0/12825.0, b4 = 28561.0/56430.0, b5 = -0.18, b6 = 2.0/55.0;
    double K1, K2, K3, K4, K5, K6, Y4, e_p = inser_e;
    int k;
    
    K1 = h * approx_delta(*x, *y, e_p);
    K2 = h * approx_delta(*x + c20*h, *y + c21*K1, e_p);
    K3 = h * approx_delta(*x + c30*h, *y + c31*K1 + c32*K2, e_p);
    K4 = h * approx_delta(*x + c40*h, *y + c41*K1 + c42*K2 + c43*K3, e_p);
    K5 = h * approx_delta(*x + h, *y + c51*K1 + c52*K2 + c53*K3 + c54*K4, e_p);
    K6 = h * approx_delta(*x + c60*h, *y + c61*K1 + c62*K2 + c63*K3 + c64*K4 + c65*K5, e_p);
    
    Y4 = *y + a1*K1 + a3*K3 + a4*K4 +a5*K5;
    *y += b1*K1 + b3*K3 + b4*K4 + b5*K5 + b6*K6;
    *x += h;
    *epsilon = fabs(*y - Y4);
}


void adrk45(double inser_e){
    double x, y, h, b = 0.5, d, tempx, tempy, delta = 0.000001, epsilon;
    int max_step_num = 500, stop_s = 1, i = 0, k;
    
        x = -0.5;
        y = 0.0;
        h = 0.001;
        while (i <= max_step_num) {
            i++;
            d = fabs(b - x); /* The distance betweent the present point and the final point */
            if (d <= h){
                stop_s = 0;
                h = d;
            }
            tempx = x; tempy = y;
            RK45(&x, &y, h, &epsilon, inser_e);
            if (stop_s == 0){
                break;
            }
            if (fabs(epsilon) > delta){
                x = tempx; y = tempy; /* Go back */
                h *= 0.5;
                i--;
            }
            if (fabs(epsilon) < delta/128.0){
                h *= 2;
            }
        }
            printf("%lf   %lf\n", inser_e, y);
}

int main(void){
    double inser_e; /* inser_e here is the epsilon in the approximated function */
    for (int k = 1; k <= 1000; k++){
    inser_e = k/1000.0;
    adrk45(inser_e);
    }
    return(0);
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "homework3.h"

int main(void){
    double a, b, I, pi = 3.1415926;
    int choose_func, funcnum;
    time_t start, end;
    
    printf("Please choose the integration to be computed. (Input 1, 2 or 3)\n");
    scanf("%d", &choose_func);
    
    switch (choose_func) {
        case 1:
            printf("This integration is implemented by Gaussian-Hermite Method\n");
            funcnum = 0;
            start = time(NULL);
            G_H(&I, funcnum);
            end = time(NULL);
            I = I/sqrt(pi);
            printf("The result is %lf\n", I);
            printf("duration: %lf\n", difftime(end, start));
            break;
        
        case 2:
            printf("This integration is implemented by Gaussian-Laguerre Method\n");
            funcnum = 1;
            I = 0;
            start = time(NULL);
            G_Laguerre(&I, funcnum);
            end = time(NULL);
            printf("The result is %lf\n", I);
            printf("duration: %lf\n", difftime(end, start));
            break;
            
        case 3:
            printf("This integration is implemented by Gaussian-Laguerre Method\n");
            funcnum = 2;
            I = 0;
            start = time(NULL);
            G_Laguerre(&I, funcnum);
            end = time(NULL);
            printf("The result is %lf\n", I);
            printf("duration: %lf\n", difftime(end, start));
            break;
    }
    return(0);
}


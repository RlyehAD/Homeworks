#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "homework3.h"

int main(void){
    double a, b, I[20], pi = 3.1415926;
    int k, choose_func, funcnum;
    time_t start, end;
    
    printf("Please choose the integration to be computed. (Input 1, 2 or 3)\n");
    scanf("%d", &choose_func);

    switch (choose_func) {
        case 1:
            funcnum = 0;
            a = 0.0; b = 0.0;
            for (k = 1; k <= 20; k++){
                a = -k*0.5; b = k*0.5;
                start = time(NULL);
                Simpson(a, b, &I[k], funcnum);
                I[k] = I[k]/sqrt(pi);
                end = time(NULL);
                printf("duration: %lf\n", difftime(end, start));
                printf("%d    %lf\n", k, I[k]);
            }
            break;
        
        case 2:
            funcnum = 1;
            a = 0.0; b = 0.0;
            for (k = 1; k <= 20; k++){
                b = k;
                start = time(NULL);
                Simpson(a, b, &I[k], funcnum);
                end = time(NULL);
                printf("duration: %lf\n", difftime(end, start));
                printf("%d    %lf\n", k, I[k]);
            }
            break;
            
        case 3:
            funcnum = 2;
            a = 0.0; b = 0.0;
            for (k = 1; k <= 20; k++){
                b = k;
                start = time(NULL);
                Simpson(a, b, &I[k], funcnum);
                end = time(NULL);
                printf("duration: %lf\n", difftime(end, start));
                printf("%d    %lf\n", k, I[k]);
            }
    }
    return(0);
}

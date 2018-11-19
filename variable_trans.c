#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "homework3.h"

int main(void){
    double I[3], /* Used to record the results for 3 functions */
           temp,
           pi = 3.1415926;
    double a, b;

    int n, /* Governs the number of added points */
        choose_func,
        funcnum; /* Choose the function */
    printf("Please input the number of integration. (Input 1, 2 or 3)\n");
    scanf("%d", &choose_func);
    
    switch (choose_func) {
        case 1:
    /* solve the first integration */
    a = -1.0/3.0;
    b = 0;
    funcnum = 0;
    /*printf("%lf\n", a);*/
    for (n = 0; n < 2; n++){
         midpin(a, b, &I[0], n, funcnum);
         /*printf("%lf\n", I[0]);*/
    }
    temp = 2.0*I[0];
    I[0] = 0;
    /*printf("%lf\n", temp);*/
    
    printf("Now enter the phase of the integration for -3~3, please always choose fucntion version 1\n");
    a = -3.0;
    b = 3.0;
    for (n = 0; n < 5; n++){
         midpin(a, b, &I[0], n, funcnum);
    }
    temp = temp + I[0];
    /*I[0] = 0;*/
    printf("The -3~3 phase is over\n");
    
   /* a = 0;
    b = 1.0/3.0;
    n = 2;
    midpin(a, b, &I[0], n, funcnum);*/
    I[0] = temp/sqrt(pi);
    
    printf("The integration result for function %d is %lf\n", funcnum, I[0]);
            break;
    
        case 2:
    /* Solve the second integration */
    a = 0;
    b = 6.0;
    funcnum = 1;
    printf("Now enter the phase of the integration for 0~6, please always choose fucntion version 1\n");
    for (n = 0; n < 5; n++){
        midpin(a, b, &I[1], n, funcnum);
    }
    temp = I[1];
    
    a = 0;
    b = 1.0/6.0;
    printf("Now enter the phase of the integration for 6~infinity, please always choose fucntion version 2\n");
    for (n = 0; n < 2; n++){
        midpin(a, b, &I[1], n, funcnum);
    }
    I[1] = I[1] + temp;
    printf("The integration result for function %d is %lf\n", funcnum, I[1]);
            break;
            
        case 3:
    a = 0;
    b = 5;
    funcnum = 2;
    printf("Now enter the phase of the integration for 0~5, please always choose fucntion version 1\n");
    for (n = 0; n < 5; n++){
        midpin(a, b, &I[2], n, funcnum);
    }
    temp = I[2];
    
    a = 0;
    b = 1.0/5.0;
    printf("Now enter the phase of the integration for 5~infinity, please always choose fucntion version 2\n");
    for (n = 0; n < 2; n++){
        midpin(a, b, &I[2], n, funcnum);
    }
    I[2] = I[2] + temp;
    printf("The integration result for function %d is %lf\n", funcnum, I[2]);
  }
    
    return (0);
}

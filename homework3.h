/* This is the .h file for the integration homework
   All the functions used in the main program are coded 
   here. */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



/* This is the function used to compute the value
of exp(-x*x)dx; When se (selection) = 1,
the value of the function for the original x is computed; when se = 2,
the value of the function for the transformed-variable is computed. */

double func1(double x, int se){
	double y;
    /*printf("%lf\n", x);*/
	if (se == 1){
		y = exp(-x*x);
	}
	if (se == 2){
		x = 1/x;
		y = x*x*exp(-x*x);
	}

	return (y);
}

double func2(double x, int se){
    double y;
    if (se == 1){
        y = exp(-x);
    }
    if (se == 2){
        x = 1/x;
        y = x*x*exp(-x);
    }
    return (y);
}

double func3(double x, int se){
    double y;
    if (se == 1){
        y = exp(-x)*cos(x);
    }
    if (se == 2){
        x = 1/x;
        y = x*x*exp(-x)*cos(x);
    }
    return (y);
}

/* This is a function to implement midpoint method*/
void midpin(double a, double b, double* I, int n, int funcnum)
/* a and b are limits; I is the value of integration. n is 
the sequential order*/
{
   int pre_ste_num, /* The step number of the last sequential order */
	   mid_p_num = 1, /* The number of points added / 2 */
	   se, /* Used to choose the original function or the transformed one */
	   k, i;
   double x, y, add, h_tot, temp,
          h_1, /* The stepsize */
          h_2; /* The stepsize *2 (used to jump over the existing points) */
   
  /* printf("Please Choose The Function\n"); scanf("%d", &funcnum);*//* !!!!!!!!!!!!!!!!!!!!!!!!!!! */
   printf("Please Choose The Version of The Function\n"); scanf("%d", &se);
   double (*funk[3])(double, int) = {&func1, &func2, &func3};
   
   h_tot = b - a;

   if (n == 0){
       temp = (a+b)/2;
       /*printf("%lf  %lf  %lf", temp, *a, *b);*/
   	*I = h_tot*(funk[funcnum](temp, se));
   } else {
   	 /* for (mid_p_num = 1, k = 1; k < n; k++) mid_p_num *= 3;  mid_p_num actually is 
   	 equal to 3^(n-1) */
   	 /*mid_p_num = pow(3, n-1); (3^(n - 1))*/
     mid_p_num = 1;
       for (i = 0; i < n-1; i++){
           mid_p_num = mid_p_num*3;
       }
     pre_ste_num = 3 * mid_p_num; /* Compute the step number for this sequential order 3^n */
     h_1 = h_tot/pre_ste_num;
     h_2 = h_1 + h_1;
     x = a + 0.5*h_1;
     add = 0;
     for (k = 0; k < mid_p_num; k++){
          /*add = add + funk[funcnum](x, se);*/
          temp = funk[funcnum](x, se);
          add = add + temp;
          x = x+h_2;
          /*add = add + funk[funcnum](x, se);*/
          temp = funk[funcnum](x, se);
          add = add + temp;
          x = x+h_1;
                }
     *I = (*I/3) + (h_1*add);             
          }
   }


void Simpson(double a, double b, double* I, int funcnum){
	int i, se = 1;
	double x,
	       h, /* The step size */
	       step_num = 20; /* The total step number */
	double (*funk[3])(double, int) = {func1, func2, func3};
    /*printf("Please Choose The Version of The Function\n"); scanf("%d", &se);*/

	h = (b - a)/step_num;
	x = a;

	for (i = 0; i < step_num; i++){
		*I = *I + (h/6)*(funk[funcnum](x, se) + funk[funcnum](x + h, se) + 4*funk[funcnum](x+h/2, se));
		x = x +h;
	}

}

void G_Legendre(double* I, int N, int funcnum){
	int i, se;
	double w[6], r[6];
	FILE *read_w_r;
	read_w_r = fopen("GL6.txt", "r");
	double (*funk[3])(double, int) = {func1, func2, func3};
    printf("Please Choose The Version of The Function\n"); scanf("%d", &se);	
    
    /* Input the weights and the roots */
	for (i = 0; i < 6; i++){
		fscanf(read_w_r, "%lf  %lf\n", &w[i],&r[i]);
	}
    
    for (i = 0; i < 6; i++){
    	*I = *I + w[i]*funk[funcnum](r[i], se);
    }
    fclose(read_w_r);
}

void G_Laguerre(double *I, int funcnum){
    int i, se = 1;
    double w[5], r[5];
    FILE *read_r_w;
    read_r_w = fopen("GLagu5.txt", "r");
    double (*funk[3])(double, int) = {func1, func2, func3};
    /*printf("Please Choose The Version of The Function\n"); scanf("%d", &se);*/
   
    /* Input the roots and the weights */
    for (i = 0; i < 5; i++){
    	fscanf(read_r_w, "%lf  %lf\n", &r[i], &w[i]);
    }
    
    for (i = 0; i < 5; i++){
        *I = *I + w[i]*exp(r[i])*funk[funcnum](r[i], se); /* The weight fuction is exp(-x), therefore mutiply by exp(x) */
    }
    fclose(read_r_w);
}

void G_H(double *I, int funcnum){
	int i, se = 1;
    double w[5], r[5];
    FILE *read_r_w;
    read_r_w = fopen("G_HER5.txt", "r");
    double (*funk[3])(double, int) = {func1, func2, func3};
    /*printf("Please Choose The Version of The Function\n"); scanf("%d", &se);*/
    
    /* Input the roots and the weights */
    for (i = 0; i < 5; i++){
        fscanf(read_r_w, "%lf  %lf\n", &r[i], &w[i]);
    }
    for (i = 0; i < 5; i++){
        *I = *I + w[i]*exp(r[i]*r[i])*funk[funcnum](r[i], se);
    }
    fclose(read_r_w);
}



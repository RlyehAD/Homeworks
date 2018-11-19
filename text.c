#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	FILE *readtest;
	readtest = fopen("test.txt","r");
	double w[6], c[6];
	int i;
    
    for (i = 0; i<2; i++){
	fscanf(readtest, "%lf  %lf\n", &w[i],&c[i]);
    }

    for (i = 0; i<2; i++){
    	printf("%lf %lf\n",w[i], c[i]);
    }
    return(0);
}

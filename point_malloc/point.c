#include <stdio.h>
#include <stdlib.h>


#define NUM_PUNTOS 4
struct punto_t{
	double x;
	double y;
};

struct punto_t centroide(struct punto_t * v, int size){
	struct punto_t pres;
	double x_med=0; double y_med=0; int p;
	for(p=0; p<size; p++){
		x_med+=v[p].x;
		y_med+=v[p].y;
	}

	pres.x=x_med/NUM_PUNTOS;
	pres.y=y_med/NUM_PUNTOS;
	return pres;
}

int main(void){
	//***allocate memory resources for a list of NUM_PUNTOS 2D points

	struct punto_t pres;
	int p=0;	
	int x=0; int y=0;
	
	for(p=0; p<NUM_PUNTOS; p++){
		printf("Introduzca las coordenadas X Y del punto\n");
		scanf("%d %d", &x, &y);
		pv[p].x=x; pv[p].y=y;
	}

	pres=centroide(pv, NUM_PUNTOS);
	printf("(%.3f, %.3f)\n",pres.x, pres.y);

	//***free memory resources appropiately
	return 0;
}



////////////////////////////
// Repaso C: programa para calcular el centroide de una nube de puntos
// fecha de creacion: 7/2/2014
// fecha de ultima actualizacion: 5/2/15


#include <stdio.h>
#include <stdlib.h>


#define NUM_PUNTOS 4
#define SIZE_OF_LINE 255
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
};


void imprime(struct punto_t p){
	printf("(%.3f, %.3f)", p.x, p.y);
}



int read_file(char* filename, struct punto_t * v, int size){
	char line [SIZE_OF_LINE];
	double x; double y;
	int index=0;

	//***

	return 0;
}


int main(void){
	struct punto_t v_puntos[NUM_PUNTOS];  
	struct punto_t pres;
	int p; 


	//***read file	


	pres=centroide(v_puntos, NUM_PUNTOS);
	imprime(pres);
	return 0;
}



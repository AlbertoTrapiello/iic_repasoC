//reads formatted matrix protocol: d <num_rows> <num_columns>, r <col[0]> <col[1]>, ... 
//date: 10/02/2015

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_LINE 250

void print_matrix(int ** matriz, int n, int m){
	int i, j;
	//***
}

void free_matrix(int n, int m, int ** matrix){
	int i;
	//***
}

int** read_matrix(const char* filename, int* n, int* m){
	int i, row=0;
	int **matrix=NULL;
	char line[SIZE_OF_LINE], token; 

	FILE * f=fopen(filename,"r");
	if( f==NULL) {
		puts("error when opening file");
		return 0;
	}

	while(!feof(f)){
		//protocol (extracts headers)
		fscanf(f, "%c",&token);

		//protocol using swith-case
		switch(token){
		//***
		default:
			perror("unrecognized protocol");
			return NULL;
		}

	}
	return matrix;
}


void main(){
//client application
	int n, m;
	int ** matrix=read_matrix("matriz.txt", &n, &m);
	
	print_matrix(matrix, n, m);
	free_matrix(n, m, matrix);
}
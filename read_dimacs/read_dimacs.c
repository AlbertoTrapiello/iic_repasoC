//////////////////////////////////////
// Example of how to read simple undirected graphs in DIMACS (Discrete Mathematics Association) format
// date of creation: 22/2/16
// last update: 22/2/16
// author: pss

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define SIZE_OF_LINE	250
#define FILENAME		"mygraph.txt"		//"brock200_1.clq"

typedef unsigned char BYTE;

void print_matrix(BYTE ** matrix, int n){
	int i; int j;
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%d ",matrix[i][j]);
		}
	}
	printf("\n");
}

void free_matrix(int n, BYTE ** matrix){
	int i;
	if(matrix!=NULL){
		for(i=0; i<n; i++){
			free(matrix[i]);
		}
		free(matrix);
		matrix=NULL;
	}
}

BYTE** allocate_matrix(int n){
	int i; int j;
	BYTE** matrix= (BYTE**) malloc(sizeof(BYTE*)*n);
	for(i=0; i<n; i++){
		matrix[i]=(BYTE*) malloc (sizeof(BYTE)* n);
	}
	//reset values
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrix[i][j]=0;
		}
	}
	return matrix;
}

BYTE** read_matrix(const char* filename, int* n, int* edges){
	int v1=-1; int v2=-1; int counter=0;  BYTE **matrix=NULL;
	char line[SIZE_OF_LINE]; char token; char token2[SIZE_OF_LINE];
	FILE* f;
	n=0; edges=0;

	
	//open file
	//***

	while(!feof(f)){
		//protocol (extracts headers)
		if(fscanf(f, "%c",&token)!=1){
			puts("unrecognized protocol");
			return 0;
		}	

		switch(token){
		case 'c':	//comment
			//***
			break;
		case 'p':  //reads vertices and edges
			fgets(line, SIZE_OF_LINE, f);
			//***


			break;
		case 'e': //reads edge			
			fgets(line, SIZE_OF_LINE, f);
			if(sscanf(line, "%d %d",&v1, &v2)!=2){
				puts("error when reading dimension");
				return 0;
			}
			//write bidirectional edge
			//**

			counter++;
			if(counter==*edges){
				//all edges are read
				return matrix;
			}

			break;
		default:
			puts("incorrect DIMACS protocol");
			if(matrix){
				free_matrix(*n, matrix);
				matrix=NULL;
				return matrix;
			}
		}
	}

return matrix;
}

int num_edges(BYTE **matrix, int n){
	int res=0;
	int i; int j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(matrix[i][j]==1)
				res++;
		}
	}
return res;
}

int main(){
	int n=0; int edges=0;
	BYTE** matrix=read_matrix(FILENAME, &n, &edges);
	printf("v: %d e: %d expected_e: %d\n", n, num_edges(matrix, n), edges);

	//shows matrix in screen
	print_matrix(matrix, n);

	free_matrix(n,matrix);
return 0;			//OK
}
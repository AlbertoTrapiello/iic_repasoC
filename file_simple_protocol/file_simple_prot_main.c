///////////////////
// reads simple formatted file protocol: c-comment, n <size of data>, d <data>
// date: 10/02/2015
// last update: 9/2/2016

#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_LINE 250

int* read_file(char* filename, int* nData){
	int* vres=NULL; 
	char line[SIZE_OF_LINE], token;
	int data=0, counter=0;

	//** open file stream "fichero.txt"


	//typical loop for reading line sequentially 
	while(!feof(f)){
		//reads line and checks the state of the stream
		fgets(line, SIZE_OF_LINE, f);
		if(ferror(f)){
			perror("error when reading line");
			return NULL;
		}
		
		//file protocol with switch-case
		sscanf(line, "%c", &token);
		//***
		
	}
	
	//error check
	if(counter!=*nData){
		printf("to read: %d read %d", nData, counter);
		puts("data read inconsistent with n value");
	}

	fclose(f);
return vres;
}


void print_data(int* vdata, int size){
//***
}

int main(void){
//client application
	int nDataRead=0, i=0;
	int* vdata=read_file("fichero.txt", &nDataRead);

	//show data in screen
	print_data(vdata, nDataRead);

	//*** free memory
	
return 0;
}

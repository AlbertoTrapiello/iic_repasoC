//simple file managing techniques in C
//date of creation: 11/2/2016
//last update: 11/2/2016


#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_LINE 255

int main (void){
	char token;
	char line[SIZE_OF_LINE];
	int dato;
	char res[SIZE_OF_LINE];

	FILE* f= fopen("datos.txt", "r");
	FILE* fres= fopen("log.txt", "w+");
	if(f==NULL){
		perror("file not found");
		return -1;
	}

	//read protocol
	while(!feof(f)){
		if(fgets(line,SIZE_OF_LINE,f)==NULL) break;
		if(ferror(f)){
			perror("file not found");
			return -1;
		}

		//protocol
		sscanf(line, "%c", &token);
		if(token=='c') continue;
		if(token=='d') {
			//read number
			//puts(line);
			sscanf(line, "%c %d", &token, &dato);
			printf("el dato es: %d\n", dato);
			sprintf(res,"el dato es: %d\n", dato);

			//log the data to log.txt file
			fputs(res,fres);
			break;
		}
		//puts(line);
	}

	//free resources
	fclose(f);
	fclose(fres);

return 0;
}
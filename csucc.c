#include <stdio.h>

void csucc_readValue(char succFile[32], char valueName[32], void *var) { //csucc_readValue opens succFile and writes the value to *var 
	FILE * fp;

	fp = fopen(succFile, "r");
	if (fp == NULL) {
		perror("File can't be opened");
		return; 
	}
	
	int c;
	char n = valueName[0];
	char tempValue[256];
	while (1==1) {
		c = fgetc(fp);
		if (c == n) {
			
		} else {
			if (c == ":") {
				
				//get value and put it into tempValue, check for line end.

			}
			n = valueName[0]
		}

		if (feof(fp)) { break; }
	}
}

void csucc_writeValue(char succFile[32], char valueName[32], void *var) { //csucc_writeValue writes *var to the valueName
	
}

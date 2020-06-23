#include <stdio.h>

void csucc_readValue(char succFile[32], char valueName[32], void *var) { //csucc_readValue opens succFile and writes the value to *var 
	FILE * fp;

	fp = fopen(succFile, "r");
	if (fp == NULL) {
		perror("File can't be opened");
		return; 
	}
	
	//this needs cleanup.
	int c;
	int found = 0;
	char n = 0;
	char tempValue[256];
	while (1==1) { //check characters in succFile to see if they match valueName.
		c = fgetc(fp);
		if (c == valueName[n]) {
			found = 1;
			n++;
		} else {
			if (c == ":" &&	found == 1) { //get value and put it into tempValue, check for line end.
				printf("bryh");
				int i;
				fgetc(fp);
				while(c != "\n" || feof(fp)) {
					tempValue[i] = c;
					i++;
					c = fgetc(fp);
					printf("%c", c);
				}
				break;
			} else {
				found = 0;
				n = 0;
			}
		}

		if (feof(fp)) { break; }
	}

	if (found == 1) {
		//put value into var
	} else {
		perror("Value not found");
		return;
	}	
}

void csucc_writeValue(char succFile[32], char valueName[32], void *var) { //csucc_writeValue writes *var to the valueName
	
}

int main(void) {
	int war = 322;
	csucc_readValue("test.succ", "name", war);
	return 0;
}

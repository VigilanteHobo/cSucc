#include <stdio.h>
#include <string.h>

void csucc_readValue(char succFile[32], char valueName[32], void *var) { //csucc_readValue opens succFile and writes the value to *var 
	FILE * fp;

	fp = fopen(succFile, "r");
	if (fp == NULL) {
		perror("File can't be opened");
		fclose(fp);
		return; 
	}

	char temp[255];
	
	while (!feof(fp)) { //Search file
		fgets(temp, 255, fp);
		if (strstr(temp, valueName) != NULL) { //Match found
			if (strstr(temp, ":") != NULL) { //Read value and place into var
				char *colon = strstr(temp, ":");
				//char *location = colon - temp;
				
				char var = sscanf(colon, "%s");
				printf("%s\n", var);
				
				fclose(fp);
				return;
			} else { //Check next line for "-"
				
			}
		}
	}

	fclose(fp);
	return;
}

void csucc_writeValue(char succFile[32], char valueName[32], void *var) { //csucc_writeValue writes *var to the valueName
	
}

int main(void) { //testing
	char war[64] = "bruh";
	csucc_readValue("test.succ", "name", war);
	//printf("%s\n", war);
	return 0;
}

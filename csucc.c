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
				char *location = colon - temp; //Use this pointer to get the colon location in temp table
				
				int i = location+1;
				int type = 1; //0 NULL 1 Integer 2 Float 3 String
				int isArray = 0;
				while (temp[i] != "\n") {
					if (temp[i] == "(" || temp[i] == ")") isArray = 1;
					if (temp[i] == '"' || temp[i] == "'") type = 3;
					if (temp[i] == "." && type != 3) type = 2; //I don't know if this is a good way, should work for now.
					if (temp[i] == 0 && i == location) { type = 0; var = NULL; return; }
				}

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

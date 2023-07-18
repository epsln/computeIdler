#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "include/config.h"
#include "include/readFiles.h"

const char* getfield(char* line, int num){
	const char* tok;
	for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n")){
		if (!--num)
			return tok;
	}

	return NULL;
}

void writeCheckpoint(params_t* params, u_int32_t* histogram){
	FILE* stream = fopen(params->checkpoint_filename, "w");
	for (int i = 0; i < params->resx; i++){
		for (int j = 0; j < params->resy; j++){
			fprintf(stream, "%u,",histogram[i * params->resy + j] );
		}
		fprintf(stream, "\n");
	}
	fclose(stream);
}

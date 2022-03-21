#include"logger.h"
#include<string.h>
static FILE* f;


void openLogger(char name[]) {
f = fopen(name, "w");
fprintf(f, "Fichero log\n----------------------------------\nDeustoMarket\n");
fprintf(stderr, "Fichero log\n----------------------------------\nDeustoMarket\n");
}

int closeLogger() {
	fprintf(f, "\n\nFINAL DEL ARCHIVO");
	return fclose(f);
}

void logFile(LEVEL l, char desc[]) {
	if (l == INFO) {
		char buffer[100];
		strcat(strcpy(buffer, "\n[INFO]   "), desc);
		fprintf(f, buffer);
		fprintf(stderr, buffer);
	} else if (l == WARN) {
		char buffer[100];
		strcat(strcpy(buffer, "\n[WARN]   "), desc);
		fprintf(f, buffer);
		fprintf(stderr, buffer);
	} else if (l == ERROR) {
		char buffer[100];
		strcat(strcpy(buffer, "\n[ERROR]   "), desc);
		fprintf(f, buffer);
		fprintf(stderr, buffer);
	}
}

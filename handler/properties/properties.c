#include "properties.h"
#include "../logger/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void createProperties(Properties *properties, char name[]) {
	FILE *f = fopen(name, "w");

	for (int i = 0; i < properties->numProp; i++) {
		fprintf(f, "-%s\n", properties->propName[i]); //NOMBRE DE LA PROPIEDAD
		fprintf(f, "%s\n", properties->propValue[i]); //VALOR DE LA PROPIEDAD
	}
	logFile(INFO, "Fichero de configuración creado");
	fclose(f);

}

void allocate(Properties *prop, char name[]) {
	FILE *f = fopen(name, "r");

	char buffer[MAX];
	char** nombres = malloc(sizeof(char*) * prop->numProp);
	char** valores = malloc(sizeof(char*) * prop->numProp);
	int props = prop->numProp;
	int posEnValue = 0;
	int posEnName = 0;
	while (fgets(buffer, MAX, f) != NULL) {
		strtok(buffer, "\n");
		if (buffer[0] == '-') {
			if (posEnName < props) {
				buffer[0] = ' ';
				nombres[posEnName] = malloc(sizeof(char)*MAX);
				strcpy(nombres[posEnName], buffer);
				posEnName++;
			}
		} else if (buffer[0] != '-') {
			if (posEnValue < props) {
				valores[posEnValue] = malloc(sizeof(char)*MAX);
				strcpy(valores[posEnValue], buffer);
				posEnValue++;
			}
		}
	}

	prop->propName = nombres;
	prop->propValue = valores;
	logFile(INFO, "Propiedades cragadas con éxito");
	fclose(f);

}

void loadProperties(Properties *properties, char name[]) {
	FILE *f = fopen(name, "r");

	properties->numProp = 0;

	char buffer[MAX];
	while (fgets(buffer, MAX, f)) {
		strtok(buffer, "\n");
		if (buffer[0] == '-') {
			properties->numProp++;
		}
	}

	fclose(f);

	allocate(properties, name);


}

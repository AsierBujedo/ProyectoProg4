/*
 * methods.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker L�pez
 */

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "../handler/DBH.h"

void showStatistics() {
	char strAux[2];

	printf("\n------------\n");
	printf("ESTAD�STICAS\n");
	printf("------------\n\n");

	printf("\n�Estad�sticas mostradas! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void showSupermarkets() {
	char sql[100];
	char strAux[2];

	printf("\n-------------------------------\n");
	printf("LISTA COMPLETA DE SUPERMERCADOS\n");
	printf("-------------------------------\n\n");

	printf("\n�Lista completa de supermercados mostrada! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void showProducts() {
	char sql[100];
	char strAux[2];

	printf("\n---------------------------\n");
	printf("LISTA COMPLETA DE PRODUCTOS\n");
	printf("---------------------------\n\n");

	printf("\n�Lista completa de productos mostrada! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void addSupermarket() {
	char sql[100];

	char str1[26];
	char str2[36];
	char str3[10];
	char str4[6];
	char strAux[2];

	printf("\n-------------------\n");
	printf("A�ADIR SUPERMERCADO\n");
	printf("-------------------\n\n");

	printf("Introduzca el nombre: ");
	fflush(stdout);
	fgets(str1, 26, stdin);
	fflush(stdin);
//	strcat(sql, str1);
//	Supermercado1 --> 'Supermercado1'

	printf("\nIntroduzca la direcci�n: ");
	fflush(stdout);
	fgets(str2, 36, stdin);
	fflush(stdin);

	printf("\nIntroduzca el tel�fono: ");
	fflush(stdout);
	fgets(str3, 10, stdin);
	fflush(stdin);

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str4, 6, stdin);
	fflush(stdin);

//	executeStatement(sql, db);

	printf("\n�Supermercado a�adido con �xito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}
void deleteSupermarket() {
	char sql[100];

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR
}

void modSupermarket() {
	char sql[100];

	printf("\n----------------------\n");
	printf("MODIFICAR SUPERMERCADO\n");
	printf("----------------------\n\n");

	// FALTA CODIFICAR
}

void addProduct() {
	char sql[100];

	printf("\n---------------\n");
	printf("A�ADIR PRODUCTO\n");
	printf("---------------\n\n");

	// FALTA CODIFICAR
}

void deleteProduct() {
	char sql[100];

	printf("\n-------------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR
}

void modProduct() {


	printf("\n------------------\n");
	printf("MODIFICAR PRODUCTO\n");
	printf("------------------\n\n");

	// FALTA CODIFICAR
}


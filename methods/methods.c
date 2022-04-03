/*
 * methods.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker López
 */

#include "methods.h"

void showStatistics(sqlite3 *db) {
	char strAux[2];

	printf("\n------------\n");
	printf("ESTADÍSTICAS\n");
	printf("------------\n\n");

	printf("\n¡Estadísticas mostradas! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void showSupermarkets(sqlite3 *db) {
	char sql[100];
	char strAux[2];

	printf("\n-------------------------------\n");
	printf("LISTA COMPLETA DE SUPERMERCADOS\n");
	printf("-------------------------------\n\n");

	printf("\n¡Lista completa de supermercados mostrada! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void showProducts(sqlite3 *db) {
	char sql[100];
	char strAux[2];

	printf("\n---------------------------\n");
	printf("LISTA COMPLETA DE PRODUCTOS\n");
	printf("---------------------------\n\n");

	printf("\n¡Lista completa de productos mostrada! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);

	// FALTA CODIFICAR
}

void addSupermarket(sqlite3 *db) {
	char sql[100];

	char str1[26];
	char str2[36];
	char str3[10];
	char str4[6];
	char strAux[2];

	printf("\n-------------------\n");
	printf("AÑADIR SUPERMERCADO\n");
	printf("-------------------\n\n");

	printf("Introduzca el nombre: ");
	fflush(stdout);
	fgets(str1, 26, stdin);
	fflush(stdin);
//	strcat(sql, str1);
//	Supermercado1 --> 'Supermercado1'

	printf("\nIntroduzca la dirección: ");
	fflush(stdout);
	fgets(str2, 36, stdin);
	fflush(stdin);

	printf("\nIntroduzca el teléfono: ");
	fflush(stdout);
	fgets(str3, 10, stdin);
	fflush(stdin);

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str4, 6, stdin);
	fflush(stdin);

//	executeStatement(sql, db);

	printf("\n¡Supermercado añadido con éxito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}
void deleteSupermarket(sqlite3 *db) {
	char sql[100];

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR
}

void modSupermarket(sqlite3 *db) {
	char sql[100];

	printf("\n----------------------\n");
	printf("MODIFICAR SUPERMERCADO\n");
	printf("----------------------\n\n");

	// FALTA CODIFICAR
}

void addProduct(sqlite3 *db) {
	char sql[100];

	printf("\n---------------\n");
	printf("AÑADIR PRODUCTO\n");
	printf("---------------\n\n");

	// FALTA CODIFICAR
}

void deleteProduct(sqlite3 *db) {
	char sql[100];

	printf("\n-------------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR
}

void modProduct(sqlite3 *db) {


	printf("\n------------------\n");
	printf("MODIFICAR PRODUCTO\n");
	printf("------------------\n\n");

	// FALTA CODIFICAR
}


/*
 * methods.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker L�pez
 */

#include "functions.h"
#include "../handler/DBH.h"
#include "../handler/logger/logger.h"
#include <stdlib.h>
#include <stdio.h>

void showStatistics() {
	char strAux[2];

	printf("\n------------\n");
	printf("ESTAD�STICAS\n");
	printf("------------\n\n");

	// FALTA CODIFICAR

	logFile(INFO, "Estad�sticas mostradas");

	printf("\n�Estad�sticas mostradas! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void showSupermarkets() {
	char sql[100];

	char strAux[2];

	printf("\n-------------------------------\n");
	printf("LISTA COMPLETA DE SUPERMERCADOS\n");
	printf("-------------------------------\n\n");

	// FALTA CODIFICAR

//	executeQuery(sql);

	logFile(INFO, "Lista completa de supermercados mostrada");

	printf("\n�Lista completa de supermercados mostrada! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void showProducts() {
	char sql[100];

	char strAux[2];

	printf("\n---------------------------\n");
	printf("LISTA COMPLETA DE PRODUCTOS\n");
	printf("---------------------------\n\n");

	// FALTA CODIFICAR

//	executeQuery(sql);

	logFile(INFO, "Lista completa de productos mostrada");

	printf("\n�Lista completa de productos mostrada! Pulse ENTER para volver al men� principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
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

// FALTA CODIFICAR

	printf("\nIntroduzca la direcci�n: ");
	fflush(stdout);
	fgets(str2, 36, stdin);
	fflush(stdin);

	// FALTA CODIFICAR

	printf("\nIntroduzca el tel�fono: ");
	fflush(stdout);
	fgets(str3, 10, stdin);
	fflush(stdin);

	// FALTA CODIFICAR

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str4, 6, stdin);
	fflush(stdin);

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Supermercado a�adido");

	printf("\n�Supermercado a�adido con �xito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}
void deleteSupermarket() {
	char sql[100];

	char strAux[2];

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Supermercado eliminado");

	printf("\n�Supermercado eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateSupermarket() {
	char sql[100];

	char strAux[2];

	printf("\n----------------------\n");
	printf("ACTUALIZAR SUPERMERCADO\n");
	printf("----------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Supermercado actualizado");

	printf("\n�Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void addProduct() {
	char sql[100];

	char strAux[2];

	printf("\n---------------\n");
	printf("A�ADIR PRODUCTO\n");
	printf("---------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Producto a�adido");

	printf("\n�Producto a�adido con �xito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteProduct() {
	char sql[100];

	char strAux[2];

	printf("\n-------------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Producto eliminado");

	printf("\n�Producto eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateProduct() {
	char sql[100];

	char strAux[2];

	printf("\n------------------\n");
	printf("ACTUALIZAR PRODUCTO\n");
	printf("------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Producto actualizado");

	printf("\n�Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}


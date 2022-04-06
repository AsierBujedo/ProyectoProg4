/*
 * methods.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker López
 */

#include "functions.h"
#include "../handler/DBH.h"
#include "../handler/logger/logger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINE 40

void showStatistics() {
	char strAux[2];

	printf("\n------------\n");
	printf("ESTADÍSTICAS\n");
	printf("------------\n\n");

	// FALTA CODIFICAR

	logFile(INFO, "Estadísticas mostradas");

	printf(
			"\n¡Estadísticas mostradas! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void showSupermarkets() {
	char *sql = "SELECT * FROM SUPERMERCADO;";
	//int result;
	char strAux[2];

	printf("\n-------------------------------\n");
	printf("LISTA COMPLETA DE SUPERMERCADOS\n");
	printf("-------------------------------\n\n");

	Data datos = executeQuery(sql);

	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i\t", sqlite3_column_int(datos.stmt, 0));
		printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 2));
		printf("%i\t", sqlite3_column_int(datos.stmt, 3));
		printf("%f\n", sqlite3_column_double(datos.stmt, 4));
	}

//	do {
//		result = sqlite3_step(datos.stmt);
//		if (result == SQLITE_ROW) {
//			printf("%i\t", sqlite3_column_int(datos.stmt, 0));
//			printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 1));
//			printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 2));
//			printf("%i\t", sqlite3_column_int(datos.stmt, 3));
//			printf("%f\n", sqlite3_column_double(datos.stmt, 4));
//		}
//
//	} while (result == SQLITE_ROW);

	printf("\n");

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de supermercados mostrada");

	printf(
			"\n¡Lista completa de supermercados mostrada! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void showProducts() {
	char *sql = "SELECT * FROM PRODUCTO;";
//	int result;
	char strAux[2];

	printf("\n---------------------------\n");
	printf("LISTA COMPLETA DE PRODUCTOS\n");
	printf("---------------------------\n\n");

	Data datos = executeQuery(sql);

	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i\t", sqlite3_column_int(datos.stmt, 0));
		printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%f\t", sqlite3_column_double(datos.stmt, 2));
		printf("%s\n", (char*) sqlite3_column_text(datos.stmt, 3));
	}

//	do {
//		result = sqlite3_step(datos.stmt);
//		if (result == SQLITE_ROW) {
//			printf("%i\t", sqlite3_column_int(datos.stmt, 0));
//			printf("%s\t", (char*) sqlite3_column_text(datos.stmt, 1));
//			printf("%f\t", sqlite3_column_double(datos.stmt, 2));
//			printf("%s\n", (char*) sqlite3_column_text(datos.stmt, 3));
//		}
//
//	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de productos mostrada");

	printf(
			"\n¡Lista completa de productos mostrada! Pulse ENTER para volver al menú principal: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void addSupermarket() {
	Supermercado supermercado; // Estructura creada por Asier (#include ...)
	supermercado.loadingCode = 1;

	char *sql = "INSERT INTO SUPERMERCADO VALUES (?, ?, ?, ?, ?, ?);";
	sqlite3_stmt * stmt;

	char str[MAX_LINE];
	char str1[MAX_LINE];
	char str2[MAX_LINE];
	char strAux[2];
	int cod_s;
	int tlf_s;
	float metros_cuad_s;
	int cod_ciu;

	printf("\n-------------------\n");
	printf("AÑADIR SUPERMERCADO\n");
	printf("-------------------\n\n");

	printf("Introduzca el códgio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);
	supermercado.cod_s = cod_s;

	printf("Introduzca el nombre: ");
	fflush(stdout);
	fgets(str1, MAX_LINE, stdin);
	fflush(stdin);
	supermercado.nom_s = str1;

	printf("\nIntroduzca la dirección: ");
	fflush(stdout);
	fgets(str2, MAX_LINE, stdin);
	fflush(stdin);
	supermercado.dir_s = str2;

	printf("\nIntroduzca el teléfono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	supermercado.tlf_s = tlf_s;

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &metros_cuad_s);
	supermercado.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el código de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	supermercado.cod_ciu = cod_ciu;

	printf(supermercado.nom_s);
	printf("\n");
	printf(supermercado.dir_s);

	addSupermarketDB(sql, &supermercado);


	printf("\n¡Supermercado añadido con éxito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}
void deleteSupermarket() {
	char *sql = "DELETE FROM SUPERMERCADO WHERE COD_S = ?;";
	char strAux[2];

	showSupermarkets(); // Mostramos la lista completa de supermercados

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Supermercado eliminado");

	printf(
			"\n¡Supermercado eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateSupermarket() {
	Supermercado supermercado; // Estructura creada por Asier (#include ...)

	char *sql =
			"UPDATE SUPERMERCADO SET ? = ?, ? = ?, ? = ?, ? = ?, ? = ?, ? = ? WHERE COD_S = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int cod_s;
	int tlf_s;
	float metros_cuad_s;
	int cod_ciu;

	showSupermarkets(); // Mostramos la lista completa de supermercados

	printf("\n----------------------\n");
	printf("ACTUALIZAR SUPERMERCADO\n");
	printf("----------------------\n\n");

	printf("Introduzca el códgio del supermecado a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);
	supermercado.cod_s = cod_s;

	printf("Introduzca el (posible nuevo) nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	supermercado.nom_s = str;

	printf("\nIntroduzca la (posible nueva) dirección: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	supermercado.dir_s = str;

	printf("\nIntroduzca el (posible nuevo) teléfono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	supermercado.tlf_s = tlf_s;

	printf("\nIntroduzca los (posible nuevos) metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &metros_cuad_s);
	supermercado.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el (posible nuevo) código de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	supermercado.cod_ciu = cod_ciu;

//	executeStatement(sql, db);

	logFile(INFO, "Supermercado actualizado");

	printf(
			"\n¡Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void addProduct() {
	Producto producto; // Estructura creada por Asier (#include ...)

	char *sql = "INSERT INTO PRODUCTO VALUES (?, ?, ?, ?)";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	float precio_prod;

	printf("\n---------------\n");
	printf("AÑADIR PRODUCTO\n");
	printf("---------------\n\n");

	printf("Introduzca el códgio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	producto.id_prod = id_prod;

	printf("Introduzca el nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	producto.nom_prod = str;

	printf("Introduzca el precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &precio_prod);
	producto.precio_prod = precio_prod;

	printf("Introduzca la descripción: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	producto.desc_prod = str;

//	executeStatement(sql, db);

	logFile(INFO, "Producto añadido");

	printf("\n¡Producto añadido con éxito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteProduct() {
	char *sql = "DELETE FROM PRODUCTO WHERE ID_PROD = ?;";
	char strAux[2];

	showProducts(); // Mostramos la lista completa de supermercados

	printf("\n-------------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-------------------\n\n");

	// FALTA CODIFICAR

//	executeStatement(sql, db);

	logFile(INFO, "Producto eliminado");

	printf("\n¡Producto eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateProduct() {
	Producto producto; // Estructura creada por Asier (#include ...)

	char *sql =
			"UPDATE PRODUCTO SET ? = ?, ? = ?, ? = ?, ? = ? WHERE ID_PROD = ?";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	float precio_prod;

	showProducts(); // Mostramos la lista completa de supermercados

	printf("\n------------------\n");
	printf("ACTUALIZAR PRODUCTO\n");
	printf("------------------\n\n");

	printf("Introduzca el códgio del producto a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	producto.id_prod = id_prod;

	printf("Introduzca el (posible nuevo) nombre: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	producto.nom_prod = str;

	printf("Introduzca el (posible nuevo) precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &precio_prod);
	producto.precio_prod = precio_prod;

	printf("Introduzca la (posible nueva) descripción: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	producto.desc_prod = str;

//	executeStatement(sql, db);

	logFile(INFO, "Producto actualizado");

	printf(
			"\n¡Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}


/*
 * methods.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker López
 */

#include "functions.h"
#include "../handler/DBH.h"
#include "../handler/logger/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void showSupermarkets(bool b) {
	char *sql = "SELECT * FROM SUPERMERCADO;";
	char strAux[2];

	if (b) {
		printf("\n-------------------------------\n");
		printf("LISTA COMPLETA DE SUPERMERCADOS\n");
		printf("-------------------------------\n\n");
	}

	Data datos = executeQuery(sql);
	printf("CODIGO || NOMBRE || DIRECCION || TELEFONO || METROS_CUADRADOS || CODIGO_CIUDAD \n\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i || ", sqlite3_column_int(datos.stmt, 0));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 2));
		printf("%i || ", sqlite3_column_int(datos.stmt, 3));
		printf("%f || ", sqlite3_column_double(datos.stmt, 4));
		printf("%i \n", sqlite3_column_int(datos.stmt, 5));
	}

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de supermercados mostrada");

	if (b) {
		printf(
				"\n¡Lista completa de supermercados mostrada! Pulse ENTER para volver al menú principal: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	}
}

void showProducts(bool b) {
	char *sql = "SELECT * FROM PRODUCTO;";
//	int result;
	char strAux[2];

	if (b) {
		printf("\n---------------------------\n");
		printf("LISTA COMPLETA DE PRODUCTOS\n");
		printf("---------------------------\n\n");
	}

	Data datos = executeQuery(sql);
	printf("CODIGO || NOMBRE || PRECIO || DESCRIPCION \n\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i || ", sqlite3_column_int(datos.stmt, 0));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%f || ", sqlite3_column_double(datos.stmt, 2));
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

//	printf("\n");

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de productos mostrada");

	if (b) {
		printf(
				"\n¡Lista completa de productos mostrada! Pulse ENTER para volver al menú principal: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	}
}

void addSupermarket() {
	Supermercado s;

	char *sql = "INSERT INTO SUPERMERCADO VALUES (?, ?, ?, ?, ?, ?);";
	char str[MAX_LINE];
	char strAux[2];
	int cod_s;
	char nom_s[MAX_LINE];
	char dir_s[MAX_LINE];
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
	s.cod_s = cod_s;

	printf("\nIntroduzca el nombre: ");
	fflush(stdout);
	fgets(nom_s, MAX_LINE, stdin);
	fflush(stdin);
	s.nom_s = nom_s;

	printf("\nIntroduzca la dirección: ");
	fflush(stdout);
	fgets(dir_s, MAX_LINE, stdin);
	fflush(stdin);
	s.dir_s = dir_s;

	printf("\nIntroduzca el teléfono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	s.tlf_s = tlf_s;

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &metros_cuad_s);
	s.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el código de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	s.cod_ciu = cod_ciu;

	addSupermarketDB(sql, s);

	printf("\n¡Supermercado añadido con éxito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteSupermarket() {
	char *sql = "DELETE FROM SUPERMERCADO WHERE COD_S = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int cod_s;

	showSupermarkets(false); // Mostramos la lista completa de supermercados

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("-------------------\n\n");

	printf("Introduzca el código del supermercado a eliminar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);

	deleteSupermarketDB(sql, cod_s);

	printf(
			"\n¡Supermercado eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateSupermarket() {
	Supermercado s;

	// No dejamos que el COD_S se actualice
	char *sql =
			"UPDATE SUPERMERCADO SET NOM_S = ?, DIR_S = ?, TLF_S = ?, METROS_CUAD_S = ?, COD_CIU = ? WHERE COD_S = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int cod_s;
	char nom_s[MAX_LINE];
	char dir_s[MAX_LINE];
	int tlf_s;
	float metros_cuad_s;
	int cod_ciu;

	showSupermarkets(false); // Mostramos la lista completa de supermercados

	printf("\n----------------------\n");
	printf("ACTUALIZAR SUPERMERCADO\n");
	printf("----------------------\n\n");

	printf("Introduzca el código del supermercado a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);
	s.cod_s = cod_s;

	printf("\nIntroduzca el (posible nuevo) nombre: ");
	fflush(stdout);
	fgets(nom_s, MAX_LINE, stdin);
	fflush(stdin);
	s.nom_s = nom_s;

	printf("\nIntroduzca la (posible nueva) dirección: ");
	fflush(stdout);
	fgets(dir_s, MAX_LINE, stdin);
	fflush(stdin);
	s.dir_s = dir_s;

	printf("\nIntroduzca el (posible nuevo) teléfono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	s.tlf_s = tlf_s;

	printf("\nIntroduzca los (posible nuevos) metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &metros_cuad_s);
	s.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el (posible nuevo) código de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	s.cod_ciu = cod_ciu;

	updateSupermarketDB(sql, s);

	printf(
			"\n¡Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void addProduct() {
	Producto p;

	char *sql = "INSERT INTO PRODUCTO VALUES (?, ?, ?, ?)";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	char nom_prod[MAX_LINE];
	float precio_prod;
	char desc_prod[MAX_LINE];

	printf("\n---------------\n");
	printf("AÑADIR PRODUCTO\n");
	printf("---------------\n\n");

	printf("Introduzca el códgio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	p.id_prod = id_prod;

	printf("\nIntroduzca el nombre: ");
	fflush(stdout);
	fgets(nom_prod, MAX_LINE, stdin);
	fflush(stdin);
	p.nom_prod = nom_prod;

	printf("\nIntroduzca el precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &precio_prod);
	p.precio_prod = precio_prod;

	printf("\nIntroduzca la descripción: ");
	fflush(stdout);
	fgets(desc_prod, MAX_LINE, stdin);
	fflush(stdin);
	p.desc_prod = desc_prod;

	addProductDB(sql, p);

	printf("\n¡Producto añadido con éxito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteProduct() {
	char *sql = "DELETE FROM PRODUCTO WHERE ID_PROD = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;

	showProducts(false); // Mostramos la lista completa de supermercados

	printf("\n-------------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-------------------\n\n");

	printf("Introduzca el código del producto a eliminar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);

	deleteProductDB(sql, id_prod);

	printf("\n¡Producto eliminado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void updateProduct() {
	Producto p;

	char *sql =
			"UPDATE PRODUCTO SET NOM_PROD = ?, PRECIO_PROD = ?, DESC_PROD = ? WHERE ID_PROD = ?";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	char nom_prod[MAX_LINE];
	float precio_prod;
	char desc_prod[MAX_LINE];

	showProducts(false); // Mostramos la lista completa de supermercados

	printf("\n------------------\n");
	printf("ACTUALIZAR PRODUCTO\n");
	printf("------------------\n\n");

	printf("Introduzca el código del producto a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	p.id_prod = id_prod;

	printf("\nIntroduzca el (posible nuevo) nombre: ");
	fflush(stdout);
	fgets(nom_prod, MAX_LINE, stdin);
	fflush(stdin);
	p.nom_prod = nom_prod;

	printf("\nIntroduzca el (posible nuevo) precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%f", &precio_prod);
	p.precio_prod = precio_prod;

	printf("\nIntroduzca la (posible nueva) descripción: ");
	fflush(stdout);
	fgets(desc_prod, MAX_LINE, stdin);
	fflush(stdin);
	p.desc_prod = desc_prod;

	updateProductDB(sql, p);

	printf(
			"\n¡Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}


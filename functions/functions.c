/*
 * functions.c
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker L�pez
 */

#include "functions.h"
#include "../handler/DBH.h"
#include "../menu/menu.h"
#include "../handler/logger/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 40

void showStatistics() {
	char strAux[2];
	Data datos1;
	Data datos2;

	printf("\n------------\n");
	printf("ESTAD�STICAS\n");
	printf("------------\n\n");

	datos1 = executeQuery("SELECT AVG(PRECIO_PROD) FROM PRODUCTO");
	datos2 = executeQuery("SELECT AVG(METROS_CUAD_S) FROM SUPERMERCADO");

	sqlite3_step(datos1.stmt);
	sqlite3_step(datos2.stmt);

	printf("Media de los precios de los productos: %.2lf�\n",
			sqlite3_column_double(datos1.stmt, 0));
	printf("Media de los metros cuadrados de los supermercados: %.2lfm\n",
			sqlite3_column_double(datos2.stmt, 0));

	logFile(INFO, "Estad�sticas mostradas");

	printf(
			"\n�Estad�sticas mostradas! Pulse ENTER para volver al men� principal: ");
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
	printf(
			"CODIGO || NOMBRE || DIRECCION || TELEFONO || METROS_CUADRADOS || CODIGO_CIUDAD\n\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i || ", sqlite3_column_int(datos.stmt, 0));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 2));
		printf("%i || ", sqlite3_column_int(datos.stmt, 3));
		printf("%.2lf || ", sqlite3_column_double(datos.stmt, 4));
		printf("%i\n", sqlite3_column_int(datos.stmt, 5));
	}

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de supermercados mostrada");

	if (b) {
		printf(
				"\n�Lista completa de supermercados mostrada! Pulse ENTER para volver al men� principal: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	}
}

void showSupermarketPK() {
	char *sql = "SELECT COD_S FROM SUPERMERCADO;";

	Data datos = executeQuery(sql);
	printf("CODIGOS DE SUPERMERCADO ACTUALES\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i\n", sqlite3_column_int(datos.stmt, 0));
	}

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "C�digos de supermercados mostrados");
}

void showProducts(bool b) {
	char *sql = "SELECT * FROM PRODUCTO;";
	char strAux[2];

	if (b) {
		printf("\n---------------------------\n");
		printf("LISTA COMPLETA DE PRODUCTOS\n");
		printf("---------------------------\n\n");
	}

	Data datos = executeQuery(sql);
	printf("CODIGO || NOMBRE || PRECIO || DESCRIPCION\n\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i || ", sqlite3_column_int(datos.stmt, 0));
		printf("%s || ", (char*) sqlite3_column_text(datos.stmt, 1));
		printf("%.2lf || ", sqlite3_column_double(datos.stmt, 2));
		printf("%s\n", (char*) sqlite3_column_text(datos.stmt, 3));
	}

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "Lista completa de productos mostrada");

	if (b) {
		printf(
				"\n�Lista completa de productos mostrada! Pulse ENTER para volver al men� principal: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	}
}

void showProductPK() {
	char *sql = "SELECT ID_PROD FROM PRODUCTO;";

	Data datos = executeQuery(sql);
	printf("CODIGOS DE PRODUCTO ACTUALES\n");
	while (sqlite3_step(datos.stmt) == SQLITE_ROW) {
		printf("%i\n", sqlite3_column_int(datos.stmt, 0));
	}

	sqlite3_finalize(datos.stmt);

	logFile(INFO, "C�digos de productos mostrados");
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
	double metros_cuad_s;
	int cod_ciu;

	printf("\n-------------------\n");
	printf("A�ADIR SUPERMERCADO\n");
	printf("-------------------\n\n");

	showSupermarketPK(); // Mostramos los c�digos de los supermercados

	printf("\nIntroduzca el c�digo: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);
	s.cod_s = cod_s;

	printf("\nIntroduzca el nombre (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(nom_s, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(nom_s, "%s", nom_s);
	s.nom_s = nom_s;

	printf("\nIntroduzca la direcci�n (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(dir_s, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(dir_s, "%s", dir_s);
	s.dir_s = dir_s;

	printf("\nIntroduzca el tel�fono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	s.tlf_s = tlf_s;

	printf("\nIntroduzca los metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%lf", &metros_cuad_s);
	s.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el c�digo de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	s.cod_ciu = cod_ciu;

	addSupermarketDB(sql, s);

	printf("\n�Supermercado a�adido con �xito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteSupermarket() {
	char *sql = "DELETE FROM SUPERMERCADO WHERE COD_S = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int cod_s;
	char opt;

	printf("\n---------------------\n");
	printf("ELIMINAR SUPERMERCADO\n");
	printf("---------------------\n\n");

	showSupermarkets(false); // Mostramos la lista completa de supermercados

	printf("\nIntroduzca el c�digo del supermercado a eliminar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);

	printf("\n�Est� seguro? Si continua se eliminar� el supermercado [s/n]: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%c", &opt);

	// Asumimos que el usuario solo introducir� una 's' o una 'n'
	if (opt == 's') {
		deleteSupermarketDB(sql, cod_s);

		printf(
				"\n�Supermercado eliminado correctamente! Pulse ENTER para continuar: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	} else if (opt == 'n') {
		manageSuperMenu();
	}
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
	double metros_cuad_s;
	int cod_ciu;

	printf("\n-----------------------\n");
	printf("ACTUALIZAR SUPERMERCADO\n");
	printf("-----------------------\n\n");

	showSupermarkets(false); // Mostramos la lista completa de supermercados

	printf("\nIntroduzca el c�digo del supermercado a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_s);
	s.cod_s = cod_s;

	printf(
			"\nIntroduzca el (posible nuevo) nombre (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(nom_s, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(nom_s, "%s", nom_s);
	s.nom_s = nom_s;

	printf(
			"\nIntroduzca la (posible nueva) direcci�n (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(dir_s, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(dir_s, "%s", dir_s);
	s.dir_s = dir_s;

	printf("\nIntroduzca el (posible nuevo) tel�fono: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &tlf_s);
	s.tlf_s = tlf_s;

	printf("\nIntroduzca los (posibles nuevos) metros cuadrados: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%lf", &metros_cuad_s);
	s.metros_cuad_s = metros_cuad_s;

	printf("\nIntroduzca el (posible nuevo) c�digo de la ciudad: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &cod_ciu);
	s.cod_ciu = cod_ciu;

	updateSupermarketDB(sql, s);

	printf(
			"\n�Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
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
	double precio_prod;
	char desc_prod[MAX_LINE];

	printf("\n---------------\n");
	printf("A�ADIR PRODUCTO\n");
	printf("---------------\n\n");

	showProductPK(); // Mostramos los c�digos de los productos

	printf("\nIntroduzca el c�digo: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	p.id_prod = id_prod;

	printf("\nIntroduzca el nombre (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(nom_prod, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(nom_prod, "%s", nom_prod);
	p.nom_prod = nom_prod;

	printf("\nIntroduzca el precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%lf", &precio_prod);
	p.precio_prod = precio_prod;

	printf("\nIntroduzca la descripci�n (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(desc_prod, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(desc_prod, "%s", desc_prod);
	p.desc_prod = desc_prod;

	addProductDB(sql, p);

	printf("\n�Producto a�adido con �xito! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}

void deleteProduct() {
	char *sql = "DELETE FROM PRODUCTO WHERE ID_PROD = ?;";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	char opt;

	printf("\n-----------------\n");
	printf("ELIMINAR PRODUCTO\n");
	printf("-----------------\n\n");

	showProducts(false); // Mostramos la lista completa de supermercados

	printf("\nIntroduzca el c�digo del producto a eliminar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);

	printf("\n�Est� seguro? Si continua se eliminar� el producto [s/n]: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%c", &opt);

	// Asumimos que el usuario solo introducir� una 's' o una 'n'
	if (opt == 's') {
		deleteProductDB(sql, id_prod);

		printf(
				"\n�Producto eliminado correctamente! Pulse ENTER para continuar: ");
		fflush(stdout);
		fgets(strAux, 2, stdin);
		fflush(stdin);
	} else if (opt == 'n') {
		manageProdMenu();
	}
}

void updateProduct() {
	Producto p;

	char *sql =
			"UPDATE PRODUCTO SET NOM_PROD = ?, PRECIO_PROD = ?, DESC_PROD = ? WHERE ID_PROD = ?";
	char str[MAX_LINE];
	char strAux[2];
	int id_prod;
	char nom_prod[MAX_LINE];
	double precio_prod;
	char desc_prod[MAX_LINE];

	printf("\n-------------------\n");
	printf("ACTUALIZAR PRODUCTO\n");
	printf("-------------------\n\n");

	showProducts(false); // Mostramos la lista completa de supermercados

	printf("\nIntroduzca el c�digo del producto a actualizar: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%i", &id_prod);
	p.id_prod = id_prod;

	printf(
			"\nIntroduzca el (posible nuevo) nombre (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(nom_prod, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(nom_prod, "%s", nom_prod);
	p.nom_prod = nom_prod;

	printf("\nIntroduzca el (posible nuevo) precio: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(str, "%lf", &precio_prod);
	p.precio_prod = precio_prod;

	printf(
			"\nIntroduzca la (posible nueva) descripci�n (separe la palabras con '_'): ");
	fflush(stdout);
	fgets(desc_prod, MAX_LINE, stdin);
	fflush(stdin);
	sscanf(desc_prod, "%s", desc_prod);
	p.desc_prod = desc_prod;

	updateProductDB(sql, p);

	printf(
			"\n�Supermercado actualizado correctamente! Pulse ENTER para continuar: ");
	fflush(stdout);
	fgets(strAux, 2, stdin);
	fflush(stdin);
}


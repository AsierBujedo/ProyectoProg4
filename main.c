/*
 * main.c
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sqlite3.h"

void initBD(){

	sqlite3 *db;
	char *zErrMsg = 0;
//	sqlite3_stmt *stmt;

	int result = sqlite3_open("desutoMarketBD.sqlite", &db);
	if (result != SQLITE_OK) {
	printf("Error opening database\n");

	// Tabla SUPERMERCADO
	char *sql1 = "DROP TABLE IF EXISTS SUPERMERCADO;"
				"CREATE TABLE SUPERMERCADO ("
					"COD_S INT PRIMARY KEY NOT NULL,"
					"NOM_S VARCHAR(25),"
					"DIR_S VARCHAR(35),"
					"TLF_S INT,"
					"METROS_CUAD_S DOUBLE,"
					"COD_CIU INT FOREIGN KEY REFERENCES CIUADAD (COD_CIU));";

	// Ejecutar la sentencia SQL
	int rc = sqlite3_exec(db, sql1, callback, 0, &zErrMsg);

	if( rc != SQLITE_OK ){
	   fprintf(stderr, "SQL error: %s\n", zErrMsg);
	   sqlite3_free(zErrMsg);
	} else {
	   fprintf(stdout, "La tabla se ha creado satisfactoriamente\n");
	}

	// Tabla PROVINCIA
	char *sql2 = "DROP TABLE IF EXISTS PROVINCIA;"
				 "CREATE TABLE PROVINCIA ("
				 	 "COD_PROV INT PRIMARY KEY NOT NULL,"
				 	 "NOM_PROV VARCHAR(25));";

	// Ejecutar la sentencia SQL
	// ...

	// Tabla CIUDAD
	char *sql3 = "DROP TABLE IF EXISTS CIUDAD;"
				 "CREATE TABLE CIUDAD ("
				 	 "COD_CIU INT PRIMARY KEY NOT NULL,"
				 	 "NOM_CIU VARCHAR(25),"
				 	 "COD_PROV INT FOREIGN KEY REFERENCES PROVINCIA (COD_PROV));";

	// Ejecutar la sentencia SQL
		// ...

	// Tabla EMPLEADO
	char *sql4 = "DROP TABLE IF EXISTS EMPLEADO;"
				 "CREATE TABLE EMPLEADO ("
				 	 "DNI_EMP VARCHAR(9) PRIMARY KEY NOT NULL,"
				 	 "NOM_EMP VARCHAR(25),"
				 	 "SALARIO_EMP DOUBLE,"
				 	 "FECHA_NCTO_EMP DATE,"
				 	 "DIR_EMP VARCHAR(35),"
				 	 "DNI_JEFE VARCHAR(9) FOREIGN KEY REFENRENCES EMPLEADO (DNI_EMP));";

	// Ejecutar la sentencia SQL
		// ...

	// Tabla PRODUCTO
	char *sql5 = "DROP TABLE IF EXISTS PRODUCTO;"
				 "CREATE TABLE PRODUCTO ("
				 	 "ID_PROD INT PRIMARY KEY NOT NULL,"
				 	 "NOM_PROD VARCHAR(25),"
				 	 "PRECIO_PROD DOUBLE,"
				 	 "DESC_PROD VARVHAR(35));";

	// Ejecutar la sentencia SQL
		// ...

	// Tabla VENDE
	char *sql6 = "DROP TABLE IF EXISTS VENDE;"
				 "CREATE TABLE VENDE ("
				 	 "COD_S INT NOT NULL, "
				 	 "ID_PROD INT NOT NULL, "
				 	 "PRIMARY KEY(COD_S, ID_PROD),"
				 	 "COD_S FOREIGN KEY REFERENCES SUPERMERCADO (COD_S),"
				 	 "ID_PROD FOREIGN KEY REFERENCES PRODUCTO (ID_PROD));";

	// Ejecutar la sentencia SQL
		// ...

	// Tabla TRABAJA
	char *sql7 = "DROP TABLE IF EXISTS TRABAJA;"
				 "CREATE TABLE TRABAJA("
				 "COD_S INT NOT NULL,"
				 "DNI_EMP VARCHAR(9) NOT NULL, "
				 "PRIMARY KEY (COD_S, DNI_EMP),"
				 "COD_S FOREIGN KEY REFERENCES SUPERMERCADO (COD_S),"
				 "DNI_EMP FOREIGN KEY REFERENCES EMPLEADO (DNI_EMP));";

	// Ejecutar la sentencia SQL
		// ...
	HOLA

	return result;
}

int main() {
	initBD();
	return 0;
}



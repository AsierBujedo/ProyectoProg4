/*
 * main.c
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */

#include <string.h>
#include <stdbool.h>
#include "handler/DBH.h"

int main() {

	char *sql2 = "DROP TABLE IF EXISTS PROVINCIA;"
					 "CREATE TABLE PROVINCIA ("
					 	 "COD_PROV INT PRIMARY KEY NOT NULL,"
					 	 "NOM_PROV VARCHAR(25));";

	char *sql3 = "DROP TABLE IF EXISTS CIUDAD;"
				 "CREATE TABLE CIUDAD ("
				 	 "COD_CIU INT PRIMARY KEY NOT NULL,"
				 	 "NOM_CIU VARCHAR(25),"
				 	 "COD_PROV INT, FOREIGN KEY (COD_PROV) REFERENCES PROVINCIA (COD_PROV));";

	char *sql1 = "DROP TABLE IF EXISTS SUPERMERCADO;"
					"CREATE TABLE SUPERMERCADO ("
						"COD_S INT PRIMARY KEY NOT NULL,"
						"NOM_S VARCHAR(25),"
						"DIR_S VARCHAR(35),"
						"TLF_S INT,"
						"METROS_CUAD_S DOUBLE,"
						"COD_CIU INT, FOREIGN KEY (COD_CIU) REFERENCES CIUADAD (COD_CIU));";

	char *sql4 = "DROP TABLE IF EXISTS EMPLEADO;"
				 "CREATE TABLE EMPLEADO ("
				 	 "DNI_EMP VARCHAR(9) PRIMARY KEY NOT NULL,"
				 	 "NOM_EMP VARCHAR(25),"
				 	 "SALARIO_EMP DOUBLE,"
				 	 "FECHA_NCTO_EMP DATE,"
				 	 "DIR_EMP VARCHAR(35),"
				 	 "DNI_JEFE VARCHAR(9), FOREIGN KEY (DNI_JEFE) REFERENCES EMPLEADO (DNI_EMP));";

	char *sql5 = "DROP TABLE IF EXISTS PRODUCTO;"
				 "CREATE TABLE PRODUCTO ("
				 	 "ID_PROD INT PRIMARY KEY NOT NULL,"
				 	 "NOM_PROD VARCHAR(25),"
				 	 "PRECIO_PROD DOUBLE,"
				 	 "DESC_PROD VARVHAR(35));";

	char *sql6 = "DROP TABLE IF EXISTS VENDE;"
				 "CREATE TABLE VENDE ("
				 	 "COD_S INT NOT NULL, "
				 	 "ID_PROD INT NOT NULL, "
				 	 "PRIMARY KEY(COD_S, ID_PROD),"
				 	 "FOREIGN KEY (COD_S) REFERENCES SUPERMERCADO (COD_S),"
				 	 "FOREIGN KEY (ID_PROD) REFERENCES PRODUCTO (ID_PROD));";

	char *sql7 = "DROP TABLE IF EXISTS TRABAJA;"
				 "CREATE TABLE TRABAJA("
				 "COD_S	INT NOT NULL,"
				 "DNI_EMP VARCHAR(9) NOT NULL, "
				 "PRIMARY KEY (COD_S, DNI_EMP) "
				 "FOREIGN KEY (COD_S) REFERENCES SUPERMERCADO (COD_S),"
				 "FOREIGN KEY (DNI_EMP) REFERENCES EMPLEADO (DNI_EMP));";

	sqlite3 *db;
	db = initDB("DeustoMarket.db");
	executeStatement(sql2, db);
	executeStatement(sql3, db);
	executeStatement(sql1, db);
	executeStatement(sql4, db);
	executeStatement(sql5, db);
	executeStatement(sql6, db);
	executeStatement(sql7, db);
	closeDB(db);


	return 0;
}



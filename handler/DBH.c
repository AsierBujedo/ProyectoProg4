/*
 * DBH.c
 *
 *  Created on: 18 mar. 2022
 *      Author: asier
 */

#include"DBH.h"
#include "logger\logger.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

sqlite3 *db;

void initDB(char name[]) {
	int res;

	res = sqlite3_open(name, &db);
	if (res) {
		logFile(ERRORL, sqlite3_errmsg(db));
	} else {
		logFile(INFO, "BD inicializada");
	}
}

void executeStatement(char sql[]) {
	int res;
	char *error;

	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		logFile(ERRORL, error);
		sqlite3_free(error);
	} else {
		logFile(INFO, "Sentencia ejecutada correctamente");
	}
}

Data executeQuery(char sql[]) {
	sqlite3_stmt *stmt;
	int cols;
	int rows;
	int rc;

	rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

	if (rc != SQLITE_OK) {
		logFile(ERRORL, sqlite3_errmsg(db));
	}

	cols = sqlite3_column_count(stmt);

	while (SQLITE_ROW == sqlite3_step(stmt)) {
		rows++;
	}
	sqlite3_reset(stmt);

//	for (int i = 0; i <= rows - 1; i++) {
//		sqlite3_step(stmt);
//		for (int j = 0; j <= cols - 1; j++) {
//			printf("Cols: %i, Rows %i Text: %s\n", j, i,
//					sqlite3_column_text(stmt, j));
//		}
//	}

	Data content;
	content.rows = rows;
	content.cols = cols;
	content.stmt = stmt;

	sqlite3_reset(stmt);
	logFile(INFO, "Consulta realizada correctamente");
	return content;
}

void closeDB() {
	sqlite3_close(db);
	free(db);
	logFile(INFO, "BD cerrada correctamente");
}

void addCityDB(char sql[], Ciudad d) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO CIUDAD VALUES (?, ?, ?);";
	sqlite3_bind_int(stmt, 1, d.cod_ciu);
	sqlite3_bind_text(stmt, 2, d.nom_ciu, strlen(d.nom_ciu), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, d.cod_prov);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir ciudad");
	} else {
		logFile(INFO, "Ciudad a�adida");
	}
}

void addEmployeeDB(char sql[], Empleado emp) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO EMPLEADO VALUES (?, ?, ?, ?, ?, ?)";
	sqlite3_bind_text(stmt, 1, emp.dni_emp, strlen(emp.dni_emp), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, emp.nom_emp, strlen(emp.nom_emp), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, emp.salario_emp);
	sqlite3_bind_text(stmt, 4, emp.fecha_ncto_emp, strlen(emp.fecha_ncto_emp),
	SQLITE_STATIC);
	sqlite3_bind_text(stmt, 5, emp.dir_emp, strlen(emp.dir_emp), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 6, emp.dni_jefe, strlen(emp.dni_jefe),
	SQLITE_STATIC);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir empleado");
	} else {
		logFile(INFO, "empleado a�adido");
	}
}

void addProductDB(char sql[], Producto p) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO PRODUCTO VALUES (?, ?, ?, ?)";
	sqlite3_bind_int(stmt, 1, p.id_prod);
	sqlite3_bind_text(stmt, 2, p.nom_prod, strlen(p.nom_prod), SQLITE_STATIC);
	sqlite3_bind_double(stmt, 3, p.precio_prod);
	sqlite3_bind_text(stmt, 4, p.desc_prod, strlen(p.desc_prod), SQLITE_STATIC);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir producto");
	} else {
		logFile(INFO, "Producto a�adido");
	}
}

void deleteProductDB(char sql[], int id_prod) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "DELETE FROM PRODUCTO WHERE ID_PROD = ?;";
	sqlite3_bind_int(stmt, 1, id_prod);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al eliminar producto");
	} else {
		logFile(INFO, "Producto eliminado");
	}
}

void updateProductDB(char sql[], Producto p) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "UPDATE PRODUCTO SET NOM_PROD = ?, PRECIO_PROD = ?, DESC_PROD = ? WHERE ID_PROD = ?";
	sqlite3_bind_text(stmt, 1, p.nom_prod, strlen(p.nom_prod), SQLITE_STATIC);
	sqlite3_bind_double(stmt, 2, p.precio_prod);
	sqlite3_bind_text(stmt, 3, p.desc_prod, strlen(p.desc_prod), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 4, p.id_prod);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al actualizar producto");
	} else {
		logFile(INFO, "Producto actualizado");
	}
}

void addProvinceDB(char sql[], Provincia p) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO PROVINCIA VALUES (?, ?);";
	sqlite3_bind_int(stmt, 1, p.cod_prov);
	sqlite3_bind_text(stmt, 2, p.nom_prov, strlen(p.nom_prov), SQLITE_STATIC);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir provincia");
	} else {
		logFile(INFO, "Provincia a�adida");
	}
}

void addSupermarketDB(char sql[], Supermercado s) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO SUPERMERCADO VALUES (?, ?, ?, ?, ?, ?);";
	sqlite3_bind_int(stmt, 1, s.cod_s);
	sqlite3_bind_text(stmt, 2, s.nom_s, strlen(s.nom_s), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, s.dir_s, strlen(s.dir_s), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 4, s.tlf_s);
	sqlite3_bind_double(stmt, 5, s.metros_cuad_s);
	sqlite3_bind_int(stmt, 6, s.cod_ciu);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir supermercado");
	} else {
		logFile(INFO, "Supermercado a�adido");
	}
}

void deleteSupermarketDB(char sql[], int cod_s) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "DELETE FROM SUPERMERCADO WHERE COD_S = ?;";
	sqlite3_bind_int(stmt, 1, cod_s);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al eliminar supermercado");
	} else {
		logFile(INFO, "Supermercado eliminado");
	}
}

void updateSupermarketDB(char sql[], Supermercado s) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "UPDATE SUPERMERCADO SET NOM_S = ?, DIR_S = ?, TLF_S = ?, METROS_CUAD_S = ?, COD_CIU = ? WHERE COD_S = ?;";
	sqlite3_bind_text(stmt, 1, s.nom_s, strlen(s.nom_s), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, s.dir_s, strlen(s.dir_s), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, s.tlf_s);
	sqlite3_bind_double(stmt, 4, s.metros_cuad_s);
	sqlite3_bind_int(stmt, 5, s.cod_ciu);
	sqlite3_bind_int(stmt, 6, s.cod_s);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al actualizar supermercado");
	} else {
		logFile(INFO, "Supermercado actualizado");
	}
}

void addWorksDB(char sql[], Trabaja t) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO TRABAJA VALUES (?, ?);";
	sqlite3_bind_int(stmt, 1, t.cod_s);
	sqlite3_bind_text(stmt, 2, t.dni_emp, strlen(t.dni_emp), SQLITE_STATIC);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir trabaja");
	} else {
		logFile(INFO, "Trabaja a�adido");
	}
}

void addSellsDB(char sql[], Vende v) {
	sqlite3_stmt *stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

//	sql = "INSERT INTO VENDE VALUES (?, ?);";
	sqlite3_bind_int(stmt, 1, v.cod_s);
	sqlite3_bind_int(stmt, 2, v.id_prod);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERRORL, "Error al a�adir vende");
	} else {
		logFile(INFO, "Vende a�adido");
	}
}

void csvCityLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Ciudad ciud;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &ciud.cod_ciu);
			token = strtok(NULL, delim);
			ciud.nom_ciu = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", ciud.nom_ciu);
			token = strtok(NULL, delim);
			sscanf(token, "%i", &ciud.cod_prov);

			addCityDB("INSERT INTO CIUDAD VALUES (?, ?, ?)", ciud);
		}
	}

	fclose(csv);
}

void csvEmployeeLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Empleado emp;
		token = strtok(row, delim);

		emp.dni_emp = malloc(sizeof(char) * strlen(token));
		sscanf(token, "%s", emp.dni_emp);
		token = strtok(NULL, delim);
		emp.nom_emp = malloc(sizeof(char) * strlen(token));
		sscanf(token, "%s", emp.nom_emp);
		token = strtok(NULL, delim);
		sscanf(token, "%lf", &emp.salario_emp);
		token = strtok(NULL, delim);
		emp.fecha_ncto_emp = malloc(sizeof(char) * strlen(token));
		sscanf(token, "%s", emp.fecha_ncto_emp);
		token = strtok(NULL, delim);
		emp.dir_emp = malloc(sizeof(char) * strlen(token));
		sscanf(token, "%s", emp.dir_emp);
		token = strtok(NULL, delim);
		if (token != NULL) {
			emp.dni_jefe = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", emp.dni_jefe);
		} else {
			emp.dni_jefe = NULL;
		}

		addEmployeeDB("INSERT INTO EMPLEADO VALUES (?, ?, ?, ?, ?, ?)", emp);

	}

	fclose(csv);

}

void csvProductLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Producto prod;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &prod.id_prod);
			token = strtok(NULL, delim);
			prod.nom_prod = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", prod.nom_prod);
			token = strtok(NULL, delim);
			sscanf(token, "%lf", &prod.precio_prod);
			token = strtok(NULL, delim);
			prod.desc_prod = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", prod.desc_prod);

			addProductDB("INSERT INTO PRODUCTO VALUES (?, ?, ?, ?)", prod);
		}
	}

	fclose(csv);

}

void csvProvinceLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Provincia prov;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &prov.cod_prov);
			token = strtok(NULL, delim);
			prov.nom_prov = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", prov.nom_prov);

			addProvinceDB("INSERT INTO PROVINCIA VALUES (?, ?)", prov);
		}
	}

	fclose(csv);
}

void csvSupermarketLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Supermercado sup;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &sup.cod_s);
			token = strtok(NULL, delim);
			sup.nom_s = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", sup.nom_s);
			token = strtok(NULL, delim);
			sup.dir_s = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", sup.dir_s);
			token = strtok(NULL, delim);
			sscanf(token, "%i", &sup.tlf_s);
			token = strtok(NULL, delim);
			sscanf(token, "%lf", &sup.metros_cuad_s);
			token = strtok(NULL, delim);
			sscanf(token, "%i", &sup.cod_ciu);

			addSupermarketDB(
					"INSERT INTO SUPERMERCADO VALUES (?, ?, ?, ?, ?, ?);", sup);
		}
	}

	fclose(csv);
}

void csvWorksLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Trabaja trab;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &trab.cod_s);
			token = strtok(NULL, delim);
			trab.dni_emp = malloc(sizeof(char) * strlen(token));
			sscanf(token, "%s", trab.dni_emp);

			addWorksDB("INSERT INTO TRABAJA VALUES (?, ?)", trab);
		}
	}

	fclose(csv);
}

void csvSellsLoader(char name[]) {
	FILE *csv;
	char row[MAX];
	const char delim[2] = ",";
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv) != NULL) {
		Vende ven;
		token = strtok(row, delim);

		if (token != NULL) {
			sscanf(token, "%i", &ven.cod_s);
			token = strtok(NULL, delim);
			sscanf(token, "%i", &ven.id_prod);

			addSellsDB("INSERT INTO VENDE VALUES (?, ?)", ven);
		}
	}

	fclose(csv);
}

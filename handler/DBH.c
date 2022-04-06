/*
 * DBH.c
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */
#include"DBH.h"
#include "logger\logger.h"
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

sqlite3 *db;

void initDB(char name[]) {
	int res;

	res = sqlite3_open(name, &db);
	if (res) {
		logFile(ERROR, sqlite3_errmsg(db));
	} else {
		logFile(INFO, "BD inicializada");
	}
}

void executeStatement(char sql[]) {
	int res;
	char *error;

	res = sqlite3_exec(db, sql, NULL, 0, &error);
	if (res != SQLITE_OK) {
		logFile(ERROR, error);
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
		logFile(ERROR, sqlite3_errmsg(db));
	}

	cols = sqlite3_column_count(stmt);

	while (SQLITE_ROW == sqlite3_step(stmt)) {
		rows++;
	}
	sqlite3_reset(stmt);

//    	for(int i = 0; i<= rows-1; i++){
//    		sqlite3_step(stmt);
//    		for (int j = 0; j<=cols-1; j++) {
//    			printf("Cols: %i, Rows %i Text: %s\n", j, i, sqlite3_column_text(stmt, j));
//    		}
//    	}

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

void addSupermarketDB(char sql[], Supermercado* supermercado) {
	sqlite3_stmt * stmt;

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_int(stmt, 1, supermercado->cod_s);
	sqlite3_bind_text(stmt, 2, supermercado->nom_s, strlen(supermercado->nom_s),
			SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, supermercado->dir_s, strlen(supermercado->dir_s),
			SQLITE_STATIC);
	sqlite3_bind_int(stmt, 4, supermercado->tlf_s);
	sqlite3_bind_double(stmt, 5, supermercado->metros_cuad_s);
	sqlite3_bind_int(stmt, 6, supermercado->cod_ciu);

	if ((sqlite3_step(stmt)) != SQLITE_DONE) {
		logFile(ERROR, "Error anadiendo supermercado");
	} else {
		logFile(INFO, "Supermercado anadido correctamente");
	}
}

void csvLoader(char name[], int code) {

	FILE *csv;
	char row[MAX];
	char *token;

	csv = fopen(name, "r");

	while (fgets(row, MAX, csv)) {
		printf("Row: %s\n", row);

		token = strtok(row, ",");

		int atrib;

		if (code == 1) {
			int i = 0;
			while (token != NULL) {
				if (i == 0) {
					Supermercado sup;
					sup.loadingCode = 1;
					sup.cod_s = token;
					i++;
				} else if (i == 1) {

				}
				printf("Token: %s\n", token);
				token = strtok(NULL, ",");
			}

		} else if (code == 2) {
			atrib = 6;

		} else if (code == 3) {
			atrib = 3;

		} else if (code == 4) {
			atrib = 2;

		} else if (code == 5) {
			atrib = 4;

		} else if (code == 6) {
			atrib = 2;

		} else if (code == 7) {
			atrib = 2;

		}

	}
}

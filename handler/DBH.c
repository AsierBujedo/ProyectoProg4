/*
 * DBH.c
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */
#include"DBH.h"


sqlite3* initDB(char name[]) {
	 sqlite3 *db;
	 int res;

	 res = sqlite3_open(name, &db);
	   if (res) {
	       printf(sqlite3_errmsg(db));
	       exit(0);
	     } else {
	       printf("Base de datos abierta correctamente\n");
	     }
	return db;
}

void executeStatement(char sql[], sqlite3 *db) {
	int res;
	char *error;

	res = sqlite3_exec(db, sql, NULL, 0, &error);
	   if (res != SQLITE_OK)
	     {
	       fprintf(stderr, "Error: %s\n", error);
	       sqlite3_free(error);
	     }
	   else
	     {
	       fprintf(stdout, "Tarea ejecutada\n");
	     }
}

Data executeQuery(char sql[], sqlite3 *db){
	sqlite3_stmt *stmt;
	int cols;
	int rows;
	int rc;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
    }

    cols = sqlite3_column_count(stmt);

    while (SQLITE_ROW == sqlite3_step(stmt)) {
           	rows++;
       }
    sqlite3_reset(stmt);

    	for(int i = 0; i<= rows-1; i++){
    		sqlite3_step(stmt);
    		for (int j = 0; j<=cols-1; j++) {
    			printf("Cols: %i, Rows %i Text: %s\n", j, i, sqlite3_column_text(stmt, j));
    		}
    	}


    Data content;
    content.rows = rows;
    content.cols = cols;
    content.stmt = stmt;

    sqlite3_reset(stmt);
    return content;
}

void closeDB(sqlite3 *db) {
	sqlite3_close(db);
	free(db);
}
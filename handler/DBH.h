/*
 * DBH.h
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */
#include "lib\sqlite3.h"

#ifndef DBH_H_
#define DBH_H_

typedef struct {
	int cols;
	int rows;
	sqlite3_stmt *stmt;
} Data;

void initDB(char name[]);
void executeStatement(char sql[]);
Data executeQuery(char sql[]);
void closeDB();

#endif /* DBH_H_ */

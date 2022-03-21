/*
 * DBH.h
 *
 *  Created on: 18 mar 2022
 *      Author: asier
 */
#include "lib\sqlite3.h"
#include "logger\logger.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#ifndef DBH_H_
#define DBH_H_

typedef struct {
	int cols;
	int rows;
	sqlite3_stmt *stmt;
} Data;

sqlite3* initDB(char name[]);
void executeStatement(char sql[], sqlite3 *db);
Data executeQuery(char sql[], sqlite3 *db);
void closeDB(sqlite3 *db);

#endif /* DBH_H_ */

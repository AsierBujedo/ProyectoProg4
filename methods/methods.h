/*
 * methods.h
 *
 *  Created on: 2 abr. 2022
 *      Author: Iker López
 */

#ifndef METHODS_METHODS_H_
#define METHODS_METHODS_H_
#include "../handler/DBH.h"

void showStatistics(sqlite3* db);
void showSupermarkets(sqlite3* db);
void showProducts(sqlite3* db);
void addSupermarket(sqlite3* db);
void deleteSupermarket(sqlite3* db);
void modSupermarket(sqlite3* db);
void addProduct(sqlite3* db);
void deleteProduct(sqlite3* db);
void modProduct(sqlite3* db);

#endif /* METHODS_METHODS_H_ */

/*
 * DBH.h
 *
 *  Created on: 18 mar. 2022
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

typedef struct {
	int cod_s;
	char* nom_s;
	char* dir_s;
	int tlf_s;
	double metros_cuad_s;
	int cod_ciu;
} Supermercado;

typedef struct {
	char* dni_emp;
	char* nom_emp;
	double salario_emp;
	char* fecha_ncto_emp;
	char* dir_emp;
	char* dni_jefe;
} Empleado;

typedef struct {
	int cod_ciu;
	char* nom_ciu;
	int cod_prov;
} Ciudad;

typedef struct {
	int cod_prov;
	char* nom_prov;
} Provincia;

typedef struct {
	int id_prod;
	char* nom_prod;
	double precio_prod;
	char* desc_prod;
} Producto;

typedef struct {
	int cod_s;
	int id_prod;
} Vende;

typedef struct {
	int cod_s;
	char* dni_emp;
} Trabaja;

void initDB(char name[]);
void executeStatement(char sql[]);
Data executeQuery(char sql[]);
void closeDB();
void getDB(sqlite3* database);
void addSupermarketDB(char sql[], Supermercado s);
void deleteSupermarketDB(char sql[], int cod_s);
void updateSupermarketDB(char sql[], Supermercado s);
void addProductDB(char sql[], Producto p);
void deleteProductDB(char sql[], int id_prod);
void updateProductDB(char sql[], Producto p);
void csvCityLoader(char name[]);
void csvEmployeeLoader(char name[]);
void csvProductLoader(char name[]);
void csvProvinceLoader(char name[]);
void csvSupermarketLoader(char name[]);
void csvWorksLoader(char name[]);
void csvSellsLoader(char name[]);
void addEmployeeDB(char sql[], Empleado emp);

#endif /* DBH_H_ */

#include "lib\sqlite3.h"

#ifndef DBH_H_
#define DBH_H_

typedef struct {
	int cols;
	int rows;
	sqlite3_stmt *stmt;
} Data;

typedef struct {
	int loadingCode; //5 Cod -> 1
	int cod_s;
	char* nom_s;
	char* dir_s;
	int tlf_s;
	double metros_cuad_s;
	int cod_ciu;
} Supermercado;

typedef struct {
	int loadingCode; //6 Cod -> 2
	char* dni_emp;
	char* nom_emp;
	double salario_emp;
	char* fecha_ncto_emp;
	char* dir_emp;
	char* dni_jefe;
} Empleado;

typedef struct {
	int loadingCode; //3 Cod -> 3
	int cod_ciu;
	char* nom_ciu;
	int cod_prov;
} Ciudad;

typedef struct {
	int loadingCode; //2 Cod -> 4
	int cod_prov;
	char* nom_prov;
} Provincia;

typedef struct {
	int loadingCode; //4 Cod -> 5
	int id_prod;
	char* nom_prod;
	double precio_prod;
	char* desc_prod;
} Producto;

typedef struct {
	int loadingCode; //2 Cod -> 6
	int cod_s;
	char* id_prod;
} Vende;

typedef struct {
	int loadingCode; //2 Cod -> 7
	int cod_s;
	char* dni_emp;
} Trabaja;

void initDB(char name[]);
void executeStatement(char sql[]);
Data executeQuery(char sql[]);
void closeDB();
void getDB(sqlite3* database);
void addSupermarketDB(char sql[], Supermercado* supermercado);
void csvLoader(char name[], int code);

#endif /* DBH_H_ */

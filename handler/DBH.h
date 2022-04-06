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
	int code;
	char* name;
	char* dir;
	int telf;
	double m2;
} Supermercado;

typedef struct {
	int loadingCode; //6 Cod -> 2
	char* DNI;
	char* name;
	double salario;
	char* ncto;
	char* dir;
	char* DNI_JEFE;
} Empleado;

typedef struct {
	int loadingCode; //3 Cod -> 3
	int code;
	char* name;
	int cod_prov;

} Ciudad;

typedef struct {
	int loadingCode; //2 Cod -> 4
	int cod_prov;
	char* name;
} Provincia;

typedef struct {
	int loadingCode; //4 Cod -> 5
	int id;
	char* name;
	double precio;
	char* desc;
} Producto;

typedef struct {
	int loadingCode; //2 Cod -> 6
	int cod_s;
	char* id_prod;
} Vende;

typedef struct {
	int loadingCode; //2 Cod -> 7
	int cod_s;
	char* DNI_emp;
} Trabaja;

void initDB(char name[]);
void executeStatement(char sql[]);
Data executeQuery(char sql[]);
void closeDB();
void csvLoader(char name[], int code);

#endif /* DBH_H_ */

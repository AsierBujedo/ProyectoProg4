/*
 * menu.c
 *
 *  Created on: 1 abr. 2022
 *      Author: Iker L�pez
 */

#include "menu.h"

// NIVEL DE MEN�: 5 (administrador)
void manageProdMenu() {
	int opt;
	char str[10];

	printf("-------------------\n");
	printf("GESTIONAR PRODUCTOS\n");
	printf("-------------------\n\n");
	printf("1. A�adir producto\n");
	printf("2. Eliminar producto\n");
	printf("3. Modificar informaci�n de un producto\n");
	printf("4. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
//		addProduct(); SIN CODIFICAR
		break;

	case 2:
//		deleteProduct(); SIN CODIFICAR
		break;

	case 3:
//		modproduct(); SIN CODIFICAR
		break;

	case 4:
		modBDDMenu();
		break;
	}
}

// NIVEL DE MEN�: 5 (administrador)
void manageSuperMenu() {
	int opt;
	char str[10];

	printf("-----------------------\n");
	printf("GESTIONAR SUPERMERCADOS\n");
	printf("-----------------------\n\n");
	printf("1. A�adir supermercado\n");
	printf("2. Eliminar supermercado\n");
	printf("3. Modificar informaci�n de un supermercado\n");
	printf("4. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
//		addSupermarket(); SIN CODIFICAR
		break;

	case 2:
//		deleteSupermarket(); SIN CODIFICAR
		break;

	case 3:
//		modSupermarket(); SIN CODIFICAR
		break;

	case 4:
		modBDDMenu(); // Llamada a m�todo de NIVEL: 4
		break;
	}
}

// NIVEL DE MEN�: 4
void modBDDMenu() {
	int opt;
	char str[10];

	printf("-------------\n");
	printf("MODIFICAR BDD\n");
	printf("-------------\n\n");
	printf("1. Gestionar supermercados\n");
	printf("2. Gestionar productos\n");
	printf("3. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		manageSuperMenu();
		break;

	case 2:
		manageProdMenu();
		break;

	case 3:
		adminMenu(); // Llamada a m�todo de NIVEL: 3
		break;
	}
}

// NIVEL DE MEN�: 3 (usuario) y 4 (administrador)
void queryBDDMenu() {
	int opt;
	char str[10];

	printf("------------------\n");
	printf("CONSULTAS A LA BDD\n");
	printf("------------------\n\n");
	printf("1. Visualizar supermercados\n");
	printf("2. Visualizar productos\n");
	printf("3. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
//		showSupermarkets(); SIN CODIFICAR
		break;

	case 2:
//		showProducts(); SIN CODIFICAR
		break;

	case 3:
		// Hay que comprobar de alguna manera si ha accedido como usuario o administrador
		// userMenu() o adminMenu();
		break;
	}
}

// NIVEL DE MEN�: 3
void adminMenu() {
	int opt;
	char str[10];

	printf("------------------\n");
	printf("MEN� ADMINISTRADOR\n");
	printf("------------------\n\n");
	printf("1. Modificar BDD\n");
	printf("2. Consultas a la BDD\n");
	printf("3. Estad�sticas\n");
	printf("4. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		modBDDMenu();
		break;

	case 2:
		queryBDDMenu();
		break;

	case 3:
//		showStatistics();
		break;

	case 4:
		mainMenu();
		break;
	}
}

// NIVEL DE MEN�: 2
void userMenu() {
	int opt;
	char str[10];

	printf("------------\n");
	printf("MEN� USUARIO\n");
	printf("------------\n\n");
	printf("1. Consultas a la BDD\n");
	printf("2. Estad�sticas\n");
	printf("3. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		queryBDDMenu();
		break;

	case 2:
//		showStatistics();
		break;

	case 3:
		mainMenu();
		break;
	}
}

// NIVEL DE MEN�: 2
void adminAccessMenu() {
	int pass;
	char str[10];

	printf("--------------------\n");
	printf("ACCESO ADMINISTRADOR\n");
	printf("--------------------\n\n");
	printf(
			"Introduzca la clave (si quiere volver pulse 'q' y para continuar pulse ENTER): ");
	fflush(stdout);
	fgets(str, 6, stdin);
	fflush(stdin);
	sscanf(str, "%i", &pass);

	if (pass == 11111) {
		adminMenu();
	} else if (str[0] == 'q') {
		mainMenu();
	} else {
		adminAccessMenu();
	}

}

// NIVEL DE MEN�: 1
void mainMenu() {
	int opt;
	char str[10];

	printf("------------\n");
	printf("DESUTOMARKET\n");
	printf("------------\n\n");
	printf("1. Entrar como usuario\n");
	printf("2. Entrar como administrador\n");
	printf("3. Salir\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		userMenu();
		break;

	case 2:
		adminAccessMenu();
		break;

	case 3:
		exit(0);
	}

}


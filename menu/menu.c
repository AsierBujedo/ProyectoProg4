/*
 * menu.c
 *
 *  Created on: 1 abr. 2022
 *      Author: Iker L�pez
 */

#include "menu.h"
#include "../functions/functions.h"
#include "../handler/logger/logger.h"
#include "../handler/properties/properties.h"
#include <stdio.h>
#include <stdlib.h>

Properties properties;

// NIVEL DE MEN�: 5 (administrador)
void manageProdMenu() {
	int opt;
	char str[10];

	printf("\n-------------------\n");
	printf("GESTIONAR PRODUCTOS\n");
	printf("-------------------\n\n");
	printf("1. A�adir producto\n");
	printf("2. Eliminar producto\n");
	printf("3. Actualizar informaci�n de un producto\n");
	printf("4. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opci�n 1 de manageProdMenu seleccionada (addProduct)");
		addProduct();
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de manageProdMenu seleccionada (deleteProduct)");
		deleteProduct();
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de manageProdMenu seleccionada (updateProduct)");
		updateProduct();
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 4:
		logFile(INFO, "Opci�n 4 de manageProdMenu seleccionada (updateBDMenu<<)");
		updateBDMenu();
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;
	}
}

// NIVEL DE MEN�: 5 (administrador)
void manageSuperMenu() {
	int opt;
	char str[10];

	printf("\n-----------------------\n");
	printf("GESTIONAR SUPERMERCADOS\n");
	printf("-----------------------\n\n");
	printf("1. A�adir supermercado\n");
	printf("2. Eliminar supermercado\n");
	printf("3. Actualizar informaci�n de un supermercado\n");
	printf("4. Volver\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opci�n 1 de manageSuperMenu seleccionada (addSupermarket)");
		addSupermarket();
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de manageSuperMenu seleccionada (deleteSupermarket)");
		deleteSupermarket();
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de manageSuperMenu seleccionada (updateSupermarket())");
		updateSupermarket();
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 4:
		logFile(INFO, "Opci�n 4 de manageSuperMenu seleccionada (updateBDMenu<<)");
		updateBDMenu();
		break;
	}
}

// NIVEL DE MEN�: 4
void updateBDMenu() {
	int opt;
	char str[10];

	printf("\n-------------\n");
	printf("ACTUALIZAR BD\n");
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
		logFile(INFO, "Opci�n 1 de updateBDMenu seleccionada (>>manageSuperMenu)");
		manageSuperMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de updateBDMenu seleccionada (>>manageProdMenu)");
		manageProdMenu();
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de updateBDMenu seleccionada (adminMenu<<)");
		adminMenu();
		break;
	}
}

// NIVEL DE MEN�: 3 (usuario) y 4 (administrador)
void queryBDMenu() {
	int opt;
	char str[10];

	printf("\n-----------------\n");
	printf("CONSULTAS A LA BD\n");
	printf("-----------------\n\n");
	printf("1. Visualizar supermercados\n");
	printf("2. Visualizar productos\n");
	printf("3. Volver a men� principal\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opci�n 1 de queryBDMenu seleccionada (showSupermarkets)");
		showSupermarkets(true);
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de queryBDMenu seleccionada (showProducts)");
		showProducts(true);
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de queryBDMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MEN�: 3
void adminMenu() {
	int opt;
	char str[10];

	printf("\n------------------\n");
	printf("MEN� ADMINISTRADOR\n");
	printf("------------------\n\n");
	printf("1. Actualizar BD\n");
	printf("2. Consultas a la BD\n");
	printf("3. Estad�sticas\n");
	printf("4. Volver al men� principal\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opci�n 1 de adminMenu seleccionada (>>updateBDMenu)");
		updateBDMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de adminMenu seleccionada (>>queryBDMenu)");
		queryBDMenu();
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de adminMenu seleccionada (showStatistics)");
		showStatistics();
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 4:
		logFile(INFO, "Opci�n 4 de adminMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MEN�: 2
void userMenu() {
	int opt;
	char str[10];

	printf("\n------------\n");
	printf("MEN� USUARIO\n");
	printf("------------\n\n");
	printf("1. Consultas a la BD\n");
	printf("2. Estad�sticas\n");
	printf("3. Volver al men� principal\n");
	printf("Introduzca una opci�n: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opci�n 1 de userMenu seleccionada (>>queryBDMenu)");
		queryBDMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de userMenu seleccionada (showStatistics)");
		showStatistics();
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 3:
		logFile(INFO, "Opci�n 3 de userMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MEN�: 2
void adminAccessMenu() {
	int pass;
	char str[10];

	printf("\n--------------------\n");
	printf("ACCESO ADMINISTRADOR\n");
	printf("--------------------\n\n");
	printf(
			"Introduzca la clave (si quiere volver al men� principal pulse 'q' y para continuar pulse ENTER): ");
	fflush(stdout);
	fgets(str, 6, stdin);
	fflush(stdin);
	sscanf(str, "%i", &pass);

	int propPass;
	sscanf(properties.propValue[2], "%i", &propPass);

	if (pass == propPass) {
		logFile(INFO, "Contrase�a de administrador correcta (>>adminMenu)");
		adminMenu();
	} else if (str[0] == 'q') {
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
	} else {
		logFile(INFO, "adminAccessMenu<<");
		adminAccessMenu();
	}

}

// NIVEL DE MEN�: 1
void mainMenu(bool b) {
	int opt;
	char str[10];

	loadProperties(&properties, "config.prop");

	if (b) {
		printf("\n------------\n");
		printf("DEUSTOMARKET\n");
		printf("------------\n\n");
	} else {
		printf("------------\n");
		printf("DEUSTOMARKET\n");
		printf("------------\n\n");
	}

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
		logFile(INFO, "Opci�n 1 de mainMenu seleccionada (>>userMenu)");
		userMenu();
		break;

	case 2:
		logFile(INFO, "Opci�n 2 de mainMenu seleccionada (>>adminMenu)");
		adminAccessMenu();
		break;

	case 3:
		logFile(END, "Opci�n 3 de mainMenu seleccionada (ejecuci�n finalizada)");
		exit(0);
	}

}


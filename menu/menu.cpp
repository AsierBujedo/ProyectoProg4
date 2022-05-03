/*
 * menu.cpp
 *
 *  Created on: 3 may. 2022
 *      Author: Iker López
 */

#include "menu.h"
#include "../handler/server/server.h"
#include "../functions/functions.h"
#include "../handler/logger/logger.h"
#include "../handler/properties/properties.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <iostream>

using namespace std;

Properties properties;
SOCKET s;

int prepareSocket() {
	WSADATA wsaData;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	return 1;
}

// NIVEL DE MENÚ: 5 (administrador)
void manageProdMenu() {
	int opt;
	char str[10];

	printf("\n-------------------\n");
	printf("GESTIONAR PRODUCTOS\n");
	printf("-------------------\n\n");
	printf("1. Añadir producto\n");
	printf("2. Eliminar producto\n");
	printf("3. Actualizar información de un producto\n");
	printf("4. Volver\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opción 1 de manageProdMenu seleccionada (addProduct)");
		addProduct(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 2:
		logFile(INFO,
				"Opción 2 de manageProdMenu seleccionada (deleteProduct)");
		deleteProduct(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 3:
		logFile(INFO,
				"Opción 3 de manageProdMenu seleccionada (updateProduct)");
		updateProduct(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;

	case 4:
		logFile(INFO,
				"Opción 4 de manageProdMenu seleccionada (updateBDMenu<<)");
		updateBDMenu(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageProdMenu<<");
		manageProdMenu();
		break;
	}
}

// NIVEL DE MENÚ: 5 (administrador)
void manageSuperMenu() {
	int opt;
	char str[10];

	printf("\n-----------------------\n");
	printf("GESTIONAR SUPERMERCADOS\n");
	printf("-----------------------\n\n");
	printf("1. Añadir supermercado\n");
	printf("2. Eliminar supermercado\n");
	printf("3. Actualizar información de un supermercado\n");
	printf("4. Volver\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO,
				"Opción 1 de manageSuperMenu seleccionada (addSupermarket)");
		addSupermarket(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 2:
		logFile(INFO,
				"Opción 2 de manageSuperMenu seleccionada (deleteSupermarket)");
		deleteSupermarket(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 3:
		logFile(INFO,
				"Opción 3 de manageSuperMenu seleccionada (updateSupermarket())");
		updateSupermarket(); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "manageSuperMenu<<");
		manageSuperMenu();
		break;

	case 4:
		logFile(INFO,
				"Opción 4 de manageSuperMenu seleccionada (updateBDMenu<<)");
		updateBDMenu(); // PASAR A SERVER Y CAMBIAR
		break;
	}
}

// NIVEL DE MENÚ: 4
void updateBDMenu() {
	int opt;
	char str[10];

	printf("\n-------------\n");
	printf("ACTUALIZAR BD\n");
	printf("-------------\n\n");
	printf("1. Gestionar supermercados\n");
	printf("2. Gestionar productos\n");
	printf("3. Volver\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO,
				"Opción 1 de updateBDMenu seleccionada (>>manageSuperMenu)");
		manageSuperMenu();
		break;

	case 2:
		logFile(INFO,
				"Opción 2 de updateBDMenu seleccionada (>>manageProdMenu)");
		manageProdMenu();
		break;

	case 3:
		logFile(INFO, "Opción 3 de updateBDMenu seleccionada (adminMenu<<)");
		adminMenu();
		break;
	}
}

// NIVEL DE MENÚ: 3 (usuario) y 4 (administrador)
void queryBDMenu() {
	int opt;
	char str[10];

	printf("\n-----------------\n");
	printf("CONSULTAS A LA BD\n");
	printf("-----------------\n\n");
	printf("1. Visualizar supermercados\n");
	printf("2. Visualizar productos\n");
	printf("3. Volver a menú principal\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO,
				"Opción 1 de queryBDMenu seleccionada (showSupermarkets)");
		showSupermarkets(true); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 2:
		logFile(INFO, "Opción 2 de queryBDMenu seleccionada (showProducts)");
		showProducts(true); // PASAR A SERVER Y CAMBIAR
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 3:
		logFile(INFO, "Opción 3 de queryBDMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MENÚ: 3
void adminMenu() {
	int opt;
	char str[10];

	printf("\n------------------\n");
	printf("MENÚ ADMINISTRADOR\n");
	printf("------------------\n\n");
	printf("1. Actualizar BD\n");
	printf("2. Consultas a la BD\n");
	printf("3. Estadísticas\n");
	printf("4. Volver al menú principal\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opción 1 de adminMenu seleccionada (>>updateBDMenu)");
		updateBDMenu();
		break;

	case 2:
		logFile(INFO, "Opción 2 de adminMenu seleccionada (>>queryBDMenu)");
		queryBDMenu();
		break;

	case 3:
		logFile(INFO, "Opción 3 de adminMenu seleccionada (showStatistics)");
//		showStatistics(); // PASAR A SERVER Y CAMBIAR

		// SENDING command SHOWSTATS
		strcpy(sendBuff, "SHOWSTATS");
		strcpy(sendBuff, "SHOWSTATS-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		// RECEIVING response to command SHOWSTATS from the server
		recv(s, recvBuff, sizeof(recvBuff), 0);
//		printf("Suma = %s \n", recvBuff);
		cout << " " << endl;

		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 4:
		logFile(INFO, "Opción 4 de adminMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MENÚ: 2
void userMenu() {
	int opt;
	char str[10];

	printf("\n------------\n");
	printf("MENÚ USUARIO\n");
	printf("------------\n\n");
	printf("1. Consultas a la BD\n");
	printf("2. Estadísticas\n");
	printf("3. Volver al menú principal\n");
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opción 1 de userMenu seleccionada (>>queryBDMenu)");
		queryBDMenu();
		break;

	case 2:
		logFile(INFO, "Opción 2 de userMenu seleccionada (showStatistics)");
//		showStatistics(); // PASAR A SERVER Y CAMBIAR

		// SENDING command SHOWSTATS
		strcpy(sendBuff, "SHOWSTATS");
		strcpy(sendBuff, "SHOWSTATS-END");
		send(s, sendBuff, sizeof(sendBuff), 0);

		// RECEIVING response to command SHOWSTATS from the server
		recv(s, recvBuff, sizeof(recvBuff), 0);
//		printf("Suma = %s \n", recvBuff);
		cout << " " << endl;

		logFile(INFO, "mainMenu<<");
		mainMenu(true);
		break;

	case 3:
		logFile(INFO, "Opción 3 de userMenu seleccionada (mainMenu<<)");
		mainMenu(true);
		break;
	}
}

// NIVEL DE MENÚ: 2
void adminAccessMenu() {
	int pass;
	char str[10];

	printf("\n--------------------\n");
	printf("ACCESO ADMINISTRADOR\n");
	printf("--------------------\n\n");
	printf(
			"Introduzca la clave (si quiere volver al menú principal pulse 'q' y para continuar pulse ENTER): ");
	fflush(stdout);
	fgets(str, 6, stdin);
	fflush(stdin);
	sscanf(str, "%i", &pass);

	int propPass;
	sscanf(properties.propValue[2], "%i", &propPass);

	if (pass == propPass) {
		logFile(INFO, "Contraseña de administrador correcta (>>adminMenu)");
		adminMenu();
	} else if (str[0] == 'q') {
		logFile(INFO, "mainMenu<<");
		mainMenu(true);
	} else {
		logFile(INFO, "adminAccessMenu<<");
		adminAccessMenu();
	}

}

// NIVEL DE MENÚ: 1
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
	printf("Introduzca una opción: ");
	fflush(stdout);
	fgets(str, 2, stdin);
	fflush(stdin);
	sscanf(str, "%i", &opt);

	switch (opt) {
	case 1:
		logFile(INFO, "Opción 1 de mainMenu seleccionada (>>userMenu)");
		userMenu();
		break;

	case 2:
		logFile(INFO, "Opción 2 de mainMenu seleccionada (>>adminMenu)");
		adminAccessMenu();
		break;

	case 3:
		logFile(END,
				"Opción 3 de mainMenu seleccionada (ejecución finalizada)");
		exit(0);
	}

}


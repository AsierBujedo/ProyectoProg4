/*
 * logger.h
 *
 *  Created on: 19 mar 2022
 *      Author: asier
 */
#include<stdio.h>
#include<stdlib.h>
#ifndef LOGGER_H_
#define LOGGER_H_

typedef enum {INFO = 0, WARN = 1, ERROR = 2} LEVEL;

void openLogger(char name[]);
int closeLogger();
void logFile(LEVEL l, char desc[]);



#endif /* LOGGER_H_ */
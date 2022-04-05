#ifndef HANDLER_PROPERTIES_PROPERTIES_H_
#define HANDLER_PROPERTIES_PROPERTIES_H_

typedef struct {
	int numProp;
	char** propName;
	char** propValue;
} Properties;

void loadProperties(Properties* properties, char name[]);
void createProperties(Properties* properties, char name[]);


#endif /* HANDLER_PROPERTIES_PROPERTIES_H_ */

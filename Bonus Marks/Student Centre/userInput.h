/*******************************************************************************
 * List header files 
*******************************************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/*******************************************************************************
 * List preprocessing directives
*******************************************************************************/
#define FILENAMELENGTH 50

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
int readInt(const char promp[]);
double readDouble(const char promp[]);
char* readString(const char promp[]);
char* readStringWithLimit(const char promp[], int length);
char readkey(const char promp[]);


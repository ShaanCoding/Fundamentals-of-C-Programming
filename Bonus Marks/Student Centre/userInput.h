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
int readInt(const char prompt[]);
double readDouble(const char prompt[]);
char* readString(const char prompt[]);
char* readStringWithLimit(const char prompt[], int length);
char readkey(const char prompt[]);
/*******************************************************************************
 * Lab Number:   1
 * Group Number: 3
 * Members:      Mohammed Shaan Shahroze Khan (13940236) 
*******************************************************************************
*******************************************************************************
 * Compiling instructions:
 *  - Type "make program" in the terminal to compile the program 
*******************************************************************************
*******************************************************************************
 * Run application:
    - Type "./program" in the terminal to run the program
    Example:
        - ./program
*******************************************************************************/


/*******************************************************************************
 * List header files 
*******************************************************************************/
#include <stdio.h> /*printf, scanf*/
#include <stdlib.h> /*atoi*/
#include <string.h> /*strlen*/


/*******************************************************************************
 * List preprocessing directives
*******************************************************************************/
#define WIDTH 65
#define BODYINDENT 4


/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void drawTopLine();
void drawBottomLine();
void drawBody(char content[]);
void drawBodySuccess(char content[]);
void drawTitle(char contentp[]);
void drawMenuTableHeader();
void clear();
void printfError(const char message[]);
void printfSuccess(const char message[]);
void printfPrompt(const char message[]);

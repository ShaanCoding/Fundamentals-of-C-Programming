
/**************************************************************
 * FileName: UserInput.c
 * Description: This file provide a input libary to get user input
 * @Author: Mohammed Shaan Shahroze Khan (13940236) 
 * Change Logs: 
    |Date           |Description                               |
    |2022-10-20     | Upload function to read user input       |
 **************************************************************/


#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif

#ifndef __USERINPUT_H__
#define __USERINPUT_H__
#include "userInput.h"
#endif

/******************************************************************************
 * This method read user input and return the input.
 * inputs:
 *     - prompt: the prompt will be displayed to user.
 * outputs:
 *     - input: the input from user.
 *****************************************************************************/
int readInt(const char prompt[]){
    printfPrompt(prompt);
    int temp;
    scanf(" %d",&temp);
    scanf("%*[^\n]");
    fflush(stdin);
    return temp;
}

/******************************************************************************
 * This method read user input and return the input.
 * inputs:
 *     - prompt: the prompt will be displayed to user.
 * outputs:
 *     - input: the input from user.
 *****************************************************************************/
double readDouble(const char prompt[]){
    printfPrompt(prompt);
    double temp;
    scanf(" %lf",&temp);
    scanf("%*[^\n]");
    fflush(stdin);
    return temp;
}

/******************************************************************************
 * This method read user input and return the input.
 * inputs:
 *     - prompt: the prompt will be displayed to user.
 * outputs:
 *     - input: the input from user.
 *****************************************************************************/
char* readString(const char prompt[]){
    printfPrompt(prompt);
    char* content = (char*) malloc(sizeof(char)*FILENAMELENGTH);
    scanf(" %[^\n\t]",content);
    scanf("%*[^\n]");
    fflush(stdin);
    return content;
}

/******************************************************************************
 * This method read user input and return the input.
 * inputs:
 *     - prompt: the prompt will be displayed to user.
 * outputs:
 *     - input: the input from user.
 *****************************************************************************/
char readkey(const char prompt[]){
    printf("%s ",prompt);
    getchar();
    return getchar();
}

/******************************************************************************
 * This method read user input and return the input.
 * inputs:
 *     - prompt: the prompt will be displayed to user.
 * outputs:
 *     - input: the input from user.
 *****************************************************************************/
char* readStringWithLimit(const char prompt[], int length) {
    char* content = (char*) malloc(sizeof(char)*length);
    printfPrompt(prompt);

    char buffer[255];

    scanf(" %[^\n\t]", buffer);
    scanf("%*[^\n]");
    fflush(stdin);

    if(strlen(buffer) > length) {
        return NULL;
    }

    strcpy(content, buffer);
    return content;
}
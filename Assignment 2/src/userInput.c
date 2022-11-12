
/**************************************************************
 * FileName: UserInput.c
 * Description: This file provide a input libary to get user input
 * @Author: Zhicheng Lin
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
int readInt(const char promp[]){
    printfPrompt(promp);
    int temp;
    scanf(" %d",&temp);
    scanf("%*[^\n]");
    fflush(stdin);
    return temp;
}

double readDouble(const char promp[]){
    printfPrompt(promp);
    double temp;
    scanf(" %lf",&temp);
    scanf("%*[^\n]");
    fflush(stdin);
    return temp;
}
char* readString(const char promp[]){
    printfPrompt(promp);
    char* content = (char*) malloc(sizeof(char)*FILENAMELENGTH);
    scanf(" %[^\n\t]",content);
    scanf("%*[^\n]");
    fflush(stdin);
    return content;
}

char readkey(const char promp[]){
    printf("%s ",promp);
    getchar();
    return getchar();
}

char* readStringWithLimit(const char promp[], int length) {
    char* content = (char*) malloc(sizeof(char)*length);
    printfPrompt(promp);

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


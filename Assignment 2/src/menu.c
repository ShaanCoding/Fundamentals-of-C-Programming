
/**************************************************************
 * FileName: Menu.c
 * Description: This file provide a menu library that create 
 a table.
 * @Author: Zhicheng Lin
 * Change Logs: 
    |Date           |Description                               |
    |2022-10-25     | Upload function to draw a table          |
 **************************************************************/

#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif

/******************************************************************************
 * This method draw the topline of table.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void drawTopLine(){
    int i;
    printf("╔");
    for(i = 0; i< WIDTH - 2; i++){
        printf("═");
    }
    printf("╗\n");
}

/******************************************************************************
 * This method draw the bottomLine of table.
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void drawBottomLine() {
   printf("╚");
   
   int i;
   for (i = 0; i < WIDTH - 2; i++)
   {
      printf("═");
   }

   printf("╝\n");
}

/******************************************************************************
 * This method draw body of table, and align content to center
 * inputs:
 *     - content: the content will be displayed in table.
 * outputs:
 *     - none
 *****************************************************************************/

void drawTitle(char content[]){
    int length = strlen(content);
    int numberOfSpace = (WIDTH-2-length)/2;
    printf("║");
    printf("%*s",numberOfSpace," ");
    printf("%s",content);
    if(length % 2 == 0){
        printf("%*s",numberOfSpace+1," ");
    }
    else{
         printf("%*s",numberOfSpace," ");    
    }
   
    printf("║\n");
}


/******************************************************************************
 * This method draw body of table, and align content to left and set padding to 4
 * inputs:
 *     - content: the content will be displayed in table.
 * outputs:
 *     - none
 *****************************************************************************/
void drawBody(char content[]){
    int length = strlen(content);
    int numberOfSpace = WIDTH - BODYINDENT - length - 2;
    printf("║");
    printf("%*s",BODYINDENT," ");
    printf("%s",content);
    printf("%*s",numberOfSpace," ");
    printf("║\n");
}

void drawBodySuccess(char content[]) {
    int length = strlen(content);
    int numberOfSpace = WIDTH - BODYINDENT - length - 4;
    printf("║");
    printf("%*s",BODYINDENT," ");
    printf("\033[46;37;1m %s \033[0m", content);
    printf("%*s",numberOfSpace," ");
    printf("║\n");
}


/******************************************************************************
 * This method draw table header with title
 * inputs:
 *     - content: the content will be displayed in table.
 * outputs:
 *     - none
 *****************************************************************************/
void drawMenuTableHeader(char title[]){
    printf("\n");
    drawTopLine();
    drawTitle(title);
    drawBottomLine();
}
void clear(){
   system("clear");
}

/******************************************************************************
 * This method will display a error message in a bold and red mode
 * inputs:
 *     - message: the content will be displayed 
 * outputs:
 *     - none
 *****************************************************************************/
void printfError(const char message[]){
  printf("\n\033[41;37;1m %s \033[0m\n",message);
}

/******************************************************************************
 * This method will display a error message in a bold and green mode
 * inputs:
 *     - message: the content will be displayed 
 * outputs:
 *     - none
 *****************************************************************************/
void printfSuccess(const char message[]){
  printf("\n\033[46;37;1m %s \033[0m\n",message);
}

void printfPrompt(const char message[]){
  printf("\n\033[44;37;1m %s \033[0m ",message);
}




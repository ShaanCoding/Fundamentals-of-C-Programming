/*******************************************************************************
 * List header files 
*******************************************************************************/
#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif

#ifndef __USERINPUT_H__
#define __USERINPUT_H__
#include "userInput.h"
#endif

#ifndef __ACCOUNTMANAGEMENT_H__
#define __ACCOUNTMANAGEMENT_H__
#include "accountManagement.h"
#endif

#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__
#include "huffman.h"
#endif

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void appChoice();
void drawAppMenu();
void loginProcess();
void registerProcess();
void drawActionMenu();
void actionChoice(account_t account);
void showProcess(account_t account);
void depositProcess(account_t account);
void withdrawProcess(account_t account);
void encodeStatementProcess(account_t account);
void decodeStatementProcess(account_t account);
void logoutProcess();
void exitApplication();

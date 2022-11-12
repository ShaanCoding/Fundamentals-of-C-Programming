/*******************************************************************************
 * List header files 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __MENU_H__
#define __MENU_H__
#include "menu.h"
#endif

#ifndef __USERINPUT_H__
#define __USERINPUT_H__
#include "userInput.h"
#endif

#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__
#include "encryption.h"
#endif


/*******************************************************************************
 * List preprocessing directives
*******************************************************************************/
#define MAX_CUSTOMER_SIZE 5
#define MAX_NAME_SIZE 20
#define PASSWORD_LENGTH 20
#define TRANSACTION_LENGTH 5000
#define ACCOUNT_LENGTH 100
#define PAYMENT_CODE_LENGTH 4

/*******************************************************************************
 * List External variables
*******************************************************************************/
extern int __debug;
extern int __detail;


/*******************************************************************************
 * List structs
*******************************************************************************/
struct transaction{
    double beforeBalance;
    double amount;
    double balance;
    char type[20];
    struct transaction* next;
};
typedef struct transaction transaction_t;
struct account{
    int clientNum;
    char username[MAX_NAME_SIZE];
    char password[PASSWORD_LENGTH];
    int paymentCode;
    double balance;
    int transactionCount;
    transaction_t * transactions_p;
};
typedef struct account account_t;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void saveAccount();
account_t readAccount(const char filepath[]);
account_t login();
void addAccount();
account_t scanfAccount(int clientNum);
int getNextNum();
void addTransaction(account_t* account, transaction_t* transaction_p);






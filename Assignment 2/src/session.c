
/**************************************************************
 * FileName: Sessionu.c
 * Description: This file is bussiness process of bank management 
    system
 * @Author: Zhicheng Lin
 * Change Logs: 
    |Date           |Description                               |
    |2022-10-25     |Upload bank management function           |
 **************************************************************/


#ifndef __SESSION_H__
#define __SESSION_H__
#include "session.h"
#endif


/******************************************************************************
 * This method draw the login interface
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void drawAppMenu(){
    drawMenuTableHeader("WELCOME TO CPROG BANK Management System");
    drawTopLine();
    drawBody("Please select from the following options:");
    drawBody("1. Login");
    drawBody("2. Register");
    drawBody("3. Exit Application");
    drawBottomLine();
}

/******************************************************************************
 * This method will run the login bussiness process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void loginProcess(){
    clear();
    drawMenuTableHeader("Login Menu");
    drawTopLine();
    drawBody("Please enter a:");
    drawBody("1. Client Number");
    drawBody("2. Client Password");
    drawBottomLine();

    int clientNum = readInt("Client Number >");
    char* password = readString("Password >");

    account_t account = login(clientNum,password);
    
    if(account.clientNum !=0 ){
        printfSuccess("Login Success");
        readkey("\nPress Enter to Go Menu");
        actionChoice(account);
    } else {
        printfError("The Username or Password was Incorrect");
        readkey("\nReturning Back To Main Menu\n");
    }
    free(password);
    password=NULL;
    clear();
    appChoice();
}

/******************************************************************************
 * This method will run the register process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void registerProcess(){
    addAccount();
    readkey("Please Press Enter to back Menu");
    clear();
    appChoice();
}


/******************************************************************************
 * This method will run the choice selection process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void appChoice(){
    drawAppMenu();
    int choice = readInt("User Input >");
    switch(choice){
        case 1:
            loginProcess();
        break;
        case 2:
            registerProcess();
        break;
        case 3:
            exitApplication();
        break;
        default: 
            printfError("User has Entered an Invalid Choice, Please Try Again!");
            readkey("\nPress Any Key To Continue\n");
            appChoice();
        break;
    }
}

/******************************************************************************
 * This method will run the exit selection process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void exitApplication() {
    printfSuccess("Thank you for using our banking system!");
    readkey("\nPress Any Key To Continue\n");
    clear();
}

/******************************************************************************
 * This method draw the main menu of application
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void drawActionMenu(){
    clear();
    drawMenuTableHeader("WELCOME TO CPROG BANK Management System");
    drawTopLine();
    drawBody("Please select from the following options:");
    drawBody("1. Show User Info");
    drawBody("2. Deposit");
    drawBody("3. Withdraw");
    drawBody("4. Compress Bank Statement");
    drawBody("5. Decompress Bank statement");
    drawBody("6. Logout");
    drawBottomLine();
}

/******************************************************************************
 * This method will run the main action selection logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void actionChoice(account_t account){
    drawActionMenu();
    int choice = readInt("User Input >");
    switch(choice){
        case 1: showProcess(account); break;
        case 2: depositProcess(account); break;
        case 3: withdrawProcess(account); break;
        case 4: encodeStatementProcess(account); break;
        case 5: decodeStatementProcess(account); break;
        case 6: logoutProcess(); break;
        default: 
            printfError("Invalid choice!");
            readkey("\nPress Any Key To Continue\n");
            actionChoice(account);
            break;
    }
}

/******************************************************************************
 * This method will show the personal information with a table interface
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void showProcess(account_t account) {
    clear();

    drawMenuTableHeader("User Information");
    drawTopLine();

    /* Concert int to string */
    char clientNum[WIDTH];
    sprintf(clientNum, "%d", account.clientNum);
    char clientNumStr[WIDTH] = "Client Number: ";
    strcat(clientNumStr, clientNum);

    char clientName[WIDTH] = "Client Name: ";
    strcat(clientName, account.username);

    char clientPassword[WIDTH] = "Client Password: ";
    strcat(clientPassword, account.password);

    char clientPaymentCode[WIDTH];
    sprintf(clientPaymentCode, "%d", account.paymentCode);
    char clientPaymentCodeStr[WIDTH] = "Client Payment Code: ";
    strcat(clientPaymentCodeStr, clientPaymentCode);

    char clientBalance[WIDTH];
    sprintf(clientBalance, "$%.2f", account.balance);
    char clientBalanceStr[WIDTH] = "Client Balance: ";
    strcat(clientBalanceStr, clientBalance);
    /*
    char totalTransaction[WIDTH];
    sprintf(totalTransaction, "%d", account.transactionCount);
    char totalTransactionStr[WIDTH] = "Total Transaction: ";
    strcat(totalTransactionStr, totalTransaction);
    */
    drawBody(clientNumStr);
    drawBody(clientName);
    drawBody(clientPassword);
    drawBody(clientPaymentCodeStr);
    drawBody(clientBalanceStr);
    /*drawBody(totalTransactionStr);*/

    transaction_t * temp = account.transactions_p;
    int i =0;
    while(temp!=NULL) {
        char transaction[WIDTH] = "Transaction ";
        char transactionNum[WIDTH];
        sprintf(transactionNum, "%d", i+1);
        strcat(transaction, transactionNum);
        strcat(transaction, ":");
        drawBodySuccess(transaction);

        /* Starting Balance, Deposit Type, Ending Balance*/
        char startingBalance[WIDTH];
        sprintf(startingBalance, "$%.2f", temp->beforeBalance);
        char startingBalanceStr[WIDTH] = "Starting Balance: ";
        strcat(startingBalanceStr, startingBalance);
        drawBody(startingBalanceStr);

        char depositType[WIDTH] = "Deposit Type: ";
        strcat(depositType, temp->type);
        drawBody(depositType);


        /* Check if string is equal */
        if(strcmp(temp->type, "Deposit") == 0) {
            char depositAmount[WIDTH];
            sprintf(depositAmount, "$%.2f", temp->amount);
            char depositAmountStr[WIDTH] = "Deposit Amount: ";
            strcat(depositAmountStr, depositAmount);
            drawBody(depositAmountStr);
        } else {
            char withdrawAmount[WIDTH];
            sprintf(withdrawAmount, "$%.2f", temp->amount);
            char withdrawAmountStr[WIDTH] = "Withdraw Amount: ";
            strcat(withdrawAmountStr, withdrawAmount);
            drawBody(withdrawAmountStr);
        }

        char endingBalance[WIDTH];
        sprintf(endingBalance, "$%.2f", temp->balance);
        char endingBalanceStr[WIDTH] = "Ending Balance: ";
        strcat(endingBalanceStr, endingBalance);
        drawBody(endingBalanceStr);
        temp = temp->next;
        i++;
    }

    drawBottomLine();

    readkey("\nPress Any Key To Continue\n");
    actionChoice(account);
}


/******************************************************************************
 * This method will run deposit bussiness logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void depositProcess(account_t account){
    
    double amount;
    while( (amount=readDouble("Amount: ")) <0 || amount>1000000){
        printfError("Amount must between 0 - 1,000,000");
    }
    char comfirm = readkey("Are you sure to deposit(y for confirm)? ");
    if(comfirm=='Y' || comfirm=='y'){
        transaction_t * transaction_p = (transaction_t *) malloc(1*sizeof(transaction_t));
        if(transaction_p==NULL){
           printfError("Some error, please try again");
           return;
        }
        transaction_p->amount = amount;

        transaction_p->beforeBalance = account.balance;

        account.balance += amount;
        transaction_p->balance = account.balance;

        transaction_p->type[0]='\0';
        strcat(transaction_p->type,"Deposit");
        addTransaction(&account,transaction_p);
        saveAccount(account);
        printfSuccess("Congratulations, You deposit successfully!");
        readkey("\nPress Any Key To Continue\n");
    }else{
        printfPrompt(" You cancel this transaction!");
        readkey("\nPress Any Key To Continue\n");
    }
    actionChoice(account);

}

/******************************************************************************
 * This method will run withdraw bussiness logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void withdrawProcess(account_t account){
    double amount;
    while( (amount=readDouble("Amount: ")) <0 || amount>1000000){
      printfError("Amount must between 0 - 1,000,000");
    }
    if(amount > account.balance){
        printfError("Sorry, you don't have enough money");
        readkey("\nPress Any Key To Continue\n"); 
    } else {
        int paycode = readInt("Please Enter payment code > ");
        if(paycode != account.paymentCode){
            printfError("Code error, Try again!");
            readkey("\nPress Any Key To Continue\n");
            actionChoice(account);
            return;
        }
        char comfirm = readkey("Are you sure to Withdraw(y for confirm)? ");
        if(comfirm=='Y' || comfirm=='y'){
            transaction_t * transaction_p = (transaction_t *) malloc(1*sizeof(transaction_t));
            if(transaction_p==NULL){
                printfError("Some error, please try again");
                return;
            }
            transaction_p->amount = amount;
            transaction_p->beforeBalance = account.balance;
            account.balance -= amount;
            transaction_p->balance = account.balance;
            transaction_p->type[0]='\0';
            strcat(transaction_p->type,"Withdraw");
            addTransaction(&account,transaction_p);
            saveAccount(account);
            printfSuccess("Congratulations, You Withdraw successfully!");
            readkey("\nPress Any Key To Continue\n");
        }else{
            printfPrompt(" You cancel this transaction!");
            readkey("\nPress Any Key To Continue\n");
        }
    }
    actionChoice(account);
    
}

/******************************************************************************
 * This method will run encode statement bussiness logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void encodeStatementProcess(account_t account){
    char filepath[32];
    sprintf(filepath,"accounts/%d.txt",account.clientNum);
    char topath[32];
    sprintf(topath,"data/%d.txt",account.clientNum);
    if(compress(filepath,topath)){
        printfSuccess("Your statement is already encoded in ./data folder");
       
    }
     readkey("Please press Enter to continue");
    actionChoice(account);
}

/******************************************************************************
 * This method will run decode statement bussiness logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void decodeStatementProcess(account_t account){
    char* decodefilename = readString("Please Enter the file you want to decompress(e.g. data/100.txt)");
    char* saveTo = readString("Please enter the Destination filename(e.g. my.txt)");
    decompress(decodefilename,saveTo);
    free(decodefilename);
    free(saveTo);
    decodefilename=NULL;
    saveTo = NULL;
    readkey("Please press Enter to continue");
    actionChoice(account);
    
}

/******************************************************************************
 * This method will run log out bussiness logical process
 * inputs:
 *     - none 
 * outputs:
 *     - none
 *****************************************************************************/
void logoutProcess(){
    printfSuccess("Thank you for using our banking system!");
    readkey("\nPress Any Key To Continue\n");
}

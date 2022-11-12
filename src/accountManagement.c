/**************************************************************
 * FileName: accountManagement.c
 * Description: This is account management libary to add account into
 local file 
 * @Author: Zhicheng Lin
 * Change Logs: 
    |Date           |           Description                    |  
    |2022-10-25     | Create accountManagement.c               |
    |               | Upload scanf account                     |
    |2022-10-26     | Updaload adding account                  |
    |               | Upload read account from file            | 
    |2022-10-27     | Upload gernerator of account number      | 
 **************************************************************/

#include "accountManagement.h"

/******************************************************************************
 * This is the method to scanf user input and add new Account into accouts folder
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/

void addAccount(){
      if(__debug){
            printfPrompt("AccountManagement ->addAccount() start\n");
      }

      int currentNum;
      int nextNum;
      currentNum = getNextNum();
      if(currentNum == -1){
            printfError("Can't add new Account,please try again");
      }
      /* Display the register Process*/
     
      drawMenuTableHeader("Register Menu");
      drawTopLine();
      drawBody("Please enter a:");
      drawBody("1. Client Username");
      drawBody("2. Client Password");
      drawBody("3. Payment Code (4 Digits)");
      drawBottomLine();

      /* Invoke the scanfAccount to read new account data */
      account_t account = scanfAccount(currentNum);
      printfSuccess("Account created!");
      printfSuccess("Please remember your login details!");
      printf("\n\033[44;37;1m Client Number: %d \033[0m \n\n", account.clientNum);
      saveAccount(account);
       FILE* fp = NULL;
      /* Update the next account ID */
      if( (fp = fopen("accounts/nextID.txt","w")) == NULL){
      /*Debug mode*/
      if(__debug){
            printfError("Open accounts/nextId.txt Fail, accountManagement.c->addAccount()\n");
      }
      
      printfError("Some Error Occur, please try again");
      return;
      }     
      nextNum=currentNum+1;
      fprintf(fp,"%d",nextNum);
      fclose(fp); fp=NULL;

      if(__debug){
         printfPrompt("AccountManagement ->addAccount() end\n");
      }
}

int getNextNum(){
     /* Get the current client number for new user*/
      if(__debug){
            printfPrompt("AccountManagement ->getNextNum() start\n");
      }     
     int currentNum =100000;
      FILE * fp = NULL;
      if( (fp = fopen("accounts/nextID.txt","r")) == NULL){
            fp = fopen("accounts/nextID.txt","w");
            if(fp==NULL){
                  if(__debug){
                     printfError("Open accounts/nextId.txt Fail, accountManagement.c->addAccount()\n");
                  }
                  printfError("Some Error Occur, please try again");
                  return -1;
            }else{
                  fprintf(fp,"%d",currentNum);
                  fclose(fp); fp=NULL;          
            }
          
      }else{
            fscanf(fp,"%d",&currentNum);
            fclose(fp); fp=NULL;
      }

      if(__debug){
            printfPrompt("AccountManagement ->getNextNum() end\n");
      }     

      return currentNum;

}

/******************************************************************************
 * This is the method to scanf user input and return an account variable
 * inputs:
 * - client number: int -> this is the new account client number
 * outputs:
 * - account: account_t -> thi is a variable to content the account information
 *****************************************************************************/

account_t scanfAccount(int clientNum){
      if(__debug){
            printfPrompt("AccountManagement ->scanfAccount() start\n");
      }           
      account_t account;
      account.transactionCount = 0;
      account.clientNum = clientNum;  
      account.username[0]='\0';
      account.password[0]='\0';
      account.transactions_p = NULL;
      char* username;

      /* Read username and validate */
      while((username = readStringWithLimit("Username >",MAX_NAME_SIZE)) == NULL){
            printfError("Invalid Username Was Entered, Username Was Too Long");
      }
      
      strcat(account.username,username);
      free(username);
      username = NULL;

      /* Read password and validate */
      char* password;
      while((password = readStringWithLimit("Password >", PASSWORD_LENGTH)) == NULL) {
            printfError("Invalid Password Was Entered, Password Was Too Long");
      }
      strcat(account.password,password);
      free(password);password =NULL;

      /* read payment code (similar cvv) and validate  */   
      while( (account.paymentCode=readInt("Payment Code(4 digits) >")) < 1000 || account.paymentCode > 9999){
            printfError("The payment Only can set 4 digits");
      }

      /* Initialize the balance, and transaction count*/
      account.balance = 0;

      if(__debug){
            printfPrompt("AccountManagement ->scanfAccount() end\n");
      }     
      return account;
}

/******************************************************************************
 * This is the method to save a account into file, filename will be accountClientNumber.txt
      : 100001:txt
 * inputs:
 *     - account: account_t -> this is a account structure data to store in file.
 * outputs:
 *    - None
 *****************************************************************************/
void saveAccount(account_t account){
   if(__debug){
      printfPrompt("AccountManagement ->saveAccount() start\n");
   }          
   FILE *fp = NULL;
   char filepath[32];
   /* Create the file path */
   sprintf(filepath,"accounts/%d.txt",account.clientNum);
      if( (fp = fopen(filepath,"w")) ==NULL ){
            printfError("Open file fail");
            if(__debug){
                  printfError("Open accounts/nextId.txt Fail, accountManagement.c->SaveAccount()\n");
            }
            return;
      }
      /* Encrypted the password */

      long int e, n, tau;
      initializeEncryption(&e, &n, &tau);
      int* encryptedPassword = encrypt(account.password, e, n);

      if(__detail){
            printf("Encrypted password is: ");
            int j;
            for(j = 0; j < strlen(account.password); j++) {
                  printf("%d ", encryptedPassword[j]);
            }
            printf("\n");
      }
      /* Encrypted the payment Code */
      char paymentCodeStr[10];
      sprintf(paymentCodeStr, "%d", account.paymentCode);
      int* encryptedPaymentCode = encrypt(paymentCodeStr, e, n);

      /*Save the all the data into file */
      fprintf(fp,"ClientNum | %d\n",account.clientNum);
      fprintf(fp,"Username | %s\n",account.username);
      fprintf(fp,"Password | ");

      int i; 

      for(i = 0; i < strlen(account.password); i++) {
            fprintf(fp, "%d ", encryptedPassword[i]);
      }
      fprintf(fp, "\n");


      fprintf(fp, "PaymentCode | ");
      for(i = 0; i < strlen(paymentCodeStr); i++) {
            fprintf(fp, "%d ", encryptedPaymentCode[i]);
      }
      fprintf(fp, "\n");


      fprintf(fp,"Balance | %.2lf\n",account.balance);
      fprintf(fp,"Transaction Count | %d\n",account.transactionCount);
     
      transaction_t * temp = account.transactions_p;
      for(i=0;i<account.transactionCount;i++){
         fprintf(fp,"%.2lf | %s | %.2lf | %.2lf\n",\
                     temp->amount,\
                     temp->type,\
                     temp->beforeBalance,\
                     temp->balance);
         temp = temp->next;
      }
 

      /*
      for(i=0;i< account.transactionCount;i++){
            fprintf(fp,"%.2lf | %s | %.2lf | %.2lf\n",account.transactions[i].amount,account.transactions[i].type,\
            account.transactions[i].beforeBalance,account.transactions[i].balance);
      }
      */

    fclose(fp);
    fp=NULL;
    if(__debug){
      printfPrompt("AccountManagement ->saveAccount() end\n");
    }           
}

/******************************************************************************
 * This method will read  account data from filepath.
 * inputs:
 *     - filepath: char[] -> this is used to read a file.
 * outputs:
 *     - account: account_t -> stroe the all data of account.
 *****************************************************************************/
account_t readAccount(const char filepath[]){
      if(__debug){
            printfPrompt("AccountManagement ->readAccount() start\n");
      }       
      account_t account;
      account.transactions_p=NULL;
      FILE *fp = NULL;
      /*Open file stream*/
      if( (fp = fopen(filepath,"r")) ==NULL ){
            printfError("Open file fail");
            return account;
      }

      /*Read data*/
      fscanf(fp,"ClientNum | %d\n",&account.clientNum);
      fscanf(fp,"Username | %[^\n]\n",account.username);

      char password[100];
      password[0]='\0';
      char paymentCode[100];
      paymentCode[0] ='\0';
      fscanf(fp,"Password | %[^\n]\n", password);
      fscanf(fp,"PaymentCode | %[^\n]\n", paymentCode);

      int passwordIntegerArray[PASSWORD_LENGTH];
      int paymentCodeIntegerArray[PAYMENT_CODE_LENGTH];
      convertStringToIntArray(password, passwordIntegerArray);
      convertStringToIntArray(paymentCode, paymentCodeIntegerArray);

      long int e, n, tau;
      initializeEncryption(&e, &n, &tau);

      long d = private_encryption_key(e, n, tau);
      char* decryptedPassword = decrypt(passwordIntegerArray, d, n);
      char* decryptedPaymentCode = decrypt(paymentCodeIntegerArray, d, n);
      strcpy(account.password, decryptedPassword);
      sscanf(decryptedPaymentCode, "%d", &account.paymentCode);
      decryptedPaymentCode[4]='\0';
      if(__detail){
            printf("Private key is: <%ld, %ld>\n", d, n);
            printf("Decrypted Password is %s\n", decryptedPassword);
            printf("Decrypted Payment code is %s\n", decryptedPaymentCode);
       }

      fscanf(fp,"Balance | %lf\n",&account.balance);
      transaction_t* temp = account.transactions_p;
      fscanf(fp,"Transaction Count | %d\n",&(account.transactionCount));
      int i;
      for(i=0;i<account.transactionCount;i++){
          transaction_t* transac_p = (transaction_t *) malloc(1*sizeof(transaction_t));
          fscanf(fp,"%lf | %s | %lf | %lf\n",&(transac_p->amount),\
                                                transac_p->type,\
                                                &(transac_p->beforeBalance), \
                                                &(transac_p->balance)
                );            
         if(account.transactions_p==NULL){   
            account.transactions_p = transac_p;      
            temp = account.transactions_p;
         }else{
             temp->next = transac_p;
             temp = temp->next;
         }
      }
   
      if(__debug){
            printfPrompt("AccountManagement ->readAccount() end\n");
      }       
      
      return account;

}


void addTransaction(account_t* account, transaction_t* transaction_p){
      if(__debug){
            printfPrompt("AccountManagement ->AddTransaction() start\n");
      }            
      transaction_p->next = NULL;
      transaction_t * temp = account->transactions_p;
      if(temp==NULL){
            account->transactions_p = transaction_p;
            (*account).transactionCount=(*account).transactionCount + 1;
            return;
      }
      
      while(temp->next!=NULL){
            temp = temp->next;
      }
     
      temp->next = transaction_p;
      (*account).transactionCount=(*account).transactionCount + 1;
      if(__debug){
            printfPrompt("AccountManagement ->AddTransaction() end\n");
      }      
}


/******************************************************************************
 * this method is used to return a account based on client number and password 
 * inputs:
 *     - clientNum: Int -> account number (login account number)
       - password: char[] -> the account password
 * outputs:
 *     - account: account_t -> stroe the  data of account based on username.
 *****************************************************************************/
account_t login(int clientNum, const char password[]){

      FILE *fp = NULL;
      char filepath[30];
      account_t account;
      account.clientNum = 0;
      sprintf(filepath,"accounts/%d.txt",clientNum);
      
      if( (fp = fopen(filepath,"r")) ==NULL  ){
            if(__debug){
                  printfError("File open failed, accountManagement.c -> login()\n");
            }
            return account;
      }
      fclose(fp);
      account = readAccount(filepath);
      if(strcmp(password,account.password)==0){
            return account;
      }else{
            account_t temp={0};           
            return temp;
      }
}

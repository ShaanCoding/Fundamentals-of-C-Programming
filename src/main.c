/*
===================================================================================
*     Lab Number: 1
===================================================================================
*     Group Nunber: 3
===================================================================================
*     Group Member: 
*        Zhicheng Lin - 13505375
*        Mohammed Khan - 13940236
*        Chloe Kernaleguen	 - 13851581
===================================================================================
*     Compiling instructions:
*        Type "make" at the command line to compile the project
===================================================================================
*     Run application:
*        Type "./program" at the command line to run the project
*        You also can append -t or -d to run application with different mode
*           -t means debug mode On
*           -d means detail mode On
*        Example:
*           ./program -t
*           ./program -d 
*           ./program -t -d 
*           ./program -d -t
*        Notice for the application:
*              1. In the decompression process, we need to enter the 
*                 path of source path and the destination path.
*                 the source path always in data folder, so please type data/xxx.txt
*                 which xxx is your client Number
===================================================================================
*/
#ifndef __SESSION_H__
#define __SESSION_H__
#include "session.h"
#endif


int __debug = 0;
int __detail = 0;


/******************************************************************************
 * This method will onpen the debug mode
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void debugMode(){
   printfSuccess("Debug mode is On");
   printf("Please enter any key to continue ");
   __debug = 1;
   getchar();
}

/******************************************************************************
 * This method will onpen the detail mode
 * inputs:
 *     - none
 * outputs:
 *     - none
 *****************************************************************************/
void detailMode(){
   printfSuccess("Detail mode is On");
   printf("Please enter any key to continue ");
   __detail = 1;
   getchar();
}

/******************************************************************************
 * This method will parse all  command argurements
 * inputs:
 *     - argc : the number of argurements.
 *     - argv[]: a pointer of char array, each element stand for an argurements.
 * outputs:
 *     - none
 *****************************************************************************/
int parseArgurement(int argc, char* argv[]){
   int i;
   for(i=1;i<argc;i++){
      if(strcmp(argv[i],"-t") == 0){
         debugMode();
      }else if(strcmp(argv[i],"-d")==0){
         detailMode();
      }else{
         printfError("Invalid Argurement entering");
         return 0;
      }
     
   }

   return 1;
}

int main(int argc, char* argv[]){
   int correct = parseArgurement(argc,argv);
   if(correct){
      appChoice();   
   }
  
   return 0;
}


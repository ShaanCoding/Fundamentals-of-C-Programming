/*******************************************************************************
 * List header files 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*******************************************************************************
 * List External variables
*******************************************************************************/
extern int __debug;
extern int __detail;

/*******************************************************************************
 * List External variables
*******************************************************************************/



/******************************************************************************
 * Function prototypes
 *****************************************************************************/
int generateTau(long int p, long int q);
long public_encryption_key(const long int p, const long int q, long n, long tau);
long private_encryption_key(long int e, long int n, long int tau);
int *encrypt(char message[], long int e, long int n);
char *decrypt(int *cipheredText, long int d, long int n);
int gcd(const int a, const int b);
long long int modPow(long long int base, int power, int mod);
void initializeEncryption(long int* e_p, long int* n_p, long int* tau_p);
void convertStringToIntArray(char stringToUpdate[], int integerArray[]);

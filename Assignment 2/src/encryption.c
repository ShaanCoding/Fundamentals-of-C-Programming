/**************************************************************
 * FileName: encryption.c | https://www.javatpoint.com/rsa-encryption-algorithm
 * Description: This is encryption lib which contain some function
 to achieve encryption and decryption using RSA algorithm.
 * @Author: Mohammed Khan
 * Change Logs: 
    |Date           |           Description                    |  
    |2022-10-04     | Create the encryption.c                  |
    |               | reading more on RSA                      |
    |Date           |           Description                    |  
    |2022-10-05     | Reformatted additional types after       |
    |               | reading more on RSA                      |
    |Date           |           Description                    |  
    |2022-10-11     | Implemented RSA encrypt + decrypt on     |
    |               | integers using longs                     |
    |Date           |           Description                    |  
    |2022-10-11     | Fixed segfault issue due to improperly   |
    |               | allocating memory                        |
 **************************************************************/

#include "encryption.h"

/******************************************************************************
 * This is the main function and contains a demo of encryption
 * inputs:
 * - void
 * outputs:
 * - void
 *****************************************************************************/

/*
int main() {
   long int p = 37;
   long int q = 31;

   long int n = p * q;
   long int tau = generateTau(p, q);

   printf("N = %ld\n", n);
   printf("Tau = %ld\n", tau);

   long int e = public_encryption_key(p, q, n, tau);
   printf("Public key is <%ld, %ld>\n", e, n);

   char message[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
   int i;
   for(i = 0; i < strlen(message); i++) {
      printf("%c", message[i]);
   }
   printf("\n");
   
   int* encrypted_string = encrypt(message, e, n);
   for(i = 0; i < 27; i++) {
      printf("%d ", encrypted_string[i]);
   }
   printf("\n");
 
   long d = private_encryption_key(e, n, tau);
   printf("Private key is: <%ld, %ld>\n", d, n);

   char* decrypted_string = decrypt(encrypted_string, d, n);
   printf("%s\n", decrypted_string);

   free(encrypted_string);
   free(decrypted_string);

   return 0;
}
*/

/******************************************************************************
 * This function takes in A & B and returns the GCD (Greatest common denominator)
 * of both A & B
 * inputs:
 * - int a, int b
 * outputs:
 * - int GCD value
 *****************************************************************************/
int gcd(const int a, const int b) {
   int i, gcd;

   if(a == 0 || b == 0) {
      return 0;
   }

   /* calculate smallest */
   int smallest = b;
   if(b > a) {
      smallest = a;
   }

   for(i = 1; i <= smallest; i++) {
      int a_mod = a % i;
      int b_mod = b % i;

      if((a_mod == 0) && (b_mod == 0)) {
         gcd = i;
      }
   }

   if(__detail){
      printf("Calculating GCD: A: %d, B: %d, GCD: %d\n", a, b, gcd);
   }
   return gcd;
}

long long int modPow(long long int base, int power, int mod) {
   int i;
   long long int result = 1;

   for(i = 0; i < power; i++) {
      result = (result * base) % mod;
   }

   if(__detail)
   {
   printf("Modulus Power Calculator. Base: %lld, Power: %d, Modulus: %d\n", base, power, mod);
   }

   return result;
}

/******************************************************************************
 * This function takes in variables p & q and calculates tau
 * Tau is a variable used in the creation and calculation of private & public keys
 * in RSA
 * this program.
 * inputs:
 * - long int
 * outputs:
 * - int
 *****************************************************************************/
int generateTau(long int p, long int q) {
   long int tau = (p - 1) * (q - 1);
   if(__detail){
      printf("Tau Calculator. P: %ld, Q: %ld, TAU: %ld\n", p, q, tau);
   }
   return tau;
}

/******************************************************************************
 * This function generates the public encryption key
 * this program.
 * inputs:
 * - p & q (random long prime numbers)
 * outputs:
 * - public encryption key
 *****************************************************************************/
long public_encryption_key(const long int p, const long int q, long n, long tau) {
   /* Calculate e < n such that n is relatively prime to tau */
   /* Means e and tau have no common factor except 1 */
   /* Choose such that 1 < e < tau, e is prime to tau */
   int i, e = 0;
   for(i = 2; i < tau; i++) {
      if(gcd(i, tau) == 1) {
         e = i;
         break;
      }
   }

   if(__detail){
      printf("Public Encryption Key Calculator. P: %ld, Q: %ld, N: %ld, TAU: %ld, E: %d\n", p, q, n, tau, e);
   }
   return e;
}

/******************************************************************************
 * This function generates the private encryption key
 * this program.
 * inputs:
 * - p & q (random long prime numbers)
 * outputs:
 * - private encryption key
 *****************************************************************************/
long private_encryption_key(long int e, long int n, long int tau) {
   /* Now determine private key */
   /* D*e % tau = 1 */
   int i, d;
   for(i = 1; i <= n; i++) {
      if(i * e % tau == 1) {
         d = i;
      }
   }

   if(__detail){
      printf("Private Encryption Key Calculator. E: %ld, N: %ld, TAU: %ld, D: %d\n", e, n, tau, d);
   }


   return d;
}

/******************************************************************************
 * This function takes in the publicKey and encrypts the text into a cipher so that
 * It can be securely transmitted & not decoded
 * inputs:
 * - publicKey
 * outputs:
 * - encryptedText
 *****************************************************************************/
int* encrypt(char message[], const long int e, const long int n) {
   int i, array_length = strlen(message);
   int* returnString = malloc(array_length * sizeof(int));

   for(i = 0; i < array_length; i++) {
      int messageChar = message[i];
      returnString[i] = (long long int) pow(messageChar, e) % n;
   }

   return returnString;
}

/******************************************************************************
 * This function takes in the privateKey and decrypts the text into plane text
 * The privateKey should not be shared with anyone
 * inputs:
 * - privateKey
 * outputs:
 * - decryptedText
 *****************************************************************************/
char* decrypt(int* cipheredText, long int d, long int n) {
   /* Decrypted is m = c^d % n */
   int i;

   char* returnString = malloc(27 * sizeof(char) + 1);

   for(i = 0; i < 27; i++) {
      int messageChar = cipheredText[i];
      char decodedChar = modPow(messageChar, d, n);
      returnString[i] = decodedChar;
   }
   return returnString; 
}

/* Need to convert string to byte array and then decode later */
/* Maybe load as 73 82 19 20 24 -> Decode to APPLE or something */

void initializeEncryption(long int* e_p, long int* n_p, long int* tau_p) {
    long int p = 37;
    long int q = 31;

    long int n = p * q;
    long int tau = generateTau(p, q);
    long int e = public_encryption_key(p, q, n, tau);
    
    if(__detail){
      printf("N = %ld\n", n);
      printf("Tau = %ld\n", tau);
      printf("Public key is <%ld, %ld>\n", e, n);
    }
    *e_p = e;
    *n_p = n;
    *tau_p = tau;
}

void convertStringToIntArray(char stringToUpdate[], int integerArray[]) {
   int length = 0, c, bytesread;

   char* input1 = stringToUpdate;

   while(sscanf(input1, "%d%n", &c, &bytesread) > 0) {
      integerArray[length++] = c;
      input1 += bytesread;
   }
}

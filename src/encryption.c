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
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/******************************************************************************
 * List preprocessing directives - you may define your own.
 *****************************************************************************/

/******************************************************************************
 * Function prototypes
 *****************************************************************************/
int generateTau(long int p, long int q);
long public_encryption_key(const long int p, const long int q, long n, long tau);
long private_encryption_key(long int e, long int n, long int tau);
long int encrypt(int message, long int e, long int n);
long int decrypt(int cipheredText, long int d, long int n);
int gcd(const int a, const int b);
int testGCD(void);
long long int modPow(long long int base, int power, int mod);

/******************************************************************************
 * This is the main function and contains a demo of encryption
 * inputs:
 * - void
 * outputs:
 * - void
 *****************************************************************************/
void main() {
   /* Need two random large prime numbers */
   long int p = 7;
   long int q = 11;

   long int n = p * q;
   long int tau = generateTau(p, q);

   printf("N = %ld\n", n);
   printf("Tau = %ld\n", tau);

   long int e = public_encryption_key(p, q, n, tau);
   printf("Public key is <%ld, %ld>\n", e, n);

   // printf("GCD Unit Tests: %d\n", testGCD());

   int message = 9;
   // char message[] = "Hello World!";
   int cipheredText = encrypt(message, e, n);
   printf("Message is: %d\n", cipheredText); 
 
   long d = private_encryption_key(e, n, tau);
   printf("Private key is: <%ld, %ld>\n", d, n);

   long decryptedText = decrypt(cipheredText, d, n);
   printf("Decrypted Text is: %ld\n", decryptedText);
}

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

   return gcd;
}

/* Temporary to remove later tests values copied from stackoverflow */
int testGCD() {
   if(gcd(42, 56) != 14) {
      printf("1\n");
      return 0;
   }

   if(gcd(461952, 116298) != 18) {
      printf("2\n");
      return 0;
   }

   if(gcd(7966496, 314080416) != 32) {
      printf("3\n");
      return 0;
   }

   if(gcd(24826148, 45296490) != 526) {
      printf("4\n");
      return 0;
   }

   if(gcd(12, 0) != 0) {
      printf("5\n");
      return 0;
   }

   if(gcd(0, 0) != 0) {
      printf("6\n");
      return 0;
   }

   if(gcd(0, 9) != 0) {
      printf("7\n");
      return 0;
   }

   return 1;
}

long long int modPow(long long int base, int power, int mod) {
   int i;
   long long int result = 1;

   for(i = 0; i < power; i++) {
      result = (result * base) % mod;
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
   return (p - 1) * (q - 1);
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
long int encrypt(int message, long int e, long int n) {
   return (int) pow(message, e) % n;
}

/******************************************************************************
 * This function takes in the privateKey and decrypts the text into plane text
 * The privateKey should not be shared with anyone
 * inputs:
 * - privateKey
 * outputs:
 * - decryptedText
 *****************************************************************************/
long int decrypt(int cipheredText, long int d, long int n) {
   /* Decrypted is m = c^d % n */
   return modPow(cipheredText, d, n);
}

/* Need to convert string to byte array and then decode later */
/* Maybe load as 73 82 19 20 24 -> Decode to APPLE or something */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modular_exponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = (result * base) % mod;
        }
        exp = exp >> 1;  
        base = (base * base) % mod;
    }
    return result;
}

int modular_inverse(int e, int phi) {
    int d = 1;
    while ((e * d) % phi != 1) {
        d++;
    }
    return d;
}

int main() {
    int p, q, n, phi, e, d;
    char plaintext[256], decrypted[256];
    int encrypted[256];
    printf("Enter two prime numbers (p and q, ensuring n is large enough): ");
    scanf("%d %d", &p, &q);
 
    n = p * q;
    phi = (p - 1) * (q - 1);

    if (n < 128) {
        printf("Error: n = %d is too small. Choose larger primes.\n", n);
        return 1;
    }

    printf("Enter a value for e (1 < e < %d, and gcd(e, %d) = 1): ", phi, phi);
    scanf("%d", &e);
    if (gcd(e, phi) != 1) {
        printf("Invalid e. It must be coprime with %d.\n", phi);
        return 1;
    }


    d = modular_inverse(e, phi);

    printf("Public Key: (e=%d, n=%d)\n", e, n);
    printf("Private Key: (d=%d, n=%d)\n", d, n);
    printf("Enter the plaintext message to encrypt: ");
    getchar(); 
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Encrypted message (numeric values): ");
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        int ascii_value = (int)plaintext[i];  
        encrypted[i] = modular_exponentiation(ascii_value, e, n);  
        printf("%d ", encrypted[i]);  
    }
    printf("\n");
    printf("Decrypted message: ");
    for (int i = 0; i < length; i++) {
        int decrypted_value = modular_exponentiation(encrypted[i], d, n);  
        decrypted[i] = (char)decrypted_value;  
        printf("%c", decrypted[i]);  
    }
    decrypted[length] = '\0';  
    printf("\n");

    return 0;
}


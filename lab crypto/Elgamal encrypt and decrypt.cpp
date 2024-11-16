#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int multiplicative_inverse(int a, int p) {
    for (int i = 1; i < p; i++) {
        if ((a * i) % p == 1) {
            return i;
        }
    }
    return -1;  
}

int main() {
    int p, g, x, y, k, m, c1, c2, decrypted_message;
    printf("Enter a large prime number (p): ");
    scanf("%d", &p);
    printf("Enter a primitive root modulo %d (g): ", p);
    scanf("%d", &g);
    printf("Enter a private key (x, 1 <= x < %d): ", p);
    scanf("%d", &x);

    y = modular_exponentiation(g, x, p);  
    printf("Public Key: (p=%d, g=%d, y=%d)\n", p, g, y);
    printf("Enter the message to encrypt (m): ");
    scanf("%d", &m);
    printf("Enter a random integer (k, 1 <= k < %d): ", p - 1);
    scanf("%d", &k);

    c1 = modular_exponentiation(g, k, p);           
    c2 = (m * modular_exponentiation(y, k, p)) % p;  
    printf("Encrypted Message: (c1=%d, c2=%d)\n", c1, c2);
    int c1_inverse = modular_exponentiation(c1, p - 1 - x, p);  
    decrypted_message = (c2 * c1_inverse) % p;                  
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}


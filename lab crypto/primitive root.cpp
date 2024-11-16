#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int power_mod(int base, int exp, int mod) {
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
 
int is_primitive_root(int g, int n) {
    int phi = 0;  
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            phi++;
        }
    }
     
    int found[phi];  
    for (int i = 0; i < phi; i++) {
        found[i] = 0;
    }
    for (int power = 1; power <= phi; power++) {
        int mod_result = power_mod(g, power, n);
        if (found[mod_result % phi]) {
            return 0;  
        }
        found[mod_result % phi] = 1;
    }
    return 1;  
}

void find_primitive_roots(int n) {
    int found = 0;
    for (int g = 2; g < n; g++) {  
        if (is_primitive_root(g, n)) {
            printf("%d ", g);
            found = 1;
        }
    }
    if (!found) {
        printf("No primitive roots exist for %d.\n", n);
    }
}

int main() {
    int n;
    printf("Enter a number to find its primitive roots: ");
    scanf("%d", &n);

    printf("Primitive roots of %d are: ", n);
    find_primitive_roots(n);

    return 0;
}


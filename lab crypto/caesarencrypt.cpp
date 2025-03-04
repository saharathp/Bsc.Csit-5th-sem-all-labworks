#include <stdio.h>
#include <string.h>

int main() {
    int i, key;
    char s[1000], c;

    printf("\nOutput by Sahara Thapa.\n\n");
    printf("Enter a plaintext to encrypt:\n");
    fgets(s, sizeof(s), stdin);
    printf("Enter key:\n");
    scanf("%d", &key);

    int n = strlen(s);
    for (i = 0; i < n; i++) {
        c = s[i];
        if (c >= 'a' && c <= 'z') {
            c = c + key;
            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            s[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + key;
            if (c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            s[i] = c;
        }
    }

    printf("Encrypted message: %s\n", s);

    return 0;
}

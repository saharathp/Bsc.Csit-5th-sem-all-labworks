#include <stdio.h>
 
void createVigenereTable(char table[26][26]) {
    
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            table[i][j] = 'A' + (i + j) % 26;
        }
    }

     
    printf("Vigenère Table:\n");
    printf("   ");
    for (int i = 0; i < 26; ++i) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for (int i = 0; i < 26; ++i) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 26; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char table[26][26];

    createVigenereTable(table);

    return 0;
}


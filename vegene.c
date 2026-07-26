#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int choice, i, j, count;
    int textLen, keyLen;

    for(count = 1; count <= 3; count++) {

        printf("\n===== Vigenere Cipher (%d) =====\n", count);
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // clear buffer

        printf("Enter message: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        printf("Enter key: ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        textLen = strlen(text);
        keyLen = strlen(key);

        if(keyLen == 0) {
            printf("Key cannot be empty!\n");
            continue;
        }

        j = 0;

        for(i = 0; i < textLen; i++) {

            if(isalpha(text[i])) {

                int keyShift = toupper(key[j % keyLen]) - 'A';

                if(choice == 1) {  // Encryption
                    int p = tolower(text[i]) - 'a';
                    text[i] = ((p + keyShift) % 26) + 'A';  // OUTPUT UPPERCASE
                }
                else if(choice == 2) {  // Decryption
                    int c = toupper(text[i]) - 'A';
                    text[i] = ((c - keyShift + 26) % 26) + 'a';  // OUTPUT lowercase
                }

                j++;
            }
        }

        if(choice == 1)
            printf("Cipher Text : %s\n", text);
        else if(choice == 2)
            printf("Plain Text : %s\n", text);
        else
            printf("Invalid choice!\n");
    }

    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 3");
    printf("\nRoll no = 32(B)\n");

    return 0;
}

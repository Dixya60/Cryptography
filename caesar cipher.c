#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], ch;
    int key, choice, i, count;

    for(count = 1; count <= 3; count++) {
        printf("\n===== Caesar Cipher (%d) =====\n", count);
        printf("1. Encryption\n2. Decryption\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        printf("Enter text: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0'; // remove newline

        printf("Enter key: ");
        scanf("%d", &key);
        getchar(); // clear buffer

        for(i = 0; text[i] != '\0'; i++) {
            if(choice == 1) { // Encryption
                ch = toupper(text[i]);
                if(ch >= 'A' && ch <= 'Z')
                    ch = ((ch - 'A' + key) % 26) + 'A';
                text[i] = ch; // store uppercase
            }
            else if(choice == 2) { // Decryption
                ch = toupper(text[i]);
                if(ch >= 'A' && ch <= 'Z')
                    ch = ((ch - 'A' - key + 26) % 26) + 'A';
                text[i] = tolower(ch); // store lowercase for plaintext
            }
        }

        if(choice == 1)
            printf("Cipher Text: %s\n", text);
        else if(choice == 2)
            printf("Plain Text: %s\n", text);
        else
            printf("Invalid choice!\n");
    }
    printf("\nName = Dikshya Gautam\nLab no = 2\nRollno = 32(B)");

    return 0;
}

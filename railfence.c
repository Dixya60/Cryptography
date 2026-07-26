#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptRailFence(char text[], int key) {
    int len = strlen(text);
    char rail[key][len];
    int i, j;

    // Initialize rail matrix
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Fill in zig-zag
    int dir = 0; // 0 = down, 1 = up
    int row = 0;
    for(j = 0; j < len; j++) {
        rail[row][j] = toupper(text[j]);  // Cipher text in uppercase

        if(row == 0) dir = 0;
        if(row == key-1) dir = 1;

        if(dir == 0) row++;
        else row--;
    }

    // Print cipher text
    printf("Cipher Text: ");
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            if(rail[i][j] != '\n')
                printf("%c", rail[i][j]);
    printf("\n");
}

void decryptRailFence(char text[], int key) {
    int len = strlen(text);
    char rail[key][len];
    int i, j;

    // Initialize rail matrix
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Mark positions
    int dir = 0;
    int row = 0;
    for(j = 0; j < len; j++) {
        rail[row][j] = '*';

        if(row == 0) dir = 0;
        if(row == key-1) dir = 1;

        if(dir == 0) row++;
        else row--;
    }

    // Fill the rail matrix with cipher text
    int index = 0;
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            if(rail[i][j] == '*' && index < len)
                rail[i][j] = toupper(text[index++]); // store uppercase

    // Read zig-zag to get plaintext
    dir = 0;
    row = 0;
    printf("Plain Text: ");
    for(j = 0; j < len; j++) {
        printf("%c", tolower(rail[row][j])); // output in lowercase

        if(row == 0) dir = 0;
        if(row == key-1) dir = 1;

        if(dir == 0) row++;
        else row--;
    }
    printf("\n");
}

int main() {
    char text[100];
    int choice, key, count;

    for(count = 1; count <= 3; count++) {
        printf("\n===== Rail Fence Cipher (%d) =====\n", count);
        printf("1. Encryption\n2. Decryption\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        printf("Enter text: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0'; // remove newline

        printf("Enter key (number of rails): ");
        scanf("%d", &key);
        getchar(); // clear buffer

        if(choice == 1)
            encryptRailFence(text, key);
        else if(choice == 2)
            decryptRailFence(text, key);
        else
            printf("Invalid choice!\n");
    }
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 5");
    printf("\nRoll no = 32(B)");

    return 0;
}

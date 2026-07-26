#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compute GCD
long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular multiplicative inverse
long long modInverse(long long e, long long phi) {
    long long d = 1;
    while((e * d) % phi != 1)
        d++;
    return d;
}

// Fast modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while(exp > 0) {
        if(exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    long long p, q, n, phi, e, d, i, count;
    char message[100];

    for(count = 1; count <= 3; count++) {
        printf("\n=== RSA Encryption/Decryption (%lld) ===\n", count);

        printf("Enter small prime number p: ");
        scanf("%lld", &p);
        printf("Enter small prime number q: ");
        scanf("%lld", &q);

        n = p * q;
        phi = (p - 1) * (q - 1);

        printf("Enter public key e (1 < e < %lld, coprime with %lld): ", phi, phi);
        scanf("%lld", &e);
        if(gcd(e, phi) != 1) {
            printf("Invalid e! Must be coprime with %lld\n", phi);
            count--;
            continue;
        }

        d = modInverse(e, phi);

        getchar(); // clear newline
        printf("Enter message (letters only): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // remove newline

        // Encrypt
        printf("Encrypted message: ");
        long long cipher[100];
        for(i = 0; message[i] != '\0'; i++) {
            if(isalpha(message[i])) {
                long long m = toupper(message[i]) - 'A'; // convert to 0-25
                cipher[i] = modExp(m, e, n);
                printf("%c", (char)((cipher[i] % 26) + 'A')); // ciphertext uppercase
            } else {
                cipher[i] = message[i]; // keep non-letters unchanged
                printf("%c", message[i]);
            }
        }
        printf("\n");

        // Decrypt
        printf("Decrypted message: ");
        for(i = 0; message[i] != '\0'; i++) {
            if(isalpha(message[i])) {
                long long m = modExp(cipher[i], d, n);
                printf("%c", (char)(m + 'a')); // plaintext lowercase
            } else {
                printf("%c", message[i]);
            }
        }
        printf("\n");
    }

    printf("\nName = Dikshya Gautam\nLab no = 14\nRoll no = 32(B)\n");

    return 0;
}

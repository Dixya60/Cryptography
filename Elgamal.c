#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Letter-friendly ElGamal for lab (mod 26)
int main() {
    int count;
    char msg[100];
    int len, i;
    long long p, g, a, A;
    int k; // Bob's random number

    for(count = 1; count <= 3; count++) {
        printf("\n=== ElGamal Cryptosystem (%d) ===\n", count);

        // Input prime p and primitive root g
        printf("Enter prime number p (>=26): ");
        scanf("%lld", &p);
        printf("Enter primitive root g: ");
        scanf("%lld", &g);

        // Alice's private key
        printf("Enter Alice's private key a: ");
        scanf("%lld", &a);

        // Compute Alice's public key
        A = modExp(g, a, p);
        printf("Alice's public key A = %lld\n", A);

        getchar(); // clear newline
        printf("Enter message to send (letters only): ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';
        len = strlen(msg);

        // Convert message to numbers 0..25
        int M[100];
        for(i = 0; i < len; i++)
            M[i] = tolower(msg[i]) - 'a';

        // Bob's random number
        printf("Enter Bob's random number k (1 < k < %lld): ", p);
        scanf("%d", &k);

        // Encryption (mod 26 for letters)
        int C[100];
        printf("Ciphertext: ");
        for(i = 0; i < len; i++) {
            C[i] = (M[i] + k) % 26;  // simplified lab version
            printf("%c", C[i] + 'A');
        }
        printf("\n");

        // Decryption
        printf("Decrypted message: ");
        for(i = 0; i < len; i++) {
            int plain = (C[i] - k + 26) % 26;
            printf("%c", plain + 'a');
        }
        printf("\n");
    }

    printf("\nName = Dikshya Gautam\nLab no = 15\nRoll no = 32(B)\n");
    return 0;
}

#include <stdio.h>

int main() {
    int p, g;      // prime number and primitive root
    int a, b;      // private keys of Alice and Bob
    int A, B;      // public keys of Alice and Bob
    int secretA, secretB;
    int count;
    int i;

    for(count = 1; count <= 3; count++) {
        printf("\n=== Diffie-Hellman Key Exchange %d ===\n", count);

        // Step 1: Input prime number and primitive root
        printf("Enter a prime number (p): ");
        scanf("%d", &p);
        printf("Enter primitive root (g): ");
        scanf("%d", &g);

        // Step 2: Input private keys
        printf("Enter private key for Alice (a): ");
        scanf("%d", &a);
        printf("Enter private key for Bob (b): ");
        scanf("%d", &b);

        // Step 3: Compute public keys
        A = 1;
        for(i = 0; i < a; i++)
            A = (A * g) % p;

        B = 1;
        for( i = 0; i < b; i++)
            B = (B * g) % p;

        printf("Alice's public key (A) = %d\n", A);
        printf("Bob's public key (B) = %d\n", B);

        // Step 4: Compute shared secret key
        secretA = 1;
        for(i = 0; i < a; i++)
            secretA = (secretA * B) % p;

        secretB = 1;
        for( i = 0; i < b; i++)
            secretB = (secretB * A) % p;

        printf("Shared secret key computed by Alice = %d\n", secretA);
        printf("Shared secret key computed by Bob   = %d\n", secretB);
    }
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 13");
    printf("\nRoll no = 32(B)");

    return 0;
}

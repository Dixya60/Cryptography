#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Modular exponentiation
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

// Modular inverse (for prime p)
long long modInverse(long long a, long long p) {
    long long i;
    for(i = 1; i < p; i++) {
        if((a * i) % p == 1)
            return i;
    }
    return 1; // fallback
}

int main() {
    long long p, g;       // prime and primitive root
    long long a, A;       // Alice's private and public key
    long long k;          // Bob's random number
    int count;
    char msg[100];
    
    for(count = 1; count <= 3; count++) {
        printf("\n=== ElGamal Cryptosystem (%d) ===\n", count);

        printf("Enter prime number p: ");
        scanf("%lld", &p);
        printf("Enter primitive root g: ");
        scanf("%lld", &g);

        printf("Enter Alice's private key a: ");
        scanf("%lld", &a);

        // Compute Alice's public key
        A = modExp(g, a, p);
        printf("Alice's public key A = %lld\n", A);

        getchar(); // clear newline
        printf("Enter message to send (letters only): ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';

        // Convert message to lowercase numbers (a=0..z=25)
        int len = strlen(msg);
        int M[100];
        int i;
        for(i = 0; i < len; i++)
            M[i] = tolower(msg[i]) - 'a';

        printf("Enter Bob's random number k (1 < k < %lld): ", p);
        scanf("%lld", &k);

        // Encryption
        long long c1 = modExp(g, k, p);
        long long c2[100];
        printf("Ciphertext: ");
        for(i = 0; i < len; i++) {
            c2[i] = (M[i] * modExp(A, k, p)) % p;
            // Convert ciphertext number to letter (mod 26)
            printf("%c", (char)((c2[i] % 26) + 'A'));
        }
        printf("\n");

        // Decryption
        long long s = modExp(c1, a, p);      // shared secret
        long long s_inv = modInverse(s, p);  // modular inverse
        printf("Decrypted message: ");
        for(i = 0; i < len; i++) {
            int plain = (int)((c2[i] * s_inv) % p);
            // Convert number back to lowercase letter
            printf("%c", (char)(plain + 'a'));
        }
        printf("\n");
    }

    printf("\nName = Dikshya Gautam\nLab no = 15\nRoll no = 32(B)\n");
    return 0;
}

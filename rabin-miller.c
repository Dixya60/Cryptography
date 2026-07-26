#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation: (a^b) % mod
long long modPow(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;

    while(b > 0) {
        if(b % 2 == 1)
            result = (result * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

// Rabin-Miller test for n, k iterations
int isPrime(long long n, int k) {
    if(n <= 1 || n == 4) return 0;
    if(n <= 3) return 1;

    // Find d such that n-1 = d * 2^r
    long long d = n - 1;
    int r = 0;
    while(d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    int i,j;
    for( i= 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4); // random a in [2, n-2]
        long long x = modPow(a, d, n);

        if(x == 1 || x == n - 1)
            continue;

        int continueLoop = 0;
        for(j = 0; j < r - 1; j++) {
            x = (x * x) % n;
            if(x == n - 1) {
                continueLoop = 1;
                break;
            }
        }
        if(continueLoop)
            continue;

        return 0; // composite
    }
    return 1; // probably prime
}

int main() {
    srand(time(0));
    long long n;
    int count;
    int k = 5; // number of iterations for accuracy

    for(count = 1; count <= 3; count++) {
        printf("\n=== Rabin-Miller Primality Check %d ===\n", count);
        printf("Enter a number: ");
        scanf("%lld", &n);

        if(isPrime(n, k))
            printf("%lld is probably prime.\n", n);
        else
            printf("%lld is composite.\n", n);
    }
     printf("\nName = Dikshya Gautam");
    printf("\nLab no = 12");
    printf("\nRoll no = 32(B)");


    return 0;
}

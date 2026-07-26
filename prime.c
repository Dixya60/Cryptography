#include <stdio.h>

int main() {
    int num, i, count;

    for(count = 1; count <= 3; count++) {
        printf("\n=== Prime Check %d ===\n", count);
        printf("Enter a number: ");
        scanf("%d", &num);

        if(num <= 1) {
            printf("%d is not a prime number.\n", num);
            continue;
        }

        int isPrime = 1; // assume prime

        // Loop from 2 to sqrt(num)
        for(i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                isPrime = 0; // not prime
                break;
            }
        }

        if(isPrime)
            printf("%d is a prime number.\n", num);
        else
            printf("%d is not a prime number.\n", num);
    }
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 11");
    printf("\nRoll no = 32(B)");


    return 0;
}

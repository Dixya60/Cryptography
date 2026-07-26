#include <stdio.h>

// Function to compute gcd
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute totient
int totient(int n) {
    int count = 0;
    int i;
    for(i = 1; i < n; i++) {
        if(gcd(n, i) == 1)
            count++;
    }
    return count;
}

int main() {
    int num, count;

    for(count = 1; count <= 3; count++) {
        printf("\n=== Totient Calculation %d ===\n", count);
        printf("Enter a number: ");
        scanf("%d", &num);

        printf("Euler's Totient phi(%d) = %d\n", num, totient(num));

    }
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 7");
    printf("\nRoll no = 32(B)");


    return 0;
}

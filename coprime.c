#include <stdio.h>

// Function to compute GCD
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, count;

    for(count = 1; count <= 3; count++) {
        printf("\n=== Coprime Check %d ===\n", count);

        printf("Enter first number: ");
        scanf("%d", &num1);

        printf("Enter second number: ");
        scanf("%d", &num2);

        if(gcd(num1, num2) == 1)
            printf("%d and %d are coprime.\n", num1, num2);
        else
            printf("%d and %d are not coprime.\n", num1, num2);
    }
    
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 9");
    printf("\nRoll no = 32(B)");


    return 0;
}

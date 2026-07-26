#include <stdio.h>

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
        printf("\n=== GCD Calculation %d ===\n", count);
        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
    }
    
    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 6");
    printf("\nRoll no = 32(B)");

    return 0;
}

#include <stdio.h>

int main() {
    int a, m, x, count;

    for(count = 1; count <= 3; count++) {
        printf("\n=== Multiplicative Inverse Calculation %d ===\n", count);

        printf("Enter integer a: ");
        scanf("%d", &a);

        printf("Enter modulo m: ");
        scanf("%d", &m);

        int inverse_found = 0;

        // Try all possible values from 1 to m-1
        for(x = 1; x < m; x++) {
            if((a * x) % m == 1) {
                printf("Multiplicative inverse of %d modulo %d is: %d\n", a, m, x);
                inverse_found = 1;
                break;
            }
        }

        if(!inverse_found)
            printf("Multiplicative inverse does not exist for %d modulo %d.\n", a, m);
    }
     printf("\nName = Dikshya Gautam");
    printf("\nLab no = 8");
    printf("\nRoll no = 32(B)");


    return 0;
}

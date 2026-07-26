#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp;
    int i;
    fp = fopen("malicious_demo.txt", "w");

    if(fp == NULL) {
        printf("File cannot be opened.\n");
        return 1;
    }
    
    printf("Writing to file....\n");
    
    for(i = 0; i < 1000; i++) {
        fprintf(fp, "This is line number %d\n", i);
    }


    fclose(fp);
    
    printf("\nName = Dikshya Gautam\nLab No. = 16\nRoll No = 32(B)\n");
    return 0;
    
}

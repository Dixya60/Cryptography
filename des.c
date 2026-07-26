#include <stdio.h>
#include <stdint.h>

// Initial Permutation (IP) table
int IP[64] = {
58,50,42,34,26,18,10,2,
60,52,44,36,28,20,12,4,
62,54,46,38,30,22,14,6,
64,56,48,40,32,24,16,8,
57,49,41,33,25,17,9,1,
59,51,43,35,27,19,11,3,
61,53,45,37,29,21,13,5,
63,55,47,39,31,23,15,7
};

// Final Permutation (FP) table
int FP[64] = {
40,8,48,16,56,24,64,32,
39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,
37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,
33,1,41,9,49,17,57,25
};

// Simple 4x16 S-box (S1 only, for demo)
int S1[4][16] = {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

// Permute 64-bit input using table
uint64_t permute64(uint64_t input, int *table, int n){
    uint64_t out=0;
    int i;
    for(i=0;i<n;i++){
        out <<=1;
        out |= (input >> (64 - table[i])) & 1;
    }
    return out;
}

// Simple Feistel function: XOR with key + S-box
uint32_t f(uint32_t R, uint32_t K){
    uint32_t val = R ^ K;        // XOR with 32-bit key
    // Apply S-box to lower 6 bits only (simplified)
    int row = ((val & 0x20) >> 4) | (val & 0x1);
    int col = (val >> 1) & 0xF;
    return S1[row][col];          // returns 0-15
}

int main(){
    uint64_t plaintext, key;
    printf("Enter 64-bit plaintext (hex): ");
    scanf("%llx",&plaintext);
    printf("Enter 32-bit key (hex): ");
    scanf("%x",&key);

    // Initial Permutation
    uint64_t permuted = permute64(plaintext, IP, 64);
    uint32_t L = permuted >>32;
    uint32_t R = permuted & 0xFFFFFFFF;

    // Single DES round
    uint32_t R_new = L ^ f(R, key); // Feistel function
    L = R;
    R = R_new;

    // Combine and apply Final Permutation
    uint64_t preoutput = ((uint64_t)L <<32) | R;
    uint64_t ciphertext = permute64(preoutput, FP, 64);

    printf("Ciphertext: 0x%016llX\n", ciphertext);

    // Single-round decryption
    uint32_t Ld = R;
    uint32_t Rd = L ^ f(R, key);
    uint64_t preplain = ((uint64_t)Ld <<32) | Rd;
    uint64_t decrypted = permute64(preplain, FP, 64);
    printf("Decrypted: 0x%016llX\n", decrypted);

    printf("\nName=Dikshya Gautam\nLab=17\nRoll=32(B)\n");

    return 0;
}

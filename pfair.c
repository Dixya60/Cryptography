#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

// Create key matrix
void createMatrix(char key[]) {
    int used[26] = {0};
    char temp[25];
    int i, j, k = 0;

    for(i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if(ch == 'J') ch = 'I';

        if(!used[ch-'A']) {
            temp[k++] = ch;
            used[ch-'A'] = 1;
        }
    }

    for(i = 0; i < 26; i++) {
        if(i + 'A' == 'J') continue;

        if(!used[i]) {
            temp[k++] = i + 'A';
            used[i] = 1;
        }
    }

    k = 0;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            matrix[i][j] = temp[k++];
}

// Find position
void findPos(char ch,int *r,int *c){
    int i,j;

    if(ch=='J') ch='I';

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(matrix[i][j]==ch){
                *r=i;
                *c=j;
                return;
            }
}

// Prepare plaintext
void prepareText(char text[]){
    char temp[200];
    int i,j=0;

    for(i=0;text[i];i++){
        char ch=toupper(text[i]);

        if(ch=='J') ch='I';

        if(isalpha(ch))
            temp[j++]=ch;
    }

    temp[j]='\0';

    strcpy(text,temp);

    char result[200];
    j=0;

    for(i=0;text[i];i++){
        result[j++]=text[i];

        if(text[i]==text[i+1]){
            result[j++]='X';
        }
    }

    result[j]='\0';

    if(j%2!=0){
        result[j++]='X';
        result[j]='\0';
    }

    strcpy(text,result);
}

int main(){

    char text[200],key[100];
    int choice,count,i;
    int r1,c1,r2,c2;

    for(count=1;count<=3;count++){

        printf("\n===== Playfair Cipher (%d) =====\n",count);

        printf("1. Encryption\n2. Decryption\nEnter choice: ");
        scanf("%d",&choice);

        printf("Enter text: ");
        scanf("%s",text);

        printf("Enter key: ");
        scanf("%s",key);

        createMatrix(key);

        if(choice==1){
            prepareText(text);
            printf("Cipher Text: ");
        }
        else
            printf("Plain Text: ");

        for(i=0;text[i];i+=2){

            findPos(toupper(text[i]),&r1,&c1);
            findPos(toupper(text[i+1]),&r2,&c2);

            char a,b;

            if(r1==r2){
                if(choice==1){
                    a=matrix[r1][(c1+1)%5];
                    b=matrix[r2][(c2+1)%5];
                }
                else{
                    a=matrix[r1][(c1+4)%5];
                    b=matrix[r2][(c2+4)%5];
                }
            }

            else if(c1==c2){
                if(choice==1){
                    a=matrix[(r1+1)%5][c1];
                    b=matrix[(r2+1)%5][c2];
                }
                else{
                    a=matrix[(r1+4)%5][c1];
                    b=matrix[(r2+4)%5][c2];
                }
            }

            else{
                a=matrix[r1][c2];
                b=matrix[r2][c1];
            }

            if(choice==1)
                printf("%c%c",toupper(a),toupper(b));
            else
                printf("%c%c",tolower(a),tolower(b));
        }

        printf("\n");
    }

    printf("\nName = Dikshya Gautam");
    printf("\nLab no = 4");
    printf("\nRoll no = 32(B)");

    return 0;
}

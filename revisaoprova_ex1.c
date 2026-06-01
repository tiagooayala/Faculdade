#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void lerA(int a[10]){
    printf("Digite os 10 numeros da matriz A: \n");
    for(int i=0;i<10;i++){
        scanf("%i", &a[i]);
    }
    system("clear");
}

void lerB(int b[10]){
    printf("Digite os 10 numeros da matriz B: \n");
    for(int i=0;i<10;i++){
        scanf("%i", &b[i]);
    }
    system("clear");
}
void somav(int a[10], int b[10], int c[10]){
    for(int i=0;i<10;i++){
        c[i] = a[i] + b[i];
    }
}

void ordemex(int c[10]){
    int temp;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(c[j]>c[i]){
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;
            }
        }
    }
    printf("A matriz ordenada e: \n");
    for(int i=0;i<10;i++){
        printf("%i\n", c[i]);
    }
}

int main(){
    int A[10], B[10], C[10];
    lerA(A);
    lerB(B);
    somav(A, B, C);
    ordemex(C);
}
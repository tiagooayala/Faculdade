#include<stdio.h>
#include<string.h>
int somatoria(int n, int *soma){
    *soma = 0;
    for(int i=0;i<=n;i++){
        *soma = *soma + i;
    }
}

int main(){
    int num, total;
    printf("Digite um numero para somatoria: ");
    scanf("%i", &num);
    somatoria(num, &total);
    printf("O resultado e: %i", total);
    return 0;
}
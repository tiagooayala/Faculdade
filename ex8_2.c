#include<stdio.h>
#include<string.h>

void fibonacci(int n){
    int array[n];
    array[0] = 1;
    array[1] = 1;
    for(int i=0;i<n;i++){
        array[i+2] = array[i] + array[i+1];
    }
    printf("A sequencia de %i numeros: \n", n);
    for(int i=0;i<n;i++){
        printf("%i\n", array[i]);
    }
}

int main(){
    int num;
    printf("Digite os N numeros: ");
    scanf("%i", &num);
    fibonacci(num);
}
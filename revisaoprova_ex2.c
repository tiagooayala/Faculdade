#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct aluno{
    char nome[50];
    char curso[50];
    char ra[20];
    float media;
};

typedef struct aluno aluno;

void cadastro(struct aluno p[]){
    for(int i=0;i<5;i++){
        printf("Digite o nome do aluno %i: ", i);
        fgets(p[i].nome, 50, stdin);
        printf("Digite o curso do aluno %i: ", i);
        fgets(p[i].curso, 50, stdin);
        printf("Digite o RA do aluno %i: ", i);
        fgets(p[i].ra, 20, stdin);
        printf("Digite a media final do aluno %i: ", i);
        scanf("%f", &p[i].media);
        getchar();
        system("clear");
    }
}

void pesquisa(struct aluno p[]){
    char pesq[50];
    int flag = 0;
    printf("Digite o nome a ser buscado: ");
    fgets(pesq, 50, stdin);
    for(int i=0;i<5;i++){
        if(strcmp(pesq, p[i].nome) == 0){
            printf("Aluno encontrado: \n");
            printf("Nome: %s", p[i].nome);
            printf("Curso: %s", p[i].curso);
            printf("RA: %s", p[i].ra);
            printf("Media: %.2f \n", p[i].media);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Aluno nao encontrado. \n");
    }
}
void ordem(struct aluno p[]){
    char temp[50];
    float tempmedia;

    printf("Ordem alfabetica: \n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(strcmp(p[i].nome, p[j].nome)<0){
                strcpy(temp, p[i].nome);
                strcpy(p[i].nome, p[j].nome);
                strcpy(p[j].nome, temp);

                strcpy(temp, p[i].curso);
                strcpy(p[i].curso, p[j].curso);
                strcpy(p[j].curso, temp);

                strcpy(temp, p[i].ra);
                strcpy(p[i].ra, p[j].ra);
                strcpy(p[j].ra, temp);

                tempmedia = p[i].media;
                p[i].media = p[j].media;
                p[j].media = tempmedia;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("Nome: %s", p[i].nome);
        printf("Curso: %s", p[i].curso);
        printf("RA: %s", p[i].ra);
        printf("Media: %.2f \n", p[i].media);
    }
}

void alterar(struct aluno p[]){
    int registro, flag = 0;
    for(int i=0;i<5;i++){
        printf("Registro do aluno %i\n", i);
        printf("Nome: %s", p[i].nome);
        printf("Curso: %s", p[i].curso);
        printf("RA: %s", p[i].ra);
        printf("Media: %.2f \n", p[i].media);
    }
    printf("Digite o registro que queira que seja alterado: ");
    scanf("%i", &registro);
    getchar();
    if(registro<5 && registro >=0){
        printf("Digite o nome do aluno %i: ", registro);
        fgets(p[registro].nome, 50, stdin);
        printf("Digite o curso do aluno %i: ", registro);
        fgets(p[registro].curso, 50, stdin);
        printf("Digite o RA do aluno %i: ", registro);
        fgets(p[registro].ra, 20, stdin);
        printf("Digite a media final do aluno %i: ", registro);
        scanf("%f", &p[registro].media);
        getchar();
        system("clear");
        flag = 1;
    }
    if(flag == 0){
        system("clear");
        printf("Aluno nao encontrado \n");
    }
}

void aprovados(struct aluno p[]){
    printf("Alunos aprovados: \n");
    for(int i=0;i<5;i++){
        if(p[i].media>=6){
            printf("Nome: %s", p[i].nome);
            printf("Curso: %s", p[i].curso);
            printf("RA: %s", p[i].ra);
            printf("Media: %.2f \n", p[i].media);
        }
    }
}

int main(){
    int busca = -1;
    aluno lista[5];

    while(busca != 6){
        printf("======= MENU ALUNO =======\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Pesquisa nome \n");
        printf("3 - Classificar ordem alfabetica\n");
        printf("4 - Alterar dados aluno cadastrado\n");
        printf("5 - Exibir aluno aprovado\n");
        printf("6 - Sair\n");
        printf("Digite o numero do menu desejado: ");
        scanf("%i", &busca);
        getchar();
        system("clear");
        switch (busca){
            case 1:
                cadastro(lista);
                break;
            case 2:
                pesquisa(lista);
                break;
            case 3:
                ordem(lista);
                break;
            case 4:
                alterar(lista);
                break;
            case 5:
                aprovados(lista);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
            printf("Opcao invalida. \n");
        }
    }
}
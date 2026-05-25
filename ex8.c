#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct aluno {
   char nome[50];
   float n1;
   float n2;
   float media;
};
typedef struct aluno aluno;

void buffer(){
   int ch;
   while( (ch = getchar()) != EOF && ch != '\n' );
}

void cadastro(struct aluno p[]){
	for (int i=0;i<3;i++){
		printf("Digite o nome do aluno %i: ", i+1);
        fgets(p[i].nome, 50, stdin),
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0';
        printf("Digite a primeira nota: ");
        scanf("%f", &p[i].n1);
        buffer();
        printf("Digite a nota do segundo aluno: ");
        scanf("%f", &p[i].n2);
        buffer();
        system("clear");
	}
}

void ordenacao(struct aluno p[]){
    char temp[50];
    int tempn;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(strcmp(p[i].nome, p[j].nome)<0){
                strcpy(temp, p[i].nome);
                strcpy(p[i].nome, p[j].nome);
                strcpy(p[j].nome, temp);
                
                tempn = p[i].n1;
                p[i].n1 = p[j].n1;
                p[j].n1 = tempn;

                tempn = p[i].n2;
                p[i].n2 = p[j].n2;
                p[j].n2 = tempn;
            }
        }
    }
    printf("==== MENU CLASSIFICACAO ====\n");
    for (int i=0;i<3;i++){
        printf("Nome do aluno %i: %s\n", i+1, p[i].nome);
        printf("Primeira nota do aluno %i: %.2f \n", i+1, p[i].n1);
        printf("Segunda nota do aluno %i: %.2f \n", i+1, p[i].n2);
        printf(" ");
    }
}

void alterar(struct aluno p[]){
    int temp;

    printf("==== ALTERAR REGISRO ====\n");
    for (int i=0;i<3;i++){
        printf("Nome do aluno %i: %s\n", i+1, p[i].nome);
        printf("Primeira nota do aluno %i: %.2f\n", i+1, p[i].n1);
        printf("Segunda nota do aluno %i: %.2f\n", i+1, p[i].n2);
        printf(" ");
    }
    printf("\nDigite o registro a ser alterado: ");
    scanf("%i", &temp);
    buffer();
    if (temp>0 && temp <=3){
        printf("Digite o novo nome do aluno %i: ", temp);
        fgets(p[temp-1].nome, 50, stdin),
        printf("Digite a primeira nota: ");
        scanf("%f", &p[temp-1].n1);
        buffer();
        printf("Digite a segunda nota do aluno: ");
        scanf("%f", &p[temp-1].n2);
        buffer();
        system("clear");
    }
    else{
        system("clear");
        printf("Aluno nao encontrado\n");
    }
}

void pesquisa(struct aluno p[]){
    char busca[50];
    int flag = 0;
    printf("Digite o nome do aluno a ser procurado: ");
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = '\0';
    // buffer();
    for (int i=0;i<3;i++){
        if (strcmp(busca, p[i].nome)==0){
            printf("\nRegistro encontrado:\n");
            printf("%s; Nota 1: %.2f; Nota 2: %.2f\n", p[i].nome, p[i].n1, p[i].n2);
            flag = 1;
        }
    }
    if(flag==0){
        printf("Aluno nao encontrado\n");
    }
}

void aprovados(struct aluno p[]){
    for (int i=0;i<3;i++){
        p[i].media = (p[i].n1 + p[i].n2)/2;
    }
    printf("Alunos aprovados: \n");
    for (int i=0;i<3;i++){
        if (p[i].media>=6){
            printf("%s; Media: %.2f\n", p[i].nome, p[i].media);
        }
    }
}

void reprovados(struct aluno p[]){
    for (int i=0;i<3;i++){
        p[i].media = (p[i].n1 + p[i].n2)/2;
    }
    printf("Alunos reprovados: \n");
    for (int i=0;i<3;i++){
        if (p[i].media <= 5.9){
            printf("%s; Media: %.2f\n", p[i].nome, p[i].media);
        }
    }
}

int main(){
   int option = -1;
   
   struct aluno lista[3];

   while(option!=7){

       puts("===== MENU DA AGENDA =====");
       puts("1 - Cadastrar alunos");
       puts("2 - Classificar alunos registrados");
       puts("3 - Correcao");
       puts("4 - Pesquisa de alunos");
       puts("5 - Alunos aprovados");
       puts("6 - Alunos reprovados");
       puts("7 - Sair ");
       puts("Digite a opcao desejada: ");

       scanf("%i", &option);

       buffer();

       system("clear");
      
       switch (option){
          
           case 1:
               cadastro(lista);
               break;
           case 2:
               ordenacao(lista);
               break;
           case 3:
               alterar(lista);
               break;
           case 4:
               pesquisa(lista);
               break;
           case 5:
               aprovados(lista);
               break;
        	case 6:
        	   reprovados(lista);
        	   break;
        	case 7:
        		printf("Saindo do programa");
                break;
           default:
               printf("Opcao errada \n");
               break;
       }
   }
   return 0;
}

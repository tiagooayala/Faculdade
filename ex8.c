#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct aluno {
   char nome[50];
   int n1;
   int n2;
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
        printf("Digite a primeira nota: ");
        scanf("%i", &p[i].n1);
        buffer();
        printf("Digite a nota do segundo aluno: ");
        scanf("%i", &p[i].n2);
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
                p[i].n1 = p[j].n2;
                p[j].n1 = tempn;

                tempn = p[i].n2;
                p[i].n2 = p[j].n2;
                p[j].n2 = tempn;
            }
        }
    }
    printf("==== MENU CLASSIFICACAO ====\n");
    for (int i=0;i<3;i++){
        printf("Nome do aluno %i: %s", i+1, p[i].nome);
        printf("Primeira nota do aluno %i: %i\n", i+1, p[i].n1);
        printf("Segunda nota do aluno %i: %i\n", i+1, p[i].n2);
        printf(" ");
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
               
               break;
           case 4:
               
               break;
           case 5:
               
               break;
        	case 6:
        	   
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

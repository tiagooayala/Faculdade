#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct pessoa { // struct para armazenar os dados da pessoa
	char nome[50];
	char end[100];
	int idade;
};
typedef struct pessoa pessoa; // cria um apelido para struct pessoa

void buffer(){ 
    int ch;
    while( (ch = getchar()) != EOF && ch != '\n' ); // limpa o buffer do teclado
}

void cadastro(struct pessoa p[]){
	for(int i=0;i<5;i++){ // loop para cadastrar 5 pessoas
		printf("Digite o nome da pessoa %i: ", i+1);
		fgets(p[i].nome, 50, stdin); // le o nome
        p[i].nome[strcspn(p[i].nome, "\n")] = '\0'; // remove o \n do fgets

		printf("\nDigite a idade da pessoa %i: ", i+1);
		scanf("%i", &p[i].idade); // le a idade

		buffer(); // limpa o buffer apos scanf

		printf("\nDigite o endereco da pessoa %i: ", i+1);
		fgets(p[i].end, 100, stdin); // le o endereco
        p[i].end[strcspn(p[i].end, "\n")] = '\0'; // remove o \n do fgets

		system("clear"); // limpa a tela
	}
}

void pesquisa_idade(struct pessoa p[]){
	int i, busca, flag;

	printf("Digite a idade: ");
	scanf("%i", &busca); // recebe a idade a ser pesquisada

	flag = 0; // flag usada para verificar se encontrou alguem

	for (i=0; i<5; i++){ // percorre o vetor

		if (busca == p[i].idade){ // compara a idade digitada com a idade armazenada

			printf("Pessoa encontrada: \n");

			printf("%s, %i anos, %s \n", p[i].nome, p[i].idade, p[i].end);

			flag = 1; // indica que encontrou
		}
	}

	if (flag == 0){ // caso nao encontre
		printf("Pessoa nao encontrada");
	}
}

void ord_alfa(struct pessoa p[]){
    pessoa temp; // variavel auxiliar para troca

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){

            if (strcmp(p[i].nome, p[j].nome)<0){ // compara alfabeticamente os nomes

                temp = p[j]; // troca os registros
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    puts("A lista ordenada e: ");

    for (int i=0;i<5;i++){
        printf("%s \n", p[i].nome); // mostra os nomes ordenados
    }

    puts(" ");
}

void alt_registro(struct pessoa p[]){
    int num;

    for (int i=0;i<5;i++){ // mostra todos os registros
        printf("==== PESSOA %i ====\n", i+1);
        printf("Nome: %s\n", p[i].nome);
        printf("Idade: %i\n", p[i].idade);
        printf("Endereco: %s\n", p[i].end);
    }

    printf("Digite o registro a ser alterado: ");
    scanf("%i", &num);

    num = num-1; // ajusta para o indice do vetor

    buffer();

    if (num>=0 && num<5){ // verifica se o numero e valido

        printf("Digite o novo nome da pessoa: ");
		fgets(p[num].nome, 50, stdin);
        p[num].nome[strcspn(p[num].nome, "\n")] = '\0';

		printf("\nDigite a nova idade da pessoa: " );
		scanf("%i", &p[num].idade);

		buffer();

		printf("\nDigite o novo endereco da pessoa: ");
		fgets(p[num].end, 100, stdin);
        p[num].end[strcspn(p[num].end, "\n")] = '\0';

		system("clear");
    }

    else{
        printf("Registro nao encontrado\n");
    }
}

int main(){
	int option = -1; // inicializa a opcao

	pessoa lista[5]; // vetor de structs

	while(option!=5){ // loop principal do programa

		puts("===== MENU DA AGENDA =====");
		puts("Teste commit");
		puts("1 - Cadastrar informacoes");
		puts("2 - Pesquisa de idade");
		puts("3 - Ordem Alfabetica");
		puts("4 - Alteracao de registro");
		puts("5 - Sair ");
		puts("Digite a opcao desejada: ");

		scanf("%i", &option);

		buffer(); // limpa o buffer

		system("clear");
		
		switch (option){
			
			case 1: 
				cadastro(lista); // chama a funcao de cadastro
				break;

			case 2:
				pesquisa_idade(lista); // chama a pesquisa por idade
				break;

			case 3:
                ord_alfa(lista); // chama a ordenacao alfabetica
				break;

			case 4:
                alt_registro(lista); // chama a alteracao de registro
				break;

			case 5:
				printf("Saindo do programa... ");
				break;

			default:
				printf("Opcao errada \n");
				break;
		}
	}
}
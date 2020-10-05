#include <stdio.h>
#include <stdlib.h>

#define max 10;

//A ESTRUTURA DE NODES E DE CRIAR NODES SÃO UTILIZADAS NOS EXERCICIOS 4 E 5
typedef struct nodes{
	int value;
	struct node *next;
} node;

struct node *novo_node(int value){
	node *Node = (struct novo_node*)malloc(sizeof(node));
	Node->value=value;
	Node->next=NULL;

	return Node;
};

int isEmpty(node *root)
{
    return !root;
}


void exercicio1 (){

	printf("hello world\n");

}

void exercicio2 (){

	int vet[10];

	for(int i=0; i<10; i++){
		scanf("%d", &vet[i]);
	}

	for(int i=0; i<10; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}


void exercicio3(){

	int mat[10][10];

	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}


void pilha_push (node **root, int value){
	node *Node = novo_node (value);

	Node->next = *root;
	*root = Node;

}

void pilha_pop (node **root){

	node *aux = *root;
	*root = (*root)->next;
}

void print (node **root){

	node *aux = *root;

	while(1){

		printf("%d\n", aux->value);
		aux = aux->next;

		if (!aux){
			break;
		}

	}
}


void exercicio4(){
	node *root = NULL;
	int num=0, opc;

	for(int i=0; i<10; i++){
		scanf("%d", &num);
		pilha_push(&root, num);

	}

	while(1){
		printf("1 - desempilhar\n2 - imprimir pilha\n0 - sair\n");
		scanf("%d", &opc);

		switch(opc){
			case 1:
				pilha_pop(&root);
				printf("desempilhado\n");
				system("pause");
				break;

			case 2:
				print(&root);
				system("PAUSE");
				system("CLS");
				break;

			case 0:
				break;

			default:
				printf("invalido\n");
				system("pause");
				system("CLS");
				break;
		}
	}

}

void queue_push (node **front, int value){
	node *Node = novo_node (value);
	node *aux = *front;
	if (*front==NULL){
		*front = Node;
	}
	else{
		while(aux->next!=NULL){
				aux = aux->next;
			}
		aux->next=Node;
	}
}

void queue_pop(node **front){
	node *aux = *front;

	*front = (*front)->next;
	free(aux);

}


void exercicio5(){
	node *front = NULL;
	int num=0, opc;

	for(int i=0; i<10; i++){
		scanf("%d", &num);
		queue_push(&front, num);
	}

	while(1){
			printf("1 - desenfileirar\n2 - imprimir fila\n0 - sair\n");
			scanf("%d", &opc);

			switch(opc){
				case 1:
					pilha_pop(&front);
					printf("desenfileirado\n");
					system("pause");
					break;

				case 2:
					print(&front);
					system("PAUSE");
					system("CLS");
					break;

				case 0:
					break;

				default:
					printf("invalido\n");
					system("pause");
					system("CLS");
					break;
			}
		}




}



int main(void) {

	int opt=0;

	while(1){
		printf("Olá minha querida tia Lu!\nQual exercicio você quer executar?\n"
				"1 - Exercicio 1\n2 - Exercicio 2\n3 - Exercicio 3\n4 - Exercicio 4\n5 - Exercicio 5\n0 - Sair\n");
		scanf("%d", &opt);

		switch(opt){
			case 1:
				printf("Exercicio 1\n");
				exercicio1();
				system("PAUSE");
				break;

			case 2:
				printf("Exercicio 2\n");
				exercicio2();
				break;

			case 3:
				printf("Exercicio 3\n");
				exercicio3();
				break;

			case 4:
				printf("Exercicio 4\n");
				exercicio4();
				break;

			case 5:
				printf("Exercicio 5\n");
				exercicio5();
				break;

			case 0:
				return 0;

			default:
				printf("você apertou algum botão errado Lu, tenta denovo");
				system("PAUSE");
				system("CLS");

		}
	}
	return 0;
}

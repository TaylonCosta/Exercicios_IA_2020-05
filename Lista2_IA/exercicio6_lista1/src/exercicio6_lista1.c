#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodes{
	int prioridade;
	char *descricao;
	struct nodes *next;
} node;

node *create_node (int prioridade, char descricao){
	node *Node = (node*)malloc(sizeof(node));

	Node->prioridade=prioridade;
	Node->descricao = descricao;
	Node->next=NULL;

	return Node;
}

int isEmpty(node *root)
{
    return !root;
}


void queue_push (node **root, int prioridade, char descricao){

	node *Node = create_node(prioridade, descricao);
	node *aux = (*root);

	if (*root==NULL){
		Node->next = *root;
		(*root) = Node;
	}

	else{

		while(aux->next!=NULL && aux->next->prioridade < prioridade){
			aux->next = aux;
		}
		Node->next = aux->next;
		aux->next = Node;
	}

}


void queue_print (node **root){



	node *aux = *root;
	while(aux){

		printf("\ntask: %s\nprioridade: %d", aux->descricao, aux->prioridade);
		aux = aux->next;

	}
}

int main() {

	node *root = NULL;

	int prioridade;
	char descricao[40];


	for (int i=0; i<10; i++){
		printf("digite a descricao\n");
		gets(descricao);

		printf("digite a prioridade\n");
		scanf("%d", &prioridade);
		while(getchar() != '\n');

		queue_push(&root, prioridade, descricao);

	}

	queue_print(&root);

	return 0;
}

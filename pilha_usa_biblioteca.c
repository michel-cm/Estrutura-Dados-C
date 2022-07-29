#include <stdio.h>
#include "pilha.h"
//-------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I - Pilha Estatica ****\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");
	printf("3-Top (Olhar Topo)\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------
int main(){
	tpilha p1;
	int op;
	tdado dado;
	inicializa(&p1);
	do{
		printf("Topo:%d\n",p1.topo);
		printStack(p1);
		op = menu();
		switch(op){
			case 1: printf("Dado para inserir na pilha:");
					scanf("%d",&dado);
					if(push(&p1, dado)==1)
					 printf("Inserido com sucesso :)\n");
					else
					 printf("Pilha Cheia - Stack Overflow :(\n");
			break;
			case 2: if(!isEmpty(p1)){
				      dado = pop(&p1);
				      printf("Dado removido:%d\n",dado);
					}else
					  printf("Pilha vazia :(\n");
			break;		
			case 3: if(!isEmpty(p1)){
				      dado = top(p1);
				      printf("Dado do topo:%d\n",dado);
					}else
					  printf("Pilha vazia :(\n");
			break;				
			case 0: printf("Saindo ...\n");
			break;
		}// fim switch
		getch();
		system("cls");
	}while(op!=0);
	
}


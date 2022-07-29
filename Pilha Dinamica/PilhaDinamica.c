#include <stdio.h>
#include <stdlib.h>

typedef int tdado ;
typedef struct no{
	tdado dado;
	struct no *abaixo;
}tno;
typedef struct { 
	tno *topo;
	int qtd;
}tpilha;

void inicializa(tpilha *p){ // INICIALIZAR
	p->topo = NULL;
	p->qtd = 0;
}

int isEmpty(tpilha p){
	if(p.topo == NULL)
	return 1;	
	return 0;
}

tdado topo(tpilha p){	
	return p.topo->dado;
}

int count(tpilha p){
	return p.qtd;
}

void printStack(tpilha p){
	while (p.topo != NULL){	
	printf("%x| %d | %x ->\n ", p.topo , p.topo->dado , p.topo->abaixo);
		p.topo = p.topo->abaixo;
		}
		printf("\n");
}

int push (tpilha *p, tdado x){ // PUSH
	tno *novo = malloc(sizeof(tno));// alocando a memoria do tamanho de um " tno "...
	if(novo == NULL) // nao conseguiu alocar
		return 0;
	novo->dado = x;
	novo->abaixo = p->topo;
	p->topo = novo;
	p->qtd++;
	return 1;
}

tdado pop (tpilha *p){
	tdado retorno = p->topo->dado; // guardando o dado para retornar ...
	tno *aux = p->topo; // para poder limpar a area depois ...
	p->topo = p->topo->abaixo; // movendo o topo para o prox ...
	free(aux); // Limpa a memoria
	p->qtd--;
	return retorno; // retornando o dado do top
}

int menu(){
	int op;
	printf("-----  Pila Encadeada -----\n\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");	
	printf("3-Topo \n");
	printf("4-Count:\n");
	printf("0-Sair\n");
	scanf("%d", &op);
	return op;
}

int main(){
	tpilha p1;
	tdado dado;
	inicializa(&p1);
	int op;
	
	do{	
		printStack(p1);	
		printf("\n");
		op = menu();	
		switch (op){
			case 1:
				printf("numero para add na pilha : ");
				scanf("%d", &dado);
			 if(push( &p1, dado) != 0)
				printf("Inserido com sucesso \n");
				else{			
				printf(" FAIL \n\n");
				}
				break;
				
				case 2: if(isEmpty(p1) == 1)
						printf(" PILHA VAZIA ");
						else{
							dado = pop(&p1);
							printf("%d Removido \n", dado);	
						}
						break;									
				
				case 3: if(isEmpty(p1) == 1)
						printf(" PILHA VAZIA ");
						else{
							dado = topo(p1);
							printf("Topo da pilha eh: %d", dado);
						}
				break;
				
				case 4: if(isEmpty(p1) == 1)
						printf(" PILHA VAZIA ");
						else						
							printf("Quantidade de elementos: %d", count(p1));						
						break;
										
				case 0: printf("SAINDO ...");
				return 0;				
		}
		getch();
		system("cls");
	}while (op != 0);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[40];
	int rg;
} tdado;
typedef struct no{
	tdado dado;
	struct no *prox;
}tno;
typedef struct{
	tno *ini,*fim;
	int qtd;
}tfila;
//---------------------------
void inicializa(tfila *f){
	f->ini = NULL;
	f->fim = NULL;
	f->qtd = 0;
}
//--------------------------
int enqueue(tfila *f, tdado x){
	tno *novo = malloc(sizeof(tno));
	if(novo==NULL) // erro ao alocar
		return 0;
	novo->dado = x;
	novo->prox = NULL;
	if(f->ini == NULL) // fila vazia
		f->ini = novo;
	else
		f->fim->prox = novo;
	f->fim = novo;	
	f->qtd++;	
	return 1;
}
//-----------------------------
int isEmpty(tfila f){
	if(f.ini == NULL)
		return 1;
	else
		return 0;	
}
//----------------------------
tdado dequeue(tfila *f){
	tno *aux = f->ini; 
	tdado r = f->ini->dado; 
	f->ini = f->ini->prox; // removendo
	if(f->ini == NULL) 
		f->fim = NULL;
	free(aux); // liberando a memoria para evitar o memory leak
	f->qtd--;
	return r;
}
//-----------------------------
int count(tfila f){	
	int i = 0;
  tno *pointer = f.ini;
  while (pointer != NULL){
  		pointer = pointer->prox;
  		i++;
  }
  	return i; 		
}


//---------------------------
void printQueue(tfila f){
	while(f.ini!=NULL){
		//printf("%s |",f.ini->dado.nome);
		printf(" %x|%s->%x |",f.ini, f.ini->dado.nome, f.ini->prox) ;
		f.ini = f.ini->prox; // passando para o prox elemento
	}
	printf("\n");
}
//---------------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados I ***\n");
	printf("*** Fila Encadeada ***\n");
	printf("1-Enqueue (Inserir)\n");
	printf("2-Dequeue  (Remover)\n");
	printf("3-Qtde de pessoas na fila\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//----------------------
int main(){
	tfila f1;
	inicializa(&f1);
	tdado pessoa;
	int op;
	do{
	   printQueue(f1); 
		op=menu();
		switch(op){
			case 1: printf("Nome:");
					fflush(stdin); gets(pessoa.nome);
					printf("RG:");
					scanf("%d",&pessoa.rg);
					if(enqueue(&f1,pessoa)==1)
						printf("Inserido na fila :)\n");
					else
						printf("Vagas esgotadas :(\n");	
				break;
			case 2: if(!isEmpty(f1)){
						pessoa = dequeue(&f1);
						printf("%s atendido\n",pessoa.nome);
					}else
						printf("Fila vazia :(\n");	
				break;	
			case 3: printf("%d pessoas\n",count(f1));
			break;
			
			case 0: printf("Saindo...\n");
				break;	
		}
		getch();
		system("cls");
	}while(op!=0);
}

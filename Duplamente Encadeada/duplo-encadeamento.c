#include <stdio.h>
#include <stdlib.h>
typedef int tdado;
typedef struct no{
	tdado dado;
	struct no *prox,*ant;
}tno;
typedef struct{
	tno *head,*tail;
	int qtd;
}tlista;

void inicializa(tlista *lista){
	lista->head=NULL;
	lista->tail=NULL;
	lista->qtd=0;
}
//-------------------------------------
int insertTail(tlista *lista, tdado v){ // insereFim
	tno *novo;
	novo = malloc(sizeof(tno));
	novo->dado = v;
	novo->prox=NULL;
	novo->ant = lista->tail;
	if(lista->head==NULL)
	  lista->head = novo;
	  else
	    lista->tail->prox= novo;
	lista->tail=novo;  
	lista->qtd++;  
	return 1;
}
//----------------------------------
int insertHead(tlista *lista, tdado v){ // insereInicio
	tno *novo;
	novo = malloc(sizeof(tno));
	novo->dado = v;
	novo->ant = NULL;
	if(lista->tail == NULL)
	   lista->tail = novo;
	   else
	     lista->head->ant = novo;
	novo->prox = lista->head;
	lista->head= novo;
	lista->qtd++;
	return 1;	
}//-----------------------------------.
int insereOrdenado(tlista *lista, tdado x){
	tno *novo,*aux;
	if(lista->head == NULL) // se lista está vazia
	   return insertHead(lista,x);
	if(x <= lista->head->dado)
	   return insertHead(lista,x);
	if(x >= lista->tail->dado)   
	   return insertTail(lista,x);   
	novo = malloc(sizeof(tno));
	novo->dado = x;
	aux = lista->head;
	while(aux->prox!=NULL){
		if(x > aux->dado && x<= aux->prox->dado){
			// organizar os ponteiros aqui - IMPLEMENTAR
			novo->ant = aux;
			novo->prox = aux->prox;
			aux->prox->ant = novo;
			aux->prox = novo;
			return 1;
		}
		aux = aux->prox;
	}
	
}// fim insereOrdenado
//------------------------------------
tdado removeHead(tlista *lista){ // removeInicio
	tno *aux; tdado removido;
	aux=lista->head;
	removido=aux->dado;
	lista->head=lista->head->prox;
	if(lista->head==NULL)
	  lista->tail=NULL;
	  else
	   lista->head->ant=NULL;
	free(aux);
	lista->qtd--;
	return removido;     
}
//------------------------
tdado removeTail(tlista *lista){ // removeFim
	tno *aux; tdado removido;
	aux=lista->tail;
	removido = aux->dado;
	lista->tail = lista->tail->ant;  
	if(lista->tail==NULL)
	   lista->head=NULL;
	   else
	    lista->tail->prox=NULL;
	free(aux);
	lista->qtd--;
	return removido;    
}// fim 
//--------------------------------
int remover(tlista *lista, tdado x){
	tno *aux;
	if(lista->head == NULL) // vazio
		return 0;
	if(x == lista->head->dado)
	   return removeHead(lista);
	if(x == lista->tail->dado)
	   return removeTail(lista);   
	aux = lista->head; // aux sai do começo da lista
	while(aux->prox!=NULL){ // testando ate o fim da lista
		// testar se acho o elemento
		if(x == aux->dado){			
			
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			free(aux);
			lista->qtd--;	
			
			// organizar os ponteiros aqui - IMPLEMENTAR
			return 1;
		}// fim if
		aux= aux->prox;
	}//fim while
	return 0;// nao achou o elemento   
}
//--------------------------
int isEmpty(tlista lista){
	if(lista.head == NULL)
	   return 1;
	else
		return 0;   
}
//--------------------------------
void printList(tlista lista){
    while(lista.head!=NULL){
        printf("%d |",lista.head->dado);
        lista.head = lista.head->prox;
	}// fim while
	printf("\n");
}
//------------------------------

int menu(){
int op;
printf("*** Estrutura de Dados I ***\n\n");
printf("*** LISTA DUPLAMENTE ENCADEADA ***\n\n");
printf("1-Inserir ordenado\n");
printf("2-Insert Head\n");
printf("3-Insert Tail\n");
printf("4-Remove Head\n");
printf("5-Remove Tail\n");
printf("6-Remover\n");
printf("0-Sair\n");
scanf("%d",&op);
return op;
}
//-------------------------------
int main(){
	int op;
	tdado x;
	tlista lista;
	inicializa(&lista);
	do{
		printList(lista);
		op=menu();
		switch(op){
			case 1: printf("Dado para inserir\n");
            		scanf("%d",&x);
            		insereOrdenado(&lista,x);
			
            break;
            case 2: printf("Dado para inserir\n");
            		scanf("%d",&x);
            		insertHead(&lista,x);
            break;
			case 3: printf("Dado para inserir\n");
            		scanf("%d",&x);
            		insertTail(&lista,x);
            break;
			case 4: if(!isEmpty(lista)){
				     x = removeHead(&lista);
				     printf("Valor removido:%d\n",x);
					}
					 else
					   printf("Lista Vazia :(\n");
			break;
			case 5: if(!isEmpty(lista)){
				     x = removeTail(&lista);
				     printf("Valor removido:%d\n",x);
					}
					 else
					   printf("Lista Vazia :(\n");
			break; 
			case 6: printf("Valor para remover:");
					scanf("%d",&x);
			        if(!isEmpty(lista)){
				     x = remover(&lista,x);
				     if(x==0)
				        printf("Valor nao existente:(");
				     else   
					 	printf("Valor removido\n");
					}
					 else
					   printf("Lista Vazia\n");
			break; 		
			case 0: printf("Saindo...\n");
			break;	
		}// fim switch
		getch();
		system("cls");
	}while(op!=0);
}//fim main


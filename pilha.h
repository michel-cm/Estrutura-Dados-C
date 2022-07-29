#include <stdio.h>
#define MAX 5
typedef int tdado;
typedef struct{
	tdado pilha[MAX];
	int topo;
}tpilha;
//-----------------------
void inicializa(tpilha *p){
	p->topo = -1;
}
//----------------------
int push(tpilha *p, tdado x){ // inserir
	if(p->topo == MAX-1) // veriricando se não esta cheio
		return 0; //nao deu certo
	p->topo++;
	p->pilha[p->topo]= x; // colocando o dado no vetor pilha
	return 1;	
}
//-------------------
int isEmpty(tpilha p){
 if(p.topo==-1)
    return 1;
 else
   return 0;	
} 
//-------------------
tdado top(tpilha p){ // ou peek
	return p.pilha[p.topo];
}
//-------------------
tdado pop(tpilha *p){ // antes de chamar, verifica-se se existem dados
	tdado retorno = p->pilha[p->topo]; // pegou o valor do topo
	p->topo--; // remover
	return retorno; // devolvendo o dado que estava no topo
}
//----------------------
void printStack(tpilha p){
	while(p.topo != -1){
	  	printf("%d |", p.pilha[p.topo]);
	  	p.topo--;
	}
	printf("\n");
}

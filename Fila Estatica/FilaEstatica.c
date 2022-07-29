#include <stdio.h>
#define MAX 5

typedef struct { 
	char nome[40];
	int rg;
}tdado;
typedef struct { 
	tdado fila [MAX]; 
	int ini, fim , qtd; 
}tfila;
//---------------------
void inicializa(tfila *f){ 
	f->ini = 0; 
	f->fim = -1;
	f->qtd = 0;
}
//---------------------
int enqueue (tfila *f, tdado x){ 
	if(f->fim == MAX - 1)
		return 0;	
	f->fim++;
	f->fila[f->fim] = x;
	f->qtd++;
	return 1;
}
//---------------------
tdado dequeue(tfila *f){
	tdado ret = f->fila[f->ini]; 
	f->ini++;
	f->qtd--;
	return ret;
}
//---------------------
int isEmpty(tfila f){ 
	if(f.qtd == 0)
	return 0;
	else
	return 1;
}

int isQueueFull( tfila f){

     if( f. fim == MAX -1)

     return 1;

    return 0;

}
//---------------------
void printQueue(tfila f){
	while(f.ini <= f.fim){ 
		printf("%s - %d |", f.fila[f.ini].nome, f.fila[f.ini].rg);
		f.ini++;
		}
		printf("\n");
}
//---------------------
tdado first(tfila f){ // retornando o primeiro elemento da fila
	return f.fila[f.ini];
}
//---------------------
tdado last(tfila f){ // retornando o ultimo da fila
	return f.fila[f.fim];
}
//---------------------
int buscaRg(tfila f, int rgbusca){
	int pos = 0 , achou =0;
	
	while(f.ini<=f.fim){
		pos++;
		if(rgbusca==f.fila[f.ini].rg){
			achou = 1;
			return pos;
		}
		f.ini ++;
	} // fim hile
	if(achou == 0){
		return 0;
	}
}
//---------------------
int menu(){
	int op;
	printf("*** Estrutura de Dados 1 ***\n");
	printf("*** Fila Estatica ***\n");
	printf(" 1 - Enqueue (Inserir) \n");
	printf(" 2 - Dequeue (Remover) \n");
	printf(" 3 - Primeiro e Ultimo \n");
	printf(" 4 - Posicao na fila por RG \n");
	printf(" 5 - Cheia ?\n");
	printf(" 0 - Sair \n");
	scanf("%d", &op);
	return op;
}
//---------------------
int main(){
	tfila f1;
	inicializa(&f1);	
	tdado pessoa; 
	int op, busca;
	do{ 
		printf("Ini:%d | Fim:%d | qtd:%d |\n\n", f1.ini, f1.fim, f1.qtd); 
		printQueue(f1); 
		op = menu(); 
		switch (op){ 
			case 1:printf("Nome: ");
					fflush(stdin);	gets(pessoa.nome);  
				printf("RG:");
				scanf("%d", &pessoa.rg);
				if(enqueue(&f1,pessoa)==1) 
					printf("Inserido na fila :)\n");
				else
				printf("Vagas Esgotadas :C");			
				break;
			case 2: if(isEmpty(f1) == 0)				
				printf(" Fila Vazia");
				else{
					pessoa = dequeue(&f1);
					printf("%s atendido! \n", pessoa.nome);
				}//fim else				
				break;
			case 3: if(isEmpty(f1) == 0)	 			
				printf(" Fila Vazia");
				else{
					printf("%s \n", first(f1).nome);
					printf("%s \n", last(f1).nome);
									
				}//fim else
				break;
			case 4:printf("Digite o RG para busca : "); 
					fflush(stdin);
					scanf("%d", &busca);
					if (buscaRg(f1, busca) == 0 )
					printf("RG nao encontrado");
					else{
						buscaRg(f1,busca);						
						printf("Posicao %d na fila", buscaRg(f1,busca));
					};		
					break;
					case 5: if(isQueueFull(f1) == 1)
					printf("CHEIA");
					else
					printf("Tem espaco");
					break;
			case 0: printf("Saindo .... \n");
				break;
		}
		getch();
		system("cls");
	}while(op!=0);
}



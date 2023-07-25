#include <stdio.h>
#include <stdlib.h>

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int itens;

};

void criarFila( struct Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->itens = 0;

}

void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->itens++;

}

int remover( struct Fila *f ) {

	int temp = f->dados[f->primeiro++];

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->itens--;
	return temp;

}

int estaVazia( struct Fila *f ) {

	return (f->itens==0);

}

int estaCheia( struct Fila *f ) {

	return (f->itens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->itens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

int main () {

	int op, capacidade;
	float valor;
	struct Fila Fila;

	printf("\nCapacidade da fila? ");
	scanf("%d",&capacidade);
	criarFila(&Fila, capacidade);

	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &op);

		switch(op){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&Fila)){

					printf("\nFila cheia!\n\n");

				}
				else {

					printf("\nValor do elemento? ");
					scanf("%f", &valor);
					inserir(&Fila,valor);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&Fila)){

					printf("\nFila vazia!\n\n");

				}
				else {

					valor = remover(&Fila);
					printf("\n%1f foi removido com sucesso\n\n", valor) ;

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&Fila)){

						printf("\nFila vazia!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&Fila);

					}
					break;

				default:
					printf("\nOpcao invalida\n\n");

		}
	}
}



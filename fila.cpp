#include <stdio.h>
#include <stdlib.h>

struct fila
{
	int capacidade, cap, primeiro, ultimo;
	float *itens;
};

void criarfila(struct fila *f, int c){
	f->primeiro = 0;
	f->ultimo = -1;
	f->capacidade = c;
	f->itens = (float*) malloc (c * sizeof(float));
	f->cap = 0;
}

int cheia(struct fila *f){
	if (f->cap == f->capacidade) {
        return 1;
    } else {
        return 0;
    }
}

int vazia(struct fila *f){
	if (f->cap == 0){
		return 1;
	} else {
		return 0;
	}
}

void inserir(struct fila *f, int d){
if (cheia(f)) {
        printf("Fila cheia\n");
    } else {
			if(f->ultimo == f->capacidade-1)
				f->ultimo = -1;
            f->ultimo++;
			f->cap++;
			f->itens[f->cap - 1] = d;
        	printf("%d\n", d);
        }

}

void remover(struct fila *f){
	if(vazia(f)){
		printf("Fila vazia\n");
	    } else {
	f->primeiro = f->itens[1];
	for(int i = 0; i < f->capacidade - 1; i++){
		f->itens[i] = f->itens[i + 1];
	}
	f->cap--;
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	}
}
void mostrar(struct fila *f) {
	int cont,i;
    if (vazia(f)) {
        printf("Fila vazia\n");
    } else {
        printf("Valores na fila: ");
		f->primeiro = 0;
        for (cont = 0, i = f->primeiro; i < f->cap; cont++) {
            printf("%.2f\t", f->itens[i++]);
        }
        printf("\n");
    }
}

int main()
{
	int cap, opc;
	float valor;
	struct fila fila;
	printf("\nCapacidade da fila? ");
	scanf("%d",&cap);
	criarfila(&fila, cap);
	while(1){
        printf("\n1 para inserir\n2 para remover\n3 para mostrar\n0 para sair\nOpcao:  ");
        scanf("%d", &opc);
        switch (opc) {
			case 1:
                printf("Valor para inserir:");
                scanf("%f", &valor);
                inserir(&fila, valor);
                break;
            case 2:
                remover(&fila);
                break;
            case 3:
                mostrar(&fila);
                break;
            case 0:
                exit(0);
            default:
                printf("Opção invalida\n");
		}
	}
}

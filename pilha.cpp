#include <stdio.h>
#include <stdlib.h>

struct Pilha {

	int topo;
	int capacidade;
	float *valor;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = 0;
   p->capacidade = c;
   p->valor = (float*) malloc (c * sizeof(float));

}
int estavazia ( struct Pilha *p ){

   if( p-> topo == 0)

      return 1;

   else

      return 0;

}

int estacheia ( struct Pilha *p ){

	if (p->topo == p->capacidade)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->valor [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float Valordesempilhado = p->valor [p->topo];
   p->topo--;
   return Valordesempilhado;

}

float retornatopo ( struct Pilha *p ){

   return p->valor [p->topo];

}

int main(){

	struct Pilha pilha;
	int capacidade, option;
	float valor;

	printf( "\nQual a capacidade da pilha? " );
	scanf( "%d", &capacidade );

	criarpilha (&pilha, capacidade);

	while( 1 ){

		printf("\n1- Empilhar\n");
		printf("2- Desempilhar\n");
		printf("3- Mostrar o topo \n");
		printf("4- Sair\n");
		printf("\nOpcao? ");
		scanf("%d", &option);

		switch (option){

			case 1:

				if( estacheia( &pilha ) == 1 )

					printf("\nPilha esta cheia! \n");

				else {

					printf("\nValor? ");
					scanf("%f", &valor);
					empilhar (&pilha, valor);

				}
				break;

			case 2:
				if ( estavazia(&pilha) == 1 )

					printf( "\nPilha esta vazia! \n" );

				else{

					valor = desempilhar (&pilha);
					printf ( "\nO valor ""%.1f foi desempilhado!\n", valor );

				}
				break;

			case 3:
				if ( estavazia (&pilha) == 1 )

					printf( "\nPilha esta vazia!\n" );

				else {

					valor = retornatopo (&pilha);
					printf ( "\nO valor do topo e: %.1f\n", valor );

				}
				break;

			case 4: 
				exit(0);

			default: printf( "\nEsta opcao e invalida! \n" );
		}
	}
}



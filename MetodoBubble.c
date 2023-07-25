#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void bubbleSort(int v[200], int n) {//cria uma função void que pede dois parametros
    int i, j, aux;//declara 3 variaveis inteiras
    for (i = n - 1; i > 0; i--) {//cria um loop que continua enquanto i ser maior que 0
        for (j = 0; j < i; j++) {//cria um loop que continua enquanto j ser menor que i
            if (v[j] > v[j + 1]) {//se o valor da posição j do vetor for maior que a posição j+1
                aux = v[j];//ele atribui o valor j para aux
                v[j] = v[j + 1];// ele coloca o valor j+1 na posição de j
                v[j + 1] = aux; // e depois coloca o valor salvo em aux para j+1
            }
        }
    }
}

int main() {
    int v[200], n, i;
    char input[100];

    printf("Entre o tamanho desejado do vetor: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &n) == 1) {
            break;
        } else {
            printf("Entrada inválida. Digite um número válido.\n");
        }
    }

    printf("Entre os %d elementos do vetor:\n", n);
    for (i = 0; i < n; i++) {
        int num;
        while (1) {
            printf("Elemento %d: ", i + 1);
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &num) == 1) {
                v[i] = num;
                break;
            } else {
                printf("Entrada inválida. Digite um número válido.\n");
            }
        }
    }

    bubbleSort(v, n);

    printf("\n\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void insertionSort(int v[200], int n) {//cria uma função void que pede dois parametros
    int i, j, x;//declara 3 variaveis inteiras
    for (i = 1; i < n; i++) {//cria um loop que continua enquanto i ser menor que o tamanho do vetor
        x = v[i];//define o valor de x como o valor que esta na posição i do vetor v
        j = i - 1;//define o valor de j como i-1
        while (j >= 0 && v[j] > x) {//enquanto j for maior ou igual a 0 e o valor da posição J do vetor V for maior que x
            v[j + 1] = v[j];//define a posição j +1 do vetor com v[j]
            j--;//diminui 1 de j
        }
        v[j + 1] = x;//define x com o valor da posição j+1 do vetor
    }
}

int main() {
    int v[200], n, i;//declara 3 variaveis inteiras
    char input[100];//declara variavel de caracter
    
    printf("Entre o tamanho desejado do vetor: ");
    while (1) {
        fgets(input, sizeof(input), stdin);//lê uma linha de entrada entrada (stdin) e a armazena na variável input
        if (sscanf(input, "%d", &n) == 1) {//analisa a string input em busca de um número inteiro e o armazena na variável n
            break;
        } else {// se não encontrar ele printa erro
            printf("Entrada inválida. Digite um número válido.\n");
        }
    }
    
    printf("Entre os %d elementos do vetor:\n", n);
    for (i = 0; i < n; i++) {//cria um loop que continua enquanto i ser menor que o tamanho do vetor
        int num;
        while (1) {
            printf("Elemento %d: ", i + 1);
            fgets(input, sizeof(input), stdin);
            if (sscanf(input, "%d", &num) == 1) {
                v[i] = num;//depois atribui o valor de num para v[i]
                break;
            } else {
                printf("Entrada inválida. Digite um número válido.\n");
            }
        }
    }
    
    insertionSort(v, n);//chama a função e passa v como elementos e n como o tamanhodo vetor
    
    printf("\n\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", v[i]);//printa os valors do vetor
    }
    printf("\n");
    
    return 0;
}
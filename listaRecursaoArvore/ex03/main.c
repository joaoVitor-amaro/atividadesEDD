#include <stdio.h>

int soma_vetor(int vetor[], int n) {
    if(n == 0) {
        return 0;
    }
    return vetor[n - 1] + soma_vetor(vetor, n-1);
}

int main() {
    int numeros[] = {1, 2, 3, 4};
    int tam = sizeof(numeros)/sizeof(numeros[0]);
    printf("soma dos vetores: %d\n", soma_vetor(numeros, tam));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
} Node;

Node* novoNode(int valor) {
    Node* no = (Node*) malloc(sizeof(Node));
    if (no == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return novoNode(valor); 
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor); 
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);   
    }
    return raiz;
}

int buscar(Node* raiz, int valor) {
    if (raiz == NULL) {
        return 0; 
    }
    if (valor == raiz->valor) {
        return 1; 
    } else if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

void pre_ordem(Node* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->valor);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}


void em_ordem(Node* raiz) {
    if (raiz == NULL) return;
    em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    em_ordem(raiz->direita);
}


void pos_ordem(Node* raiz) {
    if (raiz == NULL) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}

int main() {
    Node* raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 7);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
    int altura;
} Node;


Node* novoNode(int valor) {
    Node* no = (Node*) malloc(sizeof(Node));
    if (!no) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1; 
    return no;
}

Node* inserir(Node* raiz, int valor) {
    if (!raiz) return novoNode(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz; 
}

int altura(Node* no) {
    if (!no) return 0;

    int altEsq = altura(no->esquerda);
    int altDir = altura(no->direita);

    return (altEsq > altDir ? altEsq : altDir) + 1;
}

int fator_balanceamento(Node* no) {
    if (!no) return 0;
    return altura(no->esquerda) - altura(no->direita);
}

Node* rotacao_direita(Node* y) {
    Node* x = y->esquerda;
    Node* T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    return x; 
}


Node* rotacao_esquerda(Node* x) {
    Node* y = x->direita;
    Node* T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    return y; 
}

Node* inserirAVL(Node* raiz, int valor) {
    if (!raiz) {
        return novoNode(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserirAVL(raiz->esquerda, valor);
    }else if (valor > raiz->valor) {
        raiz->direita = inserirAVL(raiz->direita, valor);
    }else {
        return raiz; 
    }
    raiz->altura = 1 + (altura(raiz->esquerda) > altura(raiz->direita) ? altura(raiz->esquerda) : altura(raiz->direita));
    int fb = fator_balanceamento(raiz);
    if (fb > 1 && valor < raiz->esquerda->valor) {
        return rotacao_direita(raiz);
    }
    if (fb < -1 && valor > raiz->direita->valor) {
        return rotacao_esquerda(raiz);   
    }
    if (fb > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
        return rotacao_direita(raiz);
    }
    if (fb < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacao_direita(raiz->direita);
        return rotacao_esquerda(raiz);
    }
    return raiz;
}

int esta_balanceada(Node* raiz) {
    if (!raiz) {
        return 1; 
    }
    int fb = fator_balanceamento(raiz);
    if (fb < -1 || fb > 1)  {
        return 0; 
    }
    return esta_balanceada(raiz->esquerda) && esta_balanceada(raiz->direita);
}

void em_ordem(Node* raiz) {
    if (!raiz) return;
    em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    em_ordem(raiz->direita);
}

int main() {
    Node* raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);

    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Fator de balanceamento da raiz: %d\n", fator_balanceamento(raiz));
    printf("Fator de balanceamento do nó 20: %d\n", fator_balanceamento(raiz->direita));
    raiz = rotacao_esquerda(raiz);
    printf("Após rotação à esquerda na raiz: ");
    em_ordem(raiz);
    printf("\n");

    raiz = rotacao_direita(raiz);
    printf("Após rotação à direita na raiz: ");
    em_ordem(raiz);
    printf("\n");

    Node* raiz2 = NULL;
    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores)/sizeof(valores[0]);

    for(int i = 0; i < n; i++)
        raiz = inserirAVL(raiz, valores[i]);

    return 0;
}

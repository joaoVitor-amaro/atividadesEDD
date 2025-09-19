#include <stdio.h>
#include <stdlib.h>  
#include <limits.h>

typedef struct No {
    int valor;
    struct No *fd;
    struct No *fe;
} No;

No* novoNo(int valor) {
    No* no = (No*) malloc(sizeof(No));
    if (!no) {
        printf("Erro de alocacao!\n");
        return NULL;
    }
    no->valor = valor;
    no->fd = NULL;
    no->fe = NULL;
    return no;
}

No* inserirNo(No *raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->fe = inserirNo(raiz->fe, valor);
    } else if (valor > raiz->valor) {
        raiz->fd = inserirNo(raiz->fd, valor); 
    }
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d ", raiz->valor);   
    preOrdem(raiz->fe);           
    preOrdem(raiz->fd);           
}

void inOrdem(No* raiz) {
    if (raiz == NULL) return;
    inOrdem(raiz->fe);            
    printf("%d ", raiz->valor);   
    inOrdem(raiz->fd);            
}

void posOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->fe);           
    posOrdem(raiz->fd);           
    printf("%d ", raiz->valor);  
}


int altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altEsq = altura(raiz->fe);
    int altDir = altura(raiz->fd);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->fe) + contarNos(raiz->fd);
}

int contarFolhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->fe == NULL && raiz->fd == NULL) {
        return 1;
    }
    return contarFolhas(raiz->fe) + contarFolhas(raiz->fd);
}

int buscar(No* raiz, int valor) {
    if (raiz == NULL) return 0;         
    if (valor == raiz->valor) {
        return 1;
    } 
    if (valor < raiz->valor)
        return buscar(raiz->fe, valor); 
    else
        return buscar(raiz->fd, valor); 
}


int menorValor(No* raiz) {
    if (raiz == NULL) {
        printf("Arvore vazia!\n");
        return -1; 
    }
    No* atual = raiz;
    while (atual->fe != NULL) {
        atual = atual->fe;
    }
    return atual->valor;
}

int maiorValor(No* raiz) {
    if (raiz == NULL) {
        printf("Arvore vazia!\n");
        return -1; 
    }
    No* atual = raiz;
    while (atual->fd != NULL) {
        atual = atual->fd;
    }
    return atual->valor;
}

int ehBST(No* raiz, int* min, int* max) {
    if (raiz == NULL) {
        return 1;
    }
    if ((min && raiz->valor <= *min) || (max && raiz->valor >= *max)) {
        return 0; 
    }
    return ehBST(raiz->fe, min, &(raiz->valor)) &&
           ehBST(raiz->fd, &(raiz->valor), max);
}



int main() {
    No *raiz = NULL;  // inicializar com NULL
    raiz = inserirNo(raiz, 8);
    raiz = inserirNo(raiz, 1);
    raiz = inserirNo(raiz, 2);

    printf("Pre-ordem: ");
    preOrdem(raiz);
    printf("\nIn-ordem: ");
    inOrdem(raiz);
    printf("\nPos-ordem: ");
    posOrdem(raiz);
    printf("\n");

    printf("Altura da árvore: %d\n", altura(raiz));

    printf("Total de nos: %d\n", contarNos(raiz));   
    printf("Total de folhas: %d\n", contarFolhas(raiz)); 

    int valor = 9;
    if (buscar(raiz, valor))
        printf("Valor %d encontrado!\n", valor);
    else
        printf("Valor %d nao encontrado!\n", valor);

    printf("Menor valor: %d\n", menorValor(raiz)); 
    printf("Maior valor: %d\n", maiorValor(raiz)); 

    if (ehBST(raiz, NULL, NULL))
        printf("A arvore é uma BST\n");
    else
        printf("A arvore NAO é uma BST\n");

    return 0;
}

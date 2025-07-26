#include <iostream>
#include "ListaSequencial.h"

ListaSequencial::ListaSequencial() {
    this->tamAtual = 0;
    this->tamMaximo = 10;
    this->dados = new int[tamMaximo];
}

bool ListaSequencial::vazio() {
    if(this->tamAtual == 0) {
        return true;
    }
    return false;
}

bool ListaSequencial::cheia() {
    if(this->tamAtual == this->tamMaximo) {
        return true;
    }
    return false;
}

int ListaSequencial::getTamAtual() {
    return this->tamAtual;
}

bool ListaSequencial::insere(int pos, int dado) {
    if((cheia()) || (pos > this->tamAtual+1) || (pos <= 0)) {
        return false;
    }

    for(int i = this->tamAtual; i >= pos; i--) {
        this->dados[i] = this->dados[i-1];
    }

    this->dados[pos-1] = dado;
    this->tamAtual++;
    return true;
}

int ListaSequencial::remove(int pos) {
    int dado;
    if(pos < 1 || pos > this->tamAtual) {
        return false;
    }

    dado = dados[pos-1];
    for(int i = pos - 1; i < tamAtual; i++) {
        dados[i] = dados[i+1];
    }
    tamAtual--;
    return dado;
}

int ListaSequencial::getElemento(int pos) {
    if(pos < 1 || pos > this->tamAtual) {
        return -1;
    }
    return dados[pos-1];
}

int ListaSequencial::getPosicao(int elemento) {
    for(int i = 0; i < tamAtual; i++) {
        if(dados[i] == elemento) {
            return (i+1);
        }
    }
    return -1;
}

int ListaSequencial::modificar(int pos, int dado) {
    if(pos < 1 || pos > this->tamAtual) {
        return -1;
    }
    int elemento = this->dados[pos-1];
    this->dados[pos-1] = dado;
    return elemento;
}
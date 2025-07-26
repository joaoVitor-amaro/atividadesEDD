#include <iostream>
#include "ListaSequencial.h"

using namespace std;

int main() {
    ListaSequencial lista;
    cout << "Lista vazia? " << ((lista.vazio()) ? "Sim":"Nao") << endl;
    lista.insere(1, 10);
    lista.insere(2, 20);
    lista.insere(3, 30);
    cout << "Lista vazia? " << ((lista.vazio()) ? "Sim":"Nao") << endl;
    cout << "Lista cheia? " << ((lista.cheia()) ? "Sim":"Nao") << endl;
    if(!lista.insere(5, 10)) {
        std::cout << "Valor nao inserido" << std::endl;
    }
    int dado = lista.remove(1);
    cout << "Dado removido: " << dado << endl;
    cout << "Lista cheia? " << ((lista.cheia()) ? "Sim":"Nao") << endl;
    int elemento = lista.getElemento(2);
    if(elemento != -1) {
        cout << "Elemento: " << elemento << endl;
    } else {
        cout << "ELemento nao encontrado" << endl;
    }
    int posicao = lista.getPosicao(20);
    if(posicao != -1) {
        cout << "Posicao do elemento: " << posicao << endl;
    } else {
        cout << "POsicao nao encontrada"<< endl;
    }
    int elemento_modificado = lista.modificar(1, 40);
    if(elemento_modificado != -1) {
        cout << "Valor " << elemento_modificado << " Modificado" << endl;
    }
    printf("Tamanho da lista: %d\n", lista.getTamAtual());
    return 0;
}
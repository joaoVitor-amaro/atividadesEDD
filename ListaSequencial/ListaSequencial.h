#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

class ListaSequencial {
    private:
        int* dados;
        int tamAtual;
        int tamMaximo;
    public:
        ListaSequencial();
        bool vazio();
        bool cheia();
        int getTamAtual();
        bool insere(int pos, int dado);
        int remove(int pos);
        int getElemento(int pos);
        int getPosicao(int elemento);
        int modificar(int pos, int dado);

};

#endif

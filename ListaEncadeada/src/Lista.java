public class Lista {
    private int tamanho = 0;
    private No primeiro;

    public Lista() {
        this.primeiro = null;
    }
    //Verifica se a lista está vazia
    public boolean is_vazio() {
        return (tamanho == 0) ? true : false;
    }

    //Inserir elementos da lista
    public void inserir(int pos, int valor) {
        if(pos == 1) {
            inserirInicio(valor);
        } else if(pos == tamanho + 1){ // Insere elementos depois da posição 1
            inserirFim(valor);
        } else {
            inserirMeio(pos, valor);
        }
    }

    public void inserirInicio(int valor) {
        No novoNo = new No(valor);
        novoNo.setProximo(primeiro);
        primeiro = novoNo;
        tamanho++;
        System.out.printf("Valor %d inserido\n", novoNo.getValor());
    }

    public void inserirFim(int valor) {
        No atual = primeiro;
        while (atual.getProximo() != null) {
            atual = atual.getProximo();
        }
        No novoNo = new No(valor);
        atual.setProximo(novoNo);
        tamanho++;
    }

    public void inserirMeio(int pos, int valor) {
        if(pos < 1 || pos > tamanho) {
            System.out.println("Posição inválida");
            return;
        }
        int cont = 1;
        No atual = primeiro;
        while (cont < pos && atual != null) {
            atual = atual.getProximo();
            cont++;
        }
        No novoNo = new No(valor);
        novoNo.setProximo(atual.getProximo());
        atual.setProximo(novoNo);
        tamanho++;
        System.out.printf("Valor %d inserido\n", novoNo.getValor());
    }

    //Remover elementos da lista
    public void remove(int pos) {
        if(is_vazio()) {
            return;
        }
        if(pos == 1) {
            removeInicio();
        } else { //Remove elementos depois da posição 1
            removePos(pos);
        }
    }

    public void removeInicio() {
        primeiro = primeiro.getProximo();
        tamanho--;
    }

    public void removePos(int pos) {
        if(pos < 1 || pos > tamanho) {
            System.out.println("Posição inválida");
            return;
        }
        int cont = 1;
        No atual = primeiro;
        while (cont < pos && atual != null) {
            atual = atual.getProximo();
            cont++;
        }
        System.out.printf("Valor %d removido\n", atual.getValor());
        primeiro.setProximo(atual.getProximo());
        tamanho--;
    }

    //Obter o valor da lista
    public int obterValor(int pos) {
        if(pos < 1 || pos > tamanho) {
            return -1;
        }
        int cont = 1;
        No atual = primeiro;
        while (cont != pos) {
            atual = atual.getProximo();
            cont++;
        }
        return atual.getValor();
    }

    //Exibe os elementos da Lista
    public void exibirLista() {
        No aux = primeiro;
        while (aux != null) {
            System.out.printf("%d -> ",aux.getValor());
            aux = aux.getProximo();
        }
        System.out.println("Null");
    }

    public int getTamanho() {
        return tamanho;
    }
}

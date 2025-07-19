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
        } else { // Insere elementos depois da posição 1
            inserirPos(pos, valor);
        }
    }

    public void inserirInicio(int valor) {
        No novoNo = new No(valor);
        novoNo.setProximo(primeiro);
        primeiro = novoNo;
        tamanho++;
        System.out.printf("Valor %d inserido\n", novoNo.getValor());
    }

    public void inserirPos(int pos, int valor) {
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
    }

    //Exibe os elementos da 
    public void exibirLista() {
        No aux = primeiro;
        while (aux != null) {
            System.out.printf("%d -> ",aux.getValor());
            aux = aux.getProximo();
        }
        System.out.println("Null");
    }
}

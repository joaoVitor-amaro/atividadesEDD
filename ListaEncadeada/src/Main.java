public class Main {
    public static void main(String[] args) {
        Lista lista = new Lista();
        lista.inserir(1, 2);
        lista.inserir(2, 5);
        lista.inserir(3, 8);
        lista.exibirLista();
        lista.remove(3);
        lista.exibirLista();
        lista.inserir(2, 10);
        lista.exibirLista();
        lista.modificarValor(2, 15);
        lista.exibirLista();
        int valorList = lista.obterValor(2);
        if(valorList != -1) {
            System.out.printf("Valor buscado: %d\n", valorList);
        } else {
            System.out.println("Valor não encontrado");
        }
        System.out.printf("Tamanho da lista: %d\n", lista.getTamanho());
    }
}
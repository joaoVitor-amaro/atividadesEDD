public class Main {
    public static void main(String[] args) {
        Lista lista = new Lista();
        lista.inserir(1, 4);
        lista.inserir(1, 5);
        lista.inserir(1, 8);
        lista.exibirLista();
        lista.remove(2);
        lista.exibirLista();
    }
}
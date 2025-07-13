import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        ReadFiles readFiles = new ReadFiles();
        File directory = new File("/home/joao/Documentos/projetos/OrdenacaoEDD/src/files/");
        long startTime, endTime;
        if(directory.exists() && directory.isDirectory()) {
            File[] files = directory.listFiles();
            Arrays.sort(files, (f1, f2) -> f1.getName().compareTo(f2.getName())); //Ordena os arquivos
            for(File file : files) {
                Ordenacao ordenacao = ReadFiles.lerArquivos(file);
                List<Long> dados = ordenacao.getNums();
                //Copia de arquivo para Ordenação
                List<Long> copia1 = new ArrayList<>(dados);
                List<Long> copia2 = new ArrayList<>(dados);
                System.out.println("Arquivo: " + file.getName());
                //Tempo de execução do insertionSort
                startTime = System.nanoTime();
                ordenacao.insertionSort(copia1);
                endTime = System.nanoTime();
                System.out.println("Tempo do InsertionSort: " + (endTime - startTime)/1_000_000.0 + "ms");

                //Tempo de execução do selectionSort
                startTime = System.nanoTime();
                ordenacao.selectionSort(copia2);
                endTime = System.nanoTime();
                System.out.println("Tempo do SelectionSort: " + (endTime - startTime)/1_000_000.0 + "ms");
                System.out.println("");
                ordenacao.clearList();
            }
        }
    }
}
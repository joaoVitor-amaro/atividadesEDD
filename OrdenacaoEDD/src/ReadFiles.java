import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class ReadFiles {
    //Ler os arquivos
    public static Ordenacao lerArquivos(File arquivo) {
        String linha_num;
        Ordenacao valor = new Ordenacao();
        try(BufferedReader file = new BufferedReader(new FileReader(arquivo))) {
            while ((linha_num = file.readLine()) != null) {
                valor.adicionar(Long.parseLong(linha_num));
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return valor;
    }
}

import java.util.ArrayList;
import java.util.List;

public class Ordenacao {
    private List<Long> nums = new ArrayList<>();

    public void adicionar(long num) {
        this.nums.add(num);
    }

    public void selectionSort(List<Long> numbers) {
        long aux = 0;
        int id_aux = 0;
        for(int i = 0; i < numbers.size(); i++) {
            id_aux = i;
            for(int j = i + 1; j < numbers.size(); j++) {
                if(numbers.get(j) < numbers.get(id_aux)) {
                    id_aux = j;
                }
            }
            aux = numbers.get(i);
            numbers.set(i, numbers.get(id_aux));
            numbers.set(id_aux, aux);
        }
    }

    public void insertionSort(List<Long> numbers) {
        long aux = 0;
        int j = 0;
        for(int i = 0; i < numbers.size(); i++) {
            aux = numbers.get(i);
            j = i - 1;
            while (j >= 0 && numbers.get(j) > aux) {
                numbers.set(j+1, numbers.get(j));
                j -= 1;
            }
            numbers.set(j+1, aux);
        }
    }

    public List<Long> getNums() {
        return this.nums;
    }
}

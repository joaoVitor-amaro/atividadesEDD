#include <stdio.h>

int maximo(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int maxResto = maximo(arr, n - 1);
    return (arr[n - 1] > maxResto) ? arr[n - 1] : maxResto;
}

int main() {
    int numeros[] = {3, 7, 2, 9, 1};
    int n = sizeof(numeros) / sizeof(numeros[0]);

    printf("Maior elemento: %d\n", maximo(numeros, n));
    return 0;
}

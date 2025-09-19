#include <stdio.h>
#include <string.h>

void inverter(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return; 
    }

    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    inverter(str, inicio + 1, fim - 1);
}

int main() {
    char palavra[] = "recursao";
    inverter(palavra, 0, strlen(palavra) - 1);
    printf("%s\n", palavra);
    return 0;
}

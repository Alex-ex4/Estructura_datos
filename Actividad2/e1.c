#include <stdio.h>

int sumaDigitos(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumaDigitos(n / 10);
}

int main() {
    int num;
    int suma, maxSuma = -1, numMayor = 0;
    int resultado;

    printf("Ingrese numeros enteros positivos (0 para terminar):\n");

    while (1) {
        printf("Numero: ");
        resultado = scanf("%d", &num);

        if (resultado != 1) {
            printf("Error: Debe ingresar un numero entero.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (num < 0) {
            printf("Error: Solo se permiten numeros positivos.\n");
            continue;
        }

        if (num == 0) {
            break;
        }

        suma = sumaDigitos(num);
        printf("Suma de digitos de %d = %d\n", num, suma);

        if (suma > maxSuma) {
            maxSuma = suma;
            numMayor = num;
        }
    }

    if (maxSuma == -1) {
        printf("No se ingresaron datos.\n");
    } else {
        printf("\nEl numero con mayor suma de digitos es: %d\n", numMayor);
        printf("Con suma de digitos: %d\n", maxSuma);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void imprimirRango(int a, int b) {
    if (a > b)
        return;

    printf("%d ", a);
    imprimirRango(a + 1, b);
}

int main() {
    int a, b;
    int res;

    system("cls"); 

    while (1) {
        printf("Ingrese el valor de A: ");
        res = scanf("%d", &a);

        if (res != 1) {
            printf("Error: Debe ingresar un numero entero.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    while (1) {
        printf("Ingrese el valor de B: ");
        res = scanf("%d", &b);

        if (res != 1) {
            printf("Error: Debe ingresar un numero entero.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    if (a > b) {
        printf("Error: A debe ser menor o igual que B.\n");
    } else {
        printf("\nNumeros del rango:\n");
        imprimirRango(a, b);
    }

    printf("\n\nPresione Enter para salir.....");
    getchar(); 
    getchar(); 

    return 0;
}
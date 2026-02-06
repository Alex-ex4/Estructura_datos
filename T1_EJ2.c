#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAX 50
#define DESC 50

typedef struct {
    int clave;
    char descripcion[DESC];
    int existencia;
    int minimo;
    float precio;
} Producto;

void limpiarBuffer() {
    while (getchar() != '\n');
}

int leerEntero() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Error: Ingrese un numero entero valido: ");
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

float leerFloat() {
    float x;
    while (scanf("%f", &x) != 1) {
        printf("Error: Ingrese un numero valido: ");
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

int main() {
    Producto productos[MAX];
    Producto *p = productos;

    int n;

    do {
        printf("Cantidad de productos: ");
        n = leerEntero();
    } while (n <= 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        int repetido;

        do {
            repetido = 0;
            printf("\nClave del producto: ");
            (p + i)->clave = leerEntero();

            if ((p + i)->clave <= 0) {
                repetido = 1;
            } else {
                for (int j = 0; j < i; j++) {
                    if ((p + j)->clave == (p + i)->clave) {
                        repetido = 1;
                        printf("Error: clave repetida.\n");
                        break;
                    }
                }
            }
        } while (repetido);

        printf("Descripcion: ");
        fgets((p + i)->descripcion, DESC, stdin);
        (p + i)->descripcion[strcspn((p + i)->descripcion, "\n")] = '\0';

        do {
            printf("Existencia: ");
            (p + i)->existencia = leerEntero();
        } while ((p + i)->existencia < 0);

        do {
            printf("Minimo a mantener: ");
            (p + i)->minimo = leerEntero();
        } while ((p + i)->minimo < 0);

        do {
            printf("Precio unitario: ");
            (p + i)->precio = leerFloat();
        } while ((p + i)->precio <= 0);
    }

int opcion;
do {
    system("cls");   

    printf("\n------ MENU ------\n");
    printf("1. Venta de producto\n");
    printf("2. Reabastecer producto\n");
    printf("3. Actualizar precio\n");
    printf("4. Informar producto\n");
    printf("0. Salir\n");
    printf("Opcion: ");
    opcion = leerEntero();

    if (opcion == 0) break;

    if (opcion < 1 || opcion > 4) {
        printf("Opcion invalida.\n");
        printf("\nPresione ENTER para continuar");
        getchar();          
        continue;
    }

    int clave, cantidad;
    float porcentaje;
    int encontrado = 0;

    printf("Clave del producto: ");
    clave = leerEntero();

    for (int i = 0; i < n; i++) {
        if ((p + i)->clave == clave) {
            encontrado = 1;

            switch (opcion) {

            case 1:
                do {
                    printf("Cantidad vendida: ");
                    cantidad = leerEntero();
                } while (cantidad <= 0);

                if ((p + i)->existencia - cantidad < 0) {
                    printf("No hay suficiente existencia.\n");
                } else {
                    (p + i)->existencia -= cantidad;
                    if ((p + i)->existencia < (p + i)->minimo) {
                        printf("ADVERTENCIA: existencia por debajo del minimo.\n");
                    }
                }
                break;

            case 2:
                do {
                    printf("Cantidad comprada: ");
                    cantidad = leerEntero();
                } while (cantidad <= 0);

                (p + i)->existencia += cantidad;
                break;

            case 3:
                do {
                    printf("Porcentaje de aumento: ");
                    porcentaje = leerFloat();
                } while (porcentaje <= 0);

                (p + i)->precio += (p + i)->precio * (porcentaje / 100);
                break;

            case 4:
                printf("\nCLAVE: %d\n", (p + i)->clave);
                printf("Descripcion: %s\n", (p + i)->descripcion);
                printf("Existencia: %d\n", (p + i)->existencia);
                printf("Minimo: %d\n", (p + i)->minimo);
                printf("Precio: %.2f\n", (p + i)->precio);
                break;
            }

            printf("\nPresione ENTER para volver al menu");
            getchar();
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
        printf("\nPresione ENTER para continuar");
        getchar();
    }

} while (1);
    return 0;
}
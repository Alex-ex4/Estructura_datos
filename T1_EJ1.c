#include <stdio.h>
#include <stdlib.h>

#define DESTINOS 4
#define VUELOS 3
#define MAX_PEDIDOS 50

void limpiarBuffer() {
    while (getchar() != '\n');
}

int leerEntero() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Entrada invalida. Ingrese un numero: ");
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

int main() {
    int plazas[DESTINOS][VUELOS];
    int *pPlazas = &plazas[0][0];

    int pedidosRechazados[MAX_PEDIDOS];
    int cantidadesRechazadas[MAX_PEDIDOS];
    int pedidosUsados[MAX_PEDIDOS];

    int *pPedidosR = pedidosRechazados;
    int *pCantidadesR = cantidadesRechazadas;
    int *pPedidosU = pedidosUsados;

    int totalRechazados = 0;
    int totalPedidos = 0;

    for (int i = 0; i < DESTINOS; i++) {
        for (int j = 0; j < VUELOS; j++) {
            do {
                printf("Plazas disponibles - Destino %d Vuelo %d: ", i + 1, j + 1); *(pPlazas + i * VUELOS + j) = leerEntero();
            } while (*(pPlazas + i * VUELOS + j) < 0);
        }
    }

    int seguir = 1;
    while (seguir) {
        int numPedido, destino, vuelo, cantidad;
        int repetido;

        do {
            repetido = 0;
            printf("\nNumero de pedido: ");
            numPedido = leerEntero();

            if (numPedido <= 0) {
                repetido = 1;
            } else {
                for (int i = 0; i < totalPedidos; i++) {
                    if (*(pPedidosU + i) == numPedido) {
                        repetido = 1;
                        printf("Error: El numero de pedido ya existe.\n");
                        break;
                    }
                }
            }
        } while (repetido);

        *(pPedidosU + totalPedidos) = numPedido;
        totalPedidos++;

        do {
            printf("Destino (1-4): ");
            destino = leerEntero();
        } while (destino < 1 || destino > 4);

        do {
            printf("Vuelo (1-3): ");
            vuelo = leerEntero();
        } while (vuelo < 1 || vuelo > 3);

        do {
            printf("Cantidad de pasajes: ");
            cantidad = leerEntero();
        } while (cantidad <= 0);

        destino--;
        vuelo--;

        int *vueloActual = pPlazas + destino * VUELOS + vuelo;

        if (cantidad > *vueloActual) {
            printf("No Hay Cantidad De Plazas Disponibles\n");
            *(pPedidosR + totalRechazados) = numPedido;
            *(pCantidadesR + totalRechazados) = cantidad;
            totalRechazados++;
        } else {
            *vueloActual -= cantidad;
        }

        do {
            printf("Desea ingresar otro pedido? (1=SI / 0=NO): ");
            seguir = leerEntero();
        } while (seguir != 0 && seguir != 1);
    }

    printf("\nPlazas Sobrantes Por Vuelo\n");
    for (int i = 0; i < DESTINOS; i++) {
        for (int j = 0; j < VUELOS; j++) {
            printf("Destino %d Vuelo %d: %d plazas\n", i + 1, j + 1, *(pPlazas + i * VUELOS + j));
        }
    }

    if (totalRechazados > 0) {
        printf("\nPedidos Rechazados\n");
        for (int i = 0; i < totalRechazados; i++) {
            printf("Pedido %d - Pasajes solicitados: %d\n", *(pPedidosR + i),*(pCantidadesR + i));
        }
    }

    system("pause");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void limpiarBuffer() {
    while (getchar() != '\n');
}

int leerEntero() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Error: Ingrese un numero valido: ");
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

void insertarFinal(Nodo **inicio, Nodo **fin, int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (*inicio == NULL) {
        *inicio = nuevo;
        *fin = nuevo;
    } else {
        (*fin)->sig = nuevo;
        *fin = nuevo;
    }
}

void mostrarLista(Nodo *inicio) {
    if (inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    printf("Lista:\n");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dato);
        inicio = inicio->sig;
    }
    printf("NULL\n");
}

void eliminarMayores(Nodo **inicio, Nodo **fin, int limite) {

    Nodo *actual = *inicio;
    Nodo *anterior = NULL;

    while (actual != NULL) {

        if (actual->dato > limite) {

            Nodo *temp = actual;

            if (anterior == NULL) { 
                *inicio = actual->sig;
                actual = *inicio;
            } else {
                anterior->sig = actual->sig;
                actual = actual->sig;
            }

            if (temp == *fin) {
                *fin = anterior;
            }

            free(temp);

        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }

    printf("Eliminacion completada.\n");
}

void liberarLista(Nodo **inicio) {
    Nodo *actual = *inicio;

    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->sig;
        free(temp);
    }

    *inicio = NULL;
}

int main() {

    Nodo *inicio = NULL;
    Nodo *fin = NULL;

    int cantidad;

    srand(time(NULL));

    system("cls");

    do {
        printf("Cantidad de numeros aleatorios a generar: ");
        cantidad = leerEntero();
    } while (cantidad <= 0);

    for (int i = 0; i < cantidad; i++) {
        int numero = rand() % 100 + 1;
        insertarFinal(&inicio, &fin, numero);
    }

    system("cls");

    printf("Lista generada:\n");
    mostrarLista(inicio);

    printf("\nPresione ENTER para continuar...");
    getchar();

    int limite;

    system("cls");

    printf("Lista actual:\n");
    mostrarLista(inicio);

    printf("\nEliminar nodos mayores a: ");
    limite = leerEntero();

    eliminarMayores(&inicio, &fin, limite);

    printf("\nPresione ENTER para ver la lista final...");
    getchar();

    system("cls");

    printf("Lista despues de eliminar:\n");
    mostrarLista(inicio);

    printf("\nPresione ENTER para salir...");
    getchar();

    liberarLista(&inicio);

    return 0;
}
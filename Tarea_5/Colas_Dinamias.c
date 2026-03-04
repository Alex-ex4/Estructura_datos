#include <stdio.h>
#include <stdlib.h>

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

void insertarFinal(Nodo **frente, Nodo **final, int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (*frente == NULL) {
        *frente = nuevo;
        *final = nuevo;
    } else {
        (*final)->sig = nuevo;
        *final = nuevo;
    }
}

void insertarPreferencial(Nodo **frente, Nodo **final, int valor) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error de memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = *frente;

    *frente = nuevo;

    if (*final == NULL) {
        *final = nuevo;
    }
}

void abandonarCola(Nodo **frente, Nodo **final, int valor) {

    if (*frente == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    Nodo *actual = *frente;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual == NULL) {
        printf("Persona no encontrada en la cola.\n");
        return;
    }

    if (anterior == NULL) { 
        *frente = actual->sig;
        if (*frente == NULL)
            *final = NULL;
    } else {
        anterior->sig = actual->sig;
        if (actual == *final)
            *final = anterior;
    }

    free(actual);
    printf("Persona eliminada correctamente.\n");
}

void mostrarCola(Nodo *frente) {
    if (frente == NULL) {
        printf("La cola esta vacia.\n");
        return;
    }

    printf("Cola actual:\n");
    while (frente != NULL) {
        printf("%d -> ", frente->dato);
        frente = frente->sig;
    }
    printf("NULL\n");
}

int main() {

    Nodo *frente = NULL;
    Nodo *final = NULL;

    int opcion;

    do {
        printf("\nMENU\n");
        printf("1. Llegada normal a la cola\n");
        printf("2. Llegada preferencial a la cola\n");
        printf("3. Abandono de la cola\n");
        printf("4. Mostrar cola\n");
        printf("0. Salir\n");
        printf("Opcion: ");

        opcion = leerEntero();

        if (opcion == 0) break;

        if (opcion < 0 || opcion > 4) {
            printf("Opcion invalida.\n");
            continue;
        }

        int numero;

        switch (opcion) {

        case 1:
            printf("Numero de persona: ");
            numero = leerEntero();
            insertarFinal(&frente, &final, numero);
            break;

        case 2:
            printf("Numero de persona preferencial: ");
            numero = leerEntero();
            insertarPreferencial(&frente, &final, numero);
            break;

        case 3:
            printf("Numero de persona que abandona: ");
            numero = leerEntero();
            abandonarCola(&frente, &final, numero);
            break;

        case 4:
            mostrarCola(frente);
            break;
        }

    } while (1);

    return 0;
}
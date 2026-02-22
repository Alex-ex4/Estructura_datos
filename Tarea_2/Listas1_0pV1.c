#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct nodo
  {
	char dato;
	struct nodo *siguiente;
  };

typedef struct nodo NODO;
typedef NODO *NODOSIG;

void insertar_frente(NODOSIG *, char);
void insertar_final(NODOSIG *, char);
void insertar_medio(NODOSIG *, char);

char borrar_frente(NODOSIG *);
char borrar_final(NODOSIG *);
char borrar_medio(NODOSIG *, char);

void ordenar_ascendente(NODOSIG);
void ordenar_descendente(NODOSIG);

void printlista(NODOSIG);

void instrucciones(void);

int isempty(NODOSIG);

int main()
{
 NODOSIG lista = NULL;
 int op;
 char ele;

	do
	 {
		system("cls");
		instrucciones();
		printf("\n\n ? ");
		scanf("%d", &op);
		switch (op) 
		 {
			case 1:
				printf("\n Introduzca el elemento: ");
				scanf("\n %c", &ele);
				insertar_frente(&lista, ele);
				printlista(lista);
				printf("\n\n Oprima cualquier tecla para continuar ");
				getch();
				break;
			case 2:
				printf("\n Introduzca el elemento: ");
				scanf("\n %c", &ele);
				insertar_final(&lista, ele);
				printlista(lista);
				printf("\n\n Oprima cualquier tecla para continuar ");
				getch();
				break;
			case 3:
				printf("\n Introduzca el elemento: ");
				scanf("\n %c", &ele);
				insertar_medio(&lista, ele);
				printlista(lista);
				printf("\n\n Oprima cualquier tecla para continuar ");
				getch();
				break;
			case 4:
				if (!isempty(lista))
					if (borrar_frente(&lista)=='a')
					  { 
						printlista(lista);
						printf("\n\n Oprima cualquier tecla para continuar ");

				      }
					else
					  {	
						printf("\n\n\n\t\tLista esta vacia\n\n");
						free(lista);
						lista=NULL;
						printf("\n\n Oprima cualquier tecla para continuar ");
					  }
				getch();
				break;
			case 5:
				if (!isempty(lista))
					if (borrar_final(&lista)=='a')
					  {					  
						printlista(lista);
						printf("\n\n Oprima cualquier tecla para continuar ");
				      }
					else
					  {
						printf("\n\n\n\t\tLista esta vacia\n\n");
						free(lista);
						lista=NULL;
						printf("\n\n Oprima cualquier tecla para continuar ");
					  }
				getch();
				break;
			case 6:
				if (!isempty(lista)) 
				  {
					printf("Elemento a borrar: ");
					scanf("\n%c", &ele);
					if (borrar_medio(&lista, ele)) 
					  {
						printf("%c borrado", ele);
						printlista(lista);
					  }
					else
						printf("%c no existe \n\n",ele);
				  }
				
				else
				  {
					printf("Lista esta vacia\n\n");
					free(lista);
					lista=NULL;
					printf("\n\n Oprima cualquier tecla para continuar ");
				  }
				getch();
				break;

			case 7:
				if (!isempty(lista))
				{
					ordenar_ascendente(lista);
					printf("\nLista ordenada ascendente\n");
					printlista(lista);
				}
				else
					printf("\nNo se puede ordenar, la lista esta vacia\n");
				getch();
				break;

			case 8:
				if (!isempty(lista))
				{
					ordenar_descendente(lista);
					printf("\nLista ordenada descendente\n");
					printlista(lista);
				}
				else
					printf("\nNo se puede ordenar, la lista esta vacia\n");
				getch();
				break;
					}
				}while (op != 9);
				system("cls");
				printf("\n\n\n\n\n\n\t\t\t\t F I N\n");
				getch();
 			return 0;
}


void instrucciones()
{
  printf("\n\n\n\t\t OPERACIONES CON LISTAS ENCADENADAS\n\n");
  printf("\n\t\t\t Que opcion desea :\n\n"
	"   \t\t 1 insertar frente\n"
	"   \t\t 2 insertar final\n"
	"   \t\t 3 insertat en medio\n"
	"   \t\t 4 eliminar frente\n"
	"   \t\t 5 eliminar final\n"
	"   \t\t 6 eliminar en medio\n"
	"   \t\t 7 ordenar ascendente\n"
	"   \t\t 8 ordenar descendente\n"
	"   \t\t 9 salir\n"
	);
}

void insertar_frente(NODOSIG *lista, char valor)
{
  NODOSIG nuevo;
	nuevo = malloc(sizeof(NODO));
	if (nuevo != NULL) 
	  {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
		nuevo -> siguiente = *lista;
		*lista = nuevo;
	  }
}


void insertar_medio(NODOSIG *lista, char valor)
{
  NODOSIG nuevo, previo, actual;
	nuevo = malloc(sizeof(NODO));
	if (nuevo != NULL) 
	  {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
		previo = NULL;
		actual = *lista;
		while (actual != NULL && valor > actual -> dato) 
		  {
		 	previo = actual;
			actual = actual -> siguiente;
		  }
		if(actual!= NULL)
		 {
		   previo -> siguiente = nuevo;
		   nuevo -> siguiente = actual;
	     }
	     else
	       printf("\n\n\t No se puede insertar en medio\n");
	  }
}


void insertar_final(NODOSIG *lista, char valor)
{
  NODOSIG nuevo, previo, actual;
	nuevo = malloc(sizeof(NODO));
	if (nuevo != NULL) 
	  {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
		previo = NULL;
		actual = *lista;
		while (actual != NULL) 
		  {
			previo = actual;
			actual = actual -> siguiente;
		  }
		if (previo == NULL) 
		  {
			nuevo -> siguiente = *lista;
			*lista = nuevo;
		  }
		else 
		  {
			previo -> siguiente = nuevo;
			nuevo -> siguiente = actual;
		  }
	  }
}


void printlista(NODOSIG actual)
{
	if (actual == NULL)
		printf("Lista vacia \n\n");
	else 
	 {
		printf("\n\n La lista es: \n\n");
		while (actual != NULL) 
		  {
			printf("%c --> ",actual -> dato);
			actual = actual -> siguiente;
		  } 
		printf("NULL \n\n");
	 }
}


char borrar_frente(NODOSIG *lista)
{
  NODOSIG  temporal,
	  previo;

	previo= (*lista)-> siguiente;
	if (previo != NULL) 
	  {
		temporal = *lista;
		*lista = (*lista) -> siguiente;
		free(temporal);
		return 'a';
	  }
	return '\0';
}


char borrar_final(NODOSIG *lista)
{
  NODOSIG  previo, actual, temporal;
	previo = NULL;
	actual = *lista;
	if (actual->siguiente != NULL) 
	  {
		while (actual->siguiente != NULL )
		  {
			previo = actual;
			actual = actual -> siguiente;
		  }
		temporal=actual;
		free(temporal);
		previo->siguiente = NULL;
		return 'a';
	  }  
	return '\0';
}


char borrar_medio(NODOSIG *lista, char valor)
{
  NODOSIG  previo, actual, temporal;
	previo = *lista;
	actual = (*lista) -> siguiente;
	while (actual!= NULL && actual -> dato != valor)
	  {
		previo = actual;
		actual = actual -> siguiente;
	  }
	if (actual != NULL && actual->siguiente != NULL) 
	  {
		temporal = actual;
		previo -> siguiente = actual -> siguiente;
		free(temporal);
		return(valor);
	  }
	return '\0';
}

void ordenar_ascendente(NODOSIG lista)
{
    NODOSIG actual, siguiente;
    char temp;

    for (actual = lista; actual != NULL; actual = actual->siguiente)
    {
        for (siguiente = actual->siguiente; siguiente != NULL; siguiente = siguiente->siguiente)
        {
            if (actual->dato > siguiente->dato)
            {
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
        }
    }
}

void ordenar_descendente(NODOSIG lista)
{
    NODOSIG actual, siguiente;
    char temp;

    for (actual = lista; actual != NULL; actual = actual->siguiente)
    {
        for (siguiente = actual->siguiente; siguiente != NULL; siguiente = siguiente->siguiente)
        {
            if (actual->dato < siguiente->dato)
            {
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;
            }
        }
    }
}


int isempty(NODOSIG lista)
 {
   return lista == NULL;
 }		    

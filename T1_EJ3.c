#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct alumno{
    char nom[' '];
    long int matr;
    int sems;
    float califs[' '];
    char carr[' '];
};

typedef struct alumno Alumno;

int insertar_datos(Alumno *ap);
void normalizar(char *cad);
void prom_mayor_9(Alumno *ap, int n);
void prom_9_sems(Alumno *ap, int n);
void mejor_prom_comp(Alumno *ap, int n);


int main(){
    Alumno alums[' '],*ap;
    int op,n=0;
    char aux[' '];    

    do{
        system("cls");
        printf("----MENU PRINCIPAL----\n\n");
        printf("1. Insertar datos de alumnos\n");
        printf("2. Alumnos con promedio general mayor a 9\n");
        printf("3. Alumnos de Economia con promedio mayor a 9 en cada semestre\n");
        printf("4. Mejor promedio de Ingenieria en Computacion\n");
        printf("5. Salir\n\n");
        printf("\tIngrese una opcion: ");
        fgets(aux,sizeof(aux),stdin);
        op=atoi(aux);

        switch(op){
            case 1:
                n=insertar_datos(&alums[0]);
                break;
            case 2:
                if (n<1){
                    printf("\n\tNo existen datos de alumnos\n\n");
                    system("pause");
                    break;
                }
                else{
                    prom_mayor_9(&alums[0],n);
                }
                break;
            case 3:
                if (n<1){
                    printf("\n\tNo existen datos de alumnos\n\n");
                    system("pause");
                    break;
                }
                else{
                    prom_9_sems(&alums[0],n);
                }
                break;
            case 4:
                if (n<1){
                    printf("\n\tNo existen datos de alumnos\n\n");
                    system("pause");
                    break;
                }
                else{
                    mejor_prom_comp(&alums[0],n);
                }
                break;
            case 5:
                printf("Saliendo del programa...");
                break;
            default:
                printf("\n\tOpcion no valida, intente de nuevo\n\n");
                system("pause");
                break;
        }

    }while(op!=5);
}

int insertar_datos(Alumno *ap){
    int cont=0,i,op;
    char temp[' '];
    do
    {       

        system("cls");
        printf("----INSERTAR DATOS DE ALUMNOS----\n\n"); 
        do
        {
            printf("\nIngrese la matricula del alumno %d: ", cont+1);
            fgets(temp,sizeof(temp),stdin);
            ap->matr=atoi(temp);
        } while (ap->matr<1);
        
        do
        {
            printf("\nIngrese nombre del alumno %d: ", cont+1);
            fgets(ap->nom, sizeof(ap->nom), stdin);
            ap->nom[strcspn(ap->nom, "\n")] = '\0';
        } while (strlen(ap->nom)<1);
        
        

        do{
            printf("\nIngrese el numero de semestres: ");
            fgets(temp, sizeof(temp), stdin);
            ap->sems=atoi(temp);
        } while (ap->sems<1 || ap->sems>10);

        for(i=0;i<ap->sems;i++){
            do{
                printf("\nIngrese la calificacion %d: ", i+1);
                fgets(temp,sizeof(temp),stdin);
                ap->califs[i]=atof(temp);
            }while(ap->califs[i]<0 || ap->califs[i]>100);
        }

        printf("\nIngrese la carrera alumno %d: ", cont+1);
        fgets(ap->carr, sizeof(ap->carr), stdin);
        normalizar(ap->carr);

        cont++;
        ap++;
        
        do
        {
            printf("\n\n\t Desea agregar otro alumno [1-Si/2-No]: ");
            fgets(temp,sizeof(temp),stdin);
            op=atoi(temp);
        } while (op!=1 && op!=2);

    } while (op==1);
    
    return cont;
}
void prom_mayor_9(Alumno *ap, int n){
    int i,j,cont=0;
    float prom,suma;
    system("cls");
    printf("----ALUMNOS CON PROMEDIO GENERAL MAYOR A 9----\n\n");
    for(i=0;i<n;i++){
        suma=0;
        for(j=0;j<ap->sems;j++){
            suma+=ap->califs[j];
        }
        prom=suma/ap->sems;        
        if (prom>90){
            cont++;
            printf("Alumno %d\n", cont);
            printf("\tNombre: %s\n", ap->nom);
            printf("\tMatricula: %ld\n", ap->matr);
        }
        ap++;
    }
    if(cont==0){
        printf("\n\tNo hay alumnos con promedio mayor a 9\n");
    }
    system("pause");
}


void prom_9_sems(Alumno *ap, int n){
    int i,j,cont=0,contsems;
    system("cls");
    printf("----ALUMNOS CON PROMEDIO MAYOR A 9 EN CADA SEMESTRE----\n\n");
    for(i=0;i<n;i++){
        contsems=0;
        for(j=0;j<ap->sems;j++){
            if(ap->califs[j]>90){
                contsems++;
            }
        }       
        if (strcmp(ap->carr,"economia")==0 && contsems==ap->sems){
            cont++;
            printf("Alumno %d\n", cont);
            printf("\tNombre: %s\n", ap->nom);
            printf("\tMatricula: %ld\n", ap->matr);
        }
        ap++;
    }
    if(cont==0){
        printf("\n\tNo hay alumnos de Economia con promedio mayor a 9 en cada semestre\n");
    }
    system("pause");
}

void mejor_prom_comp(Alumno *ap, int n){
    int i,j,encontrado=0;
    float suma,prom,max_prom=-1;
    Alumno *mejor=NULL;

    for(i=0;i<n;i++){
        if(strcmp(ap->carr,"ingenieria en computacion")==0){
            suma=0;
            for(j=0;j<ap->sems;j++){
                suma+=ap->califs[j];
            }
            prom=suma/ap->sems;

            if(prom>max_prom){
                max_prom=prom;
                mejor=ap;
                encontrado=1;
            }
        }
        ap++;
    }
    
    system("cls");
    if(encontrado){
        printf("----MEJOR PROMEDIO DE INGENIERIA EN COMPUTACION----\n\n");
        printf("Nombre: %s\n", mejor->nom);
        printf("Matricula: %ld\n", mejor->matr);
    } else {
        printf("No hay alumnos de Ingenieria en Computacion\n");
    }
    system("pause");
}

void normalizar(char *cad){
    int i=0,j=0;
    char aux[' '],c;

    cad[strcspn(cad, "\n")]='\0';

    while(cad[i]!='\0'){
        c=cad[i];

        aux[j]=tolower(c);
        i++;
        j++;
    }
    aux[j]='\0';

    strcpy(cad,aux);
}

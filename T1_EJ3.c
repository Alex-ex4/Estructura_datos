#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
    char nom[' '];
    long int matr;
    int sems;
    float califs[' '];
    char carr[' '];
};

typedef struct alumno Alumno;

int insertar_datos(Alumno *ap);
void prom_mayor_9(Alumno *ap, int n);
void prom_9_sems(Alumno *ap, int n);


int main(){
    Alumno alums[' '],*ap;
    int op, n=0;    

    do{
        system("cls");
        printf("----MENU PRINCIPAL----\n\n");
        printf("1. Insertar datos de alumnos\n");
        printf("2. Alumnos con promedio general mayor a 9\n");
        printf("3. Alumnos con promedio mayor a 9 en cada semestre\n");
        printf("4. Salir\n\n");
        printf("\tIngrese una opcion: ");
        scanf("%d", &op);
        getchar(); 

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
                printf("Saliendo del programa...");
                break;
        }

    }while(op!=4);
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
            fflush(stdin);
            printf("\nIngrese la matricula del alumno %d: ", cont+1);
            fgets(temp, sizeof(temp), stdin);
            ap->matr=atoi(temp);
        } while (ap->matr<1);
        
        
        fflush(stdin);
        printf("\nIngrese nombre del alumno %d: ", cont+1);
        fgets(ap->nom, sizeof(ap->nom), stdin);

        do{
            printf("\nIngrese el numero de semestres: ");
            fflush(stdin);
            fgets(temp, sizeof(temp), stdin);
            ap->sems=atoi(temp);
        } while (ap->sems<1 || ap->sems>10);

        for(i=0;i<ap->sems;i++){
            do{
                printf("\nIngrese la calificacion %d: ", i+1);
                fflush(stdin);
                fgets(temp,sizeof(temp),stdin);
                ap->califs[i]=atof(temp);
            }while(ap->califs[i]<0 || ap->califs[i]>100);
        }

        fflush(stdin);
        printf("\nIngrese la carrera alumno %d: ", cont+1);
        fgets(ap->carr, sizeof(ap->carr), stdin);

        cont++;
        ap++;
        
        do
        {
            fflush(stdin);
            printf("\n\n\t Desea agregar otro alumno [1-Si/2-No]: ");
            scanf("%d",&op);
        } while (op!=1 && op!=2);

    } while (op==1);
    
    return cont;
}
void prom_mayor_9(Alumno *ap, int n){
    int i,j,cont=0;
    float prom, suma=0;
    system("cls");
    printf("----ALUMNOS CON PROMEDIO GENERAL MAYOR A 9----\n\n");
    for(i=0;i<n;i++){
        for(j=0;j<ap->sems;j++){
            suma+=ap->califs[j];
        }
        prom=suma/ap->sems;        
        if (prom>90){
            cont++;
            printf("Alumno %d\n", cont);
            printf("\tNombre: %s\n", ap->nom);
            printf("\tMatricula: %d\n", ap->matr);
        }
        ap++;
    }
    if(cont==0){
        printf("\n\tNo hay alumnos con promedio mayor a 9\n");
    }
    system("pause");
}
void prom_9_sems(Alumno *ap, int n){
    int i,j,cont=0, contsems;
    system("cls");
    printf("----ALUMNOS CON PROMEDIO MAYOR A 9 EN CADA SEMESTRE----\n\n");
    for(i=0;i<n;i++){
        contsems=0;
        for(j=0;j<ap->sems;j++){
            if(ap->califs[j]>90){
                contsems++;
            }
        }       
        if (contsems==ap->sems){
            cont++;
            printf("Alumno %d\n", cont);
            printf("\tNombre: %s\n", ap->nom);
            printf("\tMatricula: %d\n", ap->matr);
        }
        ap++;
    }
    if(cont==0){
        printf("\n\tNo hay alumnos con promedio mayor a 9 en cada semestre\n");
    }
    system("pause");
}

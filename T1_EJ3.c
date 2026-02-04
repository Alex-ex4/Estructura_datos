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
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        getchar(); 

        switch(op){
            case 1:
                n=insertar_datos(&alums[0]);
                break;
            case 2:
            if (n<1){
                printf("No existen datos de alumnos");
                break;
            }
            else{
                prom_mayor_9(&alums[0],n);
            }
                break;
            case 3:
            if (n<1){
                printf("No existen datos de alumnos");
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
    int cont=0,i;
    char temp[' '];
    system("cls");
    printf("Ingrese la matricula del alumno %d: ", cont+1);
    fflush(stdin);
    fgets(temp, sizeof(temp), stdin);
    ap->matr=atoi(temp);

    fflush(stdin);
    printf("Ingrese nombre del alumno %d: ", cont+1);
    fgets(ap->nom, sizeof(ap->nom), stdin);

    printf("Ingrese el numero de semestres: ");
    fflush(stdin);
    fgets(temp, sizeof(temp), stdin);
    ap->sems=atoi(temp);

    for(i=0;i<ap->sems;i++){
        printf("Ingrese la calificacion %d: ", i+1);
        fflush(stdin);
		fgets(temp,sizeof(temp),stdin);
		ap->califs[i]=atof(temp);
    }

    fflush(stdin);
    printf("Ingrese la carrera alumno %d: ", cont+1);
    fgets(ap->carr, sizeof(ap->carr), stdin);

    cont++;
    ap++;

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
    system("pause");
}
void prom_9_sems(Alumno *ap, int n){
    int i,j,cont=0, contsems;
    system("cls");
    printf("----ALUMNOS CON PROMEDIO MAYOR A 9 EN CADA SEMESTRE----\n\n");
    for(i=0;i<n;i++){
        contsems=0;
        for(j=0;j<ap->sems;j++){
            if(ap->califs[j>90]){
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
    system("pause");
}
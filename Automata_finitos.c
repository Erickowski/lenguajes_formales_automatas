/*
Automata finito, opcion 1
Lenguajes formales y automatas
Dr. Saturnino Job Morales Escobar
Integrantes:
-Perez Mata Erick Daniel
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct estado
{
    char nombre[15]; //Nombre estado
    char estadoS[15][15]; //Estado de salida
    char ValorE[15]; //Valor de entrada
    int cont;
} CEstado;

void menu(void)
{
    printf("B I E N V E N I D O\n");
    printf("Selecciona una opcion\n");
    printf("1.- Registrar alfabeto\n");
    printf("2.- Ver alfabeto\n");
    printf("3.- Eliminar alfabeto\n");
    printf("4.- Registrar estado\n");
    printf("5.- Ver estados\n");
    printf("6.- Eliminar estados\n");
    printf("7.- Capturar cadena\n");
    printf("8.- Salir\n");
}

int main (void)
{
    CEstado conjunto[10];
    char alfabeto[15],cadena[15];
    int opc,x=0,y=0,z=0;
    int i,j=0,k;
    int a=0;
    do
    {
        menu();
        scanf("%i",&opc);
        system("cls");
        switch(opc)
        {
        case 1:
            do
            {
                printf("Elemento a agregar: ");
                scanf("%s",&alfabeto[x]);
                for(i=0; i<strlen(alfabeto); i++)
                {
                    if(alfabeto[x]==alfabeto[i] && i!=x)
                    {
                        printf("Ese elemento ya esta en el alfabeto\n");
                        i=-1;
                        break;
                    }
                }
            }
            while(i==-1);
            printf("El elemento fue correctamente agregado\n");
            x++;
            break;
        case 2:
            printf("A L F A B E T O\n");
            if(x==0)
            {
                printf("Alfabeto vacio\n");
                break;
            }
            printf("Elementos: { ");
            for(i=0; i<x; i++)
            {
                printf("%c",alfabeto[i]);
                if(i<x-1) printf(" , ");
            }
            printf(" }\n");
            break;
        case 3:
            x=0;
            printf("Alfabeto eliminado\n");
            break;
        case 4:
            printf("Ingrese nombre del estado:");
            scanf("%s",&conjunto[y].nombre);
            do
            {
                printf("Ingrese nombre estado de aceptacion:");
                scanf("%s",&conjunto[z].estadoS[z]);
                printf("Ingrese valor para estado de aceptacion:");
                scanf("%s",&conjunto[z].ValorE);
                do
                {
                    printf("Desea agregar otro estado final(1- Si 2-No)? ");
                    scanf("%i",&i);
                    if(i!=2 && i!=1)
                    {
                        printf("Opcion no valida\n");
                        i=-1;
                    }
                }
                while(i==-1);
                if(i==1) z++;
                conjunto[y].cont = z+1;
            }
            while(i!=2);
            y++;
            z++;
            break;
        case 5:
            k=0;
            printf("Tabla de estados de aceptacion\n");
            printf("%15s %15s %15s\n","Nombre del estado","Estado de aceptacion","Valor entrada");
            for(i=0; i<y; i++)
            {
                printf("%15s\n",&conjunto[i].nombre);
                for(j=k; j<conjunto[i].cont; j++)
                {
                    printf("%30s %15s\n",conjunto[j].estadoS[j],conjunto[j].ValorE);
                }
                k=j;
            }
            break;
        case 6:
            y=0;
            z=0;
            printf("Estados eliminados\n");
            break;
        case 7:
            do{
                a=1;
                printf("Ingrese cadena: ");
                scanf("%s",&cadena);
                for(i=0;i<strlen(cadena);i++){
                    for(j=0;j<strlen(alfabeto);j++){
                        if(strstr(cadena,alfabeto)!=0){
                                a=0;
                        }
                    }
                }
            }while(a!=0);
            printf("los elementos estan en el alfabeto");
            break;
        case 8:
            printf("Hasta luego\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        system("pause");
        printf("\n");
        system("cls");
    }
    while(opc!=8);
    return 0;
}

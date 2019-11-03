/*
APLICACION DE AUTOMATAS Y GRAMATICAS (OPCION 3)
Lenguajes formales y automatas
Dr. Saturnino Job Morales Escobar
Integrantes:
-Perez Mata Erick Daniel
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct producciones
{
    char noT[10];
    char result[10];
} pro;

typedef struct produccionesC
{
    char noT[10];
    char result[10];
} proC;
void menu(void)
{
    printf("B I E N V E N I D O\n");
    printf("Selecciona una opcion\n");
    printf("1.- Ingresar GCL\n");
    printf("2.- Ver GCL\n");
    printf("3.- Eliminar GCL\n");
    printf("4.- Obtener FNC\n");
    printf("5.- Salir\n");
}
int main (void)
{
    pro producciones[10];
    char noTerm[10][10],term[10][10],variable[10];
    char sust[10],cont[10],resul[10];
    proC produccionesC[30];
    int opc=0,op=0;
    int x=0,y=0,z=0;
    int a=0;
    int i=0,j=0,k=0,l=0;
    //Inicializaciones de prueba
    strcpy(noTerm[x++],"A");
    strcpy(noTerm[x++],"B");
    strcpy(noTerm[x++],"C");
    strcpy(term[y++],"a");
    strcpy(term[y++],"b");
    strcpy(variable,"S");
    strcpy(producciones[z].noT,"A");
    strcpy(producciones[z++].result,"E");
    strcpy(producciones[z].noT,"A");
    strcpy(producciones[z++].result,"B");
    strcpy(producciones[z].noT,"B");
    strcpy(producciones[z++].result,"CD");
    strcpy(producciones[z].noT,"S");
    strcpy(producciones[z++].result,"aAb");
    strcpy(producciones[z].noT,"S");
    strcpy(producciones[z++].result,"BA");
    do
    {
        menu();
        scanf("%i",&opc);
        switch(opc)
        {
        case 1:
            system("cls");
            if(x!=0 && y!=0 && z!=0)
            {
                printf("Primero elimina la GCL almacenado\n");
            }
            else
            {
                printf("NOTA: Landa = 'E'\n");
                do
                {
                    printf("Ingresa variable no terminal (mayusculas)\n");
                    scanf("%s",&noTerm[x]);
                    x++;
                    printf("Desea ingresar otra variable? 1-Si 2-No\n");
                    scanf("%i",&op);
                }
                while(op==1);
                do
                {
                    printf("Ingresa variable terminal (minuscula)\n");
                    scanf("%s",&term[y]);
                    y++;
                    printf("Desea ingresar otra variable? 1-Si 2-No\n");
                    scanf("%i",&op);
                }
                while(op==1);
                printf("Ingresa variable\n");
                scanf("%s",&variable);
                printf("Producciones\n");
                do
                {
                    printf("Ingresa variable no terminal (mayuscula)\n");
                    scanf("%s",&producciones[z].noT);
                    printf("Ingresa resultado de produccion\n");
                    scanf("%s",&producciones[z].result);
                    z++;
                    printf("Desea ingresar otra produccion? 1-Si 2-No\n");
                    scanf("%i",&op);
                }
                while(op==1);
            }
            break;
        case 2:
            system("cls");
            if(x==0 && y==0 && z==0)
            {
                printf("Gramatica de conexto libre no almacenada...\n");
            }
            else
            {
                printf("Gramatica de contexto libre almacenada: \n");
                printf("Variables no terminales: ");
                for(i=0; i<x; i++)
                {
                    printf("%s ",noTerm[i]);
                }
                printf("\n");
                printf("Variables terminales: ");
                for(i=0; i<y; i++)
                {
                    printf("%s ",term[i]);
                }
                printf("\n");
                printf("Variable: %s\n",variable);
                printf("Producciones:\n");
                for(i=0; i<z; i++)
                {
                    printf("%s --> %s \n",producciones[i].noT,producciones[i].result);
                }
                printf("\n");
            }
            break;
        case 3:
            x=0;
            y=0;
            z=0;
            printf("Gramatica borrada...\n");
            break;
        case 4:
            system("cls");
            if(x==0 && y==0 && z==0)
            {
                printf("Gramatica de conexto libre no almacenada...\n");
            }
            else
            {
                a = z;
                for(i=0; i<z; i++)
                {
                    strcpy (produccionesC[i].noT,producciones[i].noT);
                    strcpy (produccionesC[i].result,producciones[i].result);
                }
                //eliminar variables anulables
                for(i=0; i<a; i++)
                {
                    if(strcmp(produccionesC[i].result,"E")==0)
                    {
                        //Guarda variablle terminal
                        strcpy(sust,produccionesC[i].noT);
                        //Elimina la produccion landa
                        for(j=i; j<a; j++)
                        {
                            strcpy(produccionesC[j].noT,produccionesC[j+1].noT);
                            strcpy(produccionesC[j].result,produccionesC[j+1].result);
                        }
                        a--;
                        //Compara producciones en general
                        for(j=0; j<a; j++)
                        {
                            //Guarda resultado de produccion
                            strcpy(cont,produccionesC[j].result);
                            k=0;
                            l=0;
                            //Elimina variable no terminal de las producciones
                            while(cont[l] != '\0')
                            {
                                if(sust[0] != cont[l])
                                {
                                    resul[k] = cont[l];
                                    k++;
                                }
                                l++;
                            }
                            resul[k] = '\0';
                            //Genera nueva produccion
                            if(strcmp(resul,cont)!=0)
                            {
                                strcpy(produccionesC[a].noT,produccionesC[j].noT);
                                strcpy(produccionesC[a].result,resul);
                                a++;
                            }
                        }
                    }
                }
                //Eliminar sustituciones unitarias
                for(i=0; i<x; i++)
                {
                    for(j=0; j<a; j++)
                    {
                        //Buscamos unitarias
                        if(strcmp(noTerm[i],produccionesC[j].result)==0 && strcmp(noTerm[i],produccionesC[j].noT)!=0 && strcmp(variable,produccionesC[j].noT)!=0)
                        {
                            strcpy(sust,produccionesC[j].noT);
                            strcpy(cont,produccionesC[j].result);
                            //eliminamos unitaria
                            for(k=j; k<a; k++)
                            {
                                strcpy(produccionesC[k].noT,produccionesC[k+1].noT);
                                strcpy(produccionesC[k].result,produccionesC[k+1].result);
                            }
                            a--;
                            //generamos nuevas producciones
                            for(k=0; k<a; k++)
                            {
                                if(strcmp(produccionesC[k].noT,cont)==0)
                                {
                                    strcpy(produccionesC[a].noT,sust);
                                    strcpy(produccionesC[a].result,produccionesC[k].result);
                                    a++;
                                }
                            }
                        }
                        //break;

                    }
                }
                printf("Forma normal de Chomsky: \n");
                for(i=0; i<a; i++)
                {
                    printf("%s --> %s \n",produccionesC[i].noT,produccionesC[i].result);
                }
            }
            break;
        case 5:
            printf("Hasta luego...\n");
            break;
        default:
            printf("Opcion no valida...\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opc!=5);
}

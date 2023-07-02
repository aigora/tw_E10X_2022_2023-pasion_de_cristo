#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incremento_en_porcentaje(char tabla[22][25][1000], int num_filas, FILE *pescritura);

int main()
{
   FILE *plectura;
   FILE *pescritura;
   plectura = fopen("Def.csv", "r");
   char vectorfila[1000];
   char *elemento;
   int i=0, k=0, p=0;
   char tabla[22][25][1000];
   int fila=0;

    if (plectura == NULL)
    {
        printf("Error al abrir el fichero de lectura");
        return 0;
    }
    else
    {
    int letra, columna;
    int fila = 0;
    for(fila = 0; fila < 22; fila++)
    {
        fgets(vectorfila, sizeof(vectorfila), plectura);
        printf("Fila: %s\n", vectorfila);
        elemento = strtok(vectorfila, ",");
        columna = 0;
        while(elemento)
        {
            if (elemento == NULL){
                break;
            }
              letra = 0;
            for(letra=0; elemento[letra] != '\0'; letra++)
            {
                tabla[fila][columna][letra] = elemento[letra];
            }
            printf("fila %i columna %i: %s\n, ",fila, columna, tabla[fila][columna]);
            tabla[fila][columna][letra] = '\0';
            elemento = strtok(NULL, ",");
            columna++;
        }
    }
fclose(plectura);
    pescritura = fopen("incremento_tablas", "w");
    if (pescritura == NULL)
    {
        printf("Error al abrir el fichero de escritura");
        return 0;
    }
    else
    {
        for(k=0; k<22;k++)
        {
            fprintf(pescritura, "\n");
            for(p=0; p<25; p++)
            {
                fprintf(pescritura, "%s, ", tabla[k][p]);
            }
        }
    }
    incremento_en_porcentaje(tabla, 22 , pescritura);
    fclose(pescritura);
} 
return 0;
}

void incremento_en_porcentaje(char tabla[22][25][1000], int num_filas, FILE *pescritura)
{
    int i;
    for (i=0; i < num_filas; i++)
    {
        if(i>5)
        {
        char* palabra = tabla[i][0];
        float valorInicial = atof(&tabla[i][1]);
        float valorFinal = atof(&tabla[i][24]);

        float incremento_Porcentual = ((valorFinal - valorInicial) / valorInicial) * 100;

        printf("Incremento en la línea %d (%s): %.2f%%\n", i + 1, palabra, incremento_Porcentual);
        fprintf(pescritura, "Incremento en la línea %d (%s): %.2f%%\n", i + 1, palabra, incremento_Porcentual);
        }
    }
}



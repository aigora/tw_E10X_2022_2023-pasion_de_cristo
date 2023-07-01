#include <stdio.h>
#include <stdlib.h>

void incremento_en_porcentaje(const char tabla[][25][50], int num_filas, FILE *pescritura);

int main()
{
    int fila=0;
    const char tabla[17][25][50];
    FILE *plectura;
    FILE *pescritura;
    plectura = fopen("Def.csv", "r");
    int i = 0, j = 0, k = 0, p=0;
    char *archivo[50];
    if (plectura == NULL)
    {
        printf("Error al abrir el fichero de lectura");
        return 0;
    }
    else
    {
        while(fscanf(plectura, "%s", archivo) != EOF) 
        {
            if(*archivo == '\n')
            {
            	fila++;
            	j=0;
            	if(fila>5)
            	{
            		i++;
				}
			}
			else if(fila>5)
			{
				fscanf(plectura, " %[^\n]", &tabla[i][0]);
				for(j=0; j<25; j++)
				{
					fscanf(plectura, "%[^,]", &tabla[i][j]);
				}
			}
        }
        for(k=0; k<17;k++)
        {
        	for(p=0; p<25; p++)
        	{
        	    printf("%s, ", tabla[k][p]);
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
        	for(k=0; k<17;k++)
            {
            	fprintf(pescritura, "\n");
        	    for(p=0; p<25; p++)
        	       {
        	          fprintf(pescritura, "%s, ", tabla[k][p]);
			       }
		    }
		    incremento_en_porcentaje(tabla, 17, pescritura);
        }
    }
    
return 0;
}

void incremento_en_porcentaje(const char tabla[][25][50], int num_filas, FILE *pescritura)
{
	int i;
    for (i=0; i < num_filas; i++)
	{
        const char* palabra = tabla[i][0];
        float valorInicial = atof(&tabla[i][1][0]);
        float valorFinal = atof(&tabla[i][24][0]);

        float incremento_Porcentual = ((valorFinal - valorInicial) / valorInicial) * 100;

        printf("Incremento en la línea %d (%s): %.2f%%\n", i + 1, palabra, incremento_Porcentual);
        fprintf(pescritura, "Incremento en la línea %d (%s): %.2f%%\n", i + 1, palabra, incremento_Porcentual);
    }
}



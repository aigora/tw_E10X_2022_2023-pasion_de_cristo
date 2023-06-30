#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fila=0;
    char tabla[17][25][800];
    FILE *plectura;
    FILE *pescritura;
    plectura = fopen("Def.csv", "r");
    int i = 0, j = 0, k = 0, p=0;
    char *archivo;
    if (plectura == NULL)
    {
        printf("Error al abrir el fichero de lectura");
        return -1;
    }
    else
    {
        while(fscanf(plectura, "%s", archivo) != EOF) 
        {
            if(archivo == '\n')
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
				fscanf(plectura, " %[^\n]", &tabla[i]);
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
    }
    fclose(plectura);

return 0;
}

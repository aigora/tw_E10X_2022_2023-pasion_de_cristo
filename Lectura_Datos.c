#include <stdio.h>

void leer_fichero();

int main()
{
	leer_fichero();
	
	return 0;
}

void leer_fichero()
{
	FILE *datos_hidraulicos;
	
	datos_hidraulicos = fopen("C:/Users/gianm/Desktop/pan/Informatica_Trabajo/9_Datos_hidraulicos_03_2023.xlsx", "r");
	if (datos_hidraulicos == NULL)
	{
		printf("Error al abrir el fichero.\n");
	}
	else 
	{
		printf("El fichero se ha abierto correctamente.\n");
		fclose (datos_hidraulicos);
	}
}

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
	
	datos_hidraulicos = fopen("9_Datos_hidraulicos_03_2023.csv", "r");
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

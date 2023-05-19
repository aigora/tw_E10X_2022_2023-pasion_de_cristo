#include <stdio.h>

float cuasivarianza(float vector_3[], int tamanio_3);
void leer_fichero();
float media(float vector[], int tamanio);
float varianza(float vector_2[], int tamanio_2);

int main() 
{
    int seleccion,ayuda;

    do {
        printf("\n\tMENU:\n");
        printf("\t1. Opcion: Visualizacion de Datos\n");
        printf("\t2. Opcion: Media\n");
        printf("\t3. Opcion: Varianza\n");
        printf("\t4. Opcion: Cuasivarianza\n");
        printf("\t50. Salir 4\n");
        printf("\t100. Informacion y ayuda referente a las funciones del programa\n");

        printf("     Ingrese su opcion: ");
        scanf("%d", &seleccion);

        switch(seleccion) 
		{
            case 1:
                printf("Usted ha elegido la opcion 1\n");
                leer_fichero();
                break;
            case 2:
                printf("Usted ha elegido la opcion 2\n");
                break;
            case 3:
                printf("Usted ha elegido la opcion 3\n");
                break;
            case 4:
                printf("Usted ha elegido la opcion 4\n");
                break;
            case 50:
                printf("Saliendo del menu\n");
                break;
            case 100:
            	
            	
                printf("\tElija la funcion del programa sobre la que le interese aprender\n");
                printf(" 1 Visualizacion Datos\n 2 Media\n 3 Varianza\n 4 Cuasivarianza\n");
                scanf ("%d", &ayuda);
                
            	switch(ayuda) 
				{
            		case 1:
            			printf("\tVisualizacion de Datos: Se mostraran en pantalla todos lso datos contenidos en el fichero");
            			break;
            		case 2:
            			printf("\tMedia: La media es el calculo hecho a partir de la division entre el numero de variables de la suma de las \n\tmismas\n\n");
            			break;
            		case 3:
            			printf("\tVarianza: Medida de dispersión que representa la variabilidad de una serie de datos respecto a su media. \n\tFormalmente se calcula como la suma de los residuos al cuadrado divididos entre el total de observaciones\n");
            			break;
            		case 4:
            			printf("\tCuasivarianza: Medida de dispersión que indica la variabilidad de una muestra.En concreto, la cuasivarianza es \n\tigual a la suma de los cuadrados de las desviaciones partido por el número total de observaciones menos uno.\n");
            			break;
				}
                break;
            default:
            	
                printf("Elija una de las opciones vigentes\n");
               
        }
    } while(seleccion != 4 );

    return 0;
}

float cuasivarianza(float vector_3[], int tamanio_3)
{
	float suma_cuadrados=0, x=media(vector_3, tamanio_3), resultado;
	int i=0;
	for(i=0; i<tamanio_3; i++)
	{
	    suma_cuadrados=suma_cuadrados+(vector_3[i]-x)*(vector_3[i]-x);
	}
	resultado=suma_cuadrados/(tamanio_3-1);
	
	return resultado;
}

 void leer_fichero()
{
	int i;
	FILE *archivo;
	
	archivo = fopen("9_Datos_hidraulicos_03_2023.csv", "r");
	if (archivo == NULL)
	{
		printf("Error al abrir el fichero.\n");
	}
	else 
	{
		printf("El fichero se ha abierto correctamente.\n");
		
		int LARGO_LINEA = 1024; // longitud maxima
	
   
    char linea[LARGO_LINEA]; // almacenar la linea actual
    char cajas[LARGO_LINEA]; // almacenar cada caja
    int cantidad_cajas = 0; // contador de cajas

    while (fgets(linea, LARGO_LINEA, archivo)) 
	{ 
        cantidad_cajas = 0; 

        for ( i=0 ; i < LARGO_LINEA && linea[i] != '\0'; i++) 
		{ 
            if (linea[i] == ',') { //encontrar una coma indica la existencia de una caja
                cajas[cantidad_cajas] = '\0'; 
                printf("%s ", cajas); 
                cantidad_cajas = 0;//reinicio de contador
            }
            else { 
                cajas[cantidad_cajas] = linea[i]; 
                cantidad_cajas++; // incrementamos el contador de caracteres de la caja
            }
        }

        // imprimimos la ultima caja
        cajas[cantidad_cajas] = '\0';
        printf("%s\n", cajas);
    
	}
    fclose(archivo); 
    
     }
 }
 
float media(float vector[], int tamanio)
{
	float resultado;
	int i=0;
	for(i=0; i<tamanio; i++)
	{
		resultado=resultado+vector[i];
	}
	resultado=resultado/i;
	
	return resultado;
}

float varianza(float vector_2[], int tamanio_2)
{
	float suma_cuadrados=0, x=media(vector_2, tamanio_2), resultado;
	int i=0;
	for(i=0; i<tamanio_2; i++)
	{
	    suma_cuadrados=suma_cuadrados+(vector_2[i]-x)*(vector_2[i]-x);
	}
	resultado=suma_cuadrados/tamanio_2;
	
	return resultado;
}



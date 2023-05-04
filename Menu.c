#include <stdio.h>
void leer_fichero();

int main() {
    int seleccion,ayuda;

    do {
        printf("MENU:\n");
        printf("1. Opcion: Lectura del fichero .csv en la terminal 1\n");
        printf("2. Opcion: Calculo de... 2\n");
        printf("3. Opcion 3\n");
        printf("4. Salir 4\n");
        printf("100. Informacion y ayuda referente a las funciones del programa\n");

        printf("Ingrese su opcion: ");
        scanf("%d", &seleccion);

        switch(seleccion) {
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
                printf("Saliendo del menu\n");
                break;
            case 100:
            	
            	
                printf("Elija la funcion del programa sobre la que le interese aprender\n");
                printf(" 1 Media\n 2 FUNCION 2\n 3 FUNCION 3\n 4 FUNCION 4\n");
                scanf ("%d", &ayuda);
                
            	switch(ayuda) {
            		case 1:
            			printf("Media: La media es el calculo hecho a partir de la division entre el numero de variables de la suma de las mismas\n");
            			break;
            		case 2:
            			printf("Funcion 2:\n");
            			break;
            		case 3:
            			printf("Funcion 3:\n");
            			break;
            		case 4:
            			printf("Funcion 4:\n");
            			break;
				}
                break;
            default:
            	
                printf("Elija una de las opciones vigentes\n");
               
        }
    } while(seleccion != 4 );

    return 0;
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

    while (fgets(linea, LARGO_LINEA, archivo)) { 
        cantidad_cajas = 0; 

        for ( i=0 ; i < LARGO_LINEA && linea[i] != '\0'; i++) { 
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



#include <stdio.h>
#include <math.h>

int main() {
    int seleccion,ayuda;

    do {
        printf("MENU:\n");
        printf("1. Opcion: Calculo de medias 1\n");
        printf("2. Opcion: Calculo de... 2\n");
        printf("3. Opcion 3\n");
        printf("4. Salir 4\n");
        printf("100. Informacion y ayuda referente a las funciones del programa\n");

        printf("Ingrese su opcion: ");
        scanf("%d", &seleccion);

        switch(seleccion) {
            case 1:
                printf("Usted ha elegido la opcion 1\n");
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
                while(getchar() != '\n');
        }
    } while(seleccion != 4 || seleccion == 100);

    return 0;
}


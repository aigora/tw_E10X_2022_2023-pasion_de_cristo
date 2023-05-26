#include <stdio.h>
#include <stdlib.h>

float cuasivarianza(float vector_3[], int tamanio_3);
void leer_fichero();
float media(float vector[], int tamanio);
float varianza(float vector_2[], int tamanio_2);
void extraerFila(char matriz[18][25][800], int fila, float vector[25]);
void imprimirVector(float vector[25], int longitud);
void leerLineaCSV( char *nombreArchivo, int nLinea);
void MatrizArchivo();

int main() 
{
    int seleccion,ayuda,visual,operaciones;

    do {
         printf("\n      *MENU PRINCIPAL*\n\n");
        printf("\t1. Opcion: Menu de visualizacion de datos \n");
        printf("\t2. Opcion: Menu de operaciones \n");
        printf("\t3. Opcion 3\n");
        printf("\t4. Salir \n");
        printf("\t100. Informacion y ayuda referente a las funciones del programa\n");

        printf("\n\nIngrese su opcion: ");
        scanf(" %d", &seleccion);

      switch(seleccion) {
            case 1:
            	printf("\t\t\t\t\t\t\t\t\t\tEstas en: MENU DE VISUALIZACION\n");
                printf("\n\tElija la funcion:\n");
                printf("\t 1 Visualizacion del csv. \n\t 2 Visualizacion de lineas en especifico 2\n\t 3 Creacion de una matriz y seleccion de vector 3\n\t 4 FUNCION 4\n");
                scanf ("%d", &visual);
                switch(visual) {
            		case 1:
            			printf("Visualizacion: \n");
            			leer_fichero();
            			break;
            		case 2:
            			printf("Visualizacion de lineas en especifico:\n");
            			printf ("Elija el numero de linea que quiere leer del archivo. ( solo mostrara por pantalla esa linea del .csv)\n\n");
						int queLinea;
						scanf ("%i",&queLinea);
    					leerLineaCSV("archivo.csv", queLinea);
            			break;
            		case 3:
            			printf("Creacion de una matriz y seleccion de vector:\n");
            			MatrizArchivo();
            			break;
				}
                break;
            case 2:
                printf("\t\t\t\t\t\t\t\t\t\tEstas en MENU DE OPERACIONES\n");
                printf("\n\tElija la:\n");
                printf("\t 1 Media \n\t 2 Varianza \n\t 3 Cuasivarianza \n\t 4 FUNCION \n");
                scanf ("%d", &operaciones);
                
				switch(operaciones) {
            		case 1:
            			printf("Media:\n");
            			break;
            		case 2:
            			printf("Varianza:\n");
            			break;
            		case 3:
            			printf("Cuasivarianza:\n");
            			break;
            		case 4:
            			printf("Funcion 4:\n");
            			break;
				}
               
                break;
            case 3:
                printf("Usted ha elegido la opcion 3\n");
                break;
            case 4:
                printf("Saliendo del menu\n");
                break;
            case 100:
            	
            	
                printf("\n\tElija la funcion del programa sobre la que le interese aprender\n");
                printf("\t 1 Visualizacion de datos \n\t 2 Media \n\t 3 Varianza \n\t 4 Cuasivarianza \n");
                scanf ("%d", &ayuda);
                
            	switch(ayuda) {
            		case 1:
            			printf("\tVisualizacion de Datos: Se mostraran en pantalla todos los datos contenidos en el fichero\n");
            			break;
            		case 2:
            			printf("Media: La media es el calculo hecho a partir de la division entre el numero de variables de la suma de las \n\tmismas\n\n\n");
            			break;
            		case 3:
            			printf("Varianza: Medida de dispersi?n que representa la variabilidad de una serie de datos respecto a su media. \n\tFormalmente se calcula como la suma de los residuos al cuadrado divididos entre el total de observaciones\n");
            			break;
            		case 4:
            			printf("Cuasivarianza: Medida de dispersi?n que indica la variabilidad de una muestra.En concreto, la cuasivarianza es \n\tigual a la suma de los cuadrados de las desviaciones partido por el n?mero total de observaciones menos uno.\n");
            			break;
				}
                break;
            default:
            	
                printf("Elija una de las opciones vigentes\n");
               
        }
    } while(seleccion != 4 );

    return 0;
}

 void MatrizArchivo() {

   int numeroColumnas = 25;
    int numeroFilas = 18;
    char matrizDatos[18][25][800];
    char bufferFila[1024];
    FILE *archivo;
    archivo = fopen("Def.csv", "r");
    char elemento[80] = "";
    int letra = 0;
    int indiceLetra = 0;
    int filaOriginal = 0;
    int columnaActual = 0;
    int filaReal = 0;
    int Decimal = 0;
    numeroFilas += 4;
    int i = 0;
    int j = 0;
    int k = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////7
    
    for (filaOriginal = 0; filaOriginal < numeroFilas; filaOriginal++) {
        columnaActual = 0;
        fgets(bufferFila, 1024, archivo);
        printf("%s\n", bufferFila);
        indiceLetra = 0;
        letra = 0;
        
        for (letra = 0; bufferFila[letra] != '\n'; letra++) {
            if (bufferFila[letra] == '"') {
                Decimal = !Decimal;
                continue;
            }
            
            if (bufferFila[letra] == ',') {
                if (!Decimal) {
                    if (filaOriginal >= 4) {
                        filaReal = filaOriginal - 4;
                        
                        for (i = 0; elemento[i] != '\0'; i++) {
                            matrizDatos[filaReal][columnaActual][i] = elemento[i];
                        }
                        printf("%s", matrizDatos[filaReal][columnaActual]);
                        printf(" %i %i \nexito\n", filaReal, columnaActual);
                        columnaActual++;
                    }
                    indiceLetra = 0;
                } else {
                    elemento[indiceLetra] = '.';
                    indiceLetra++;
                    printf("%s\n", elemento);
                    continue;
                }
                
                int j = 0;
                for (j = 0; elemento[j] != '\0'; j++) {
                    elemento[j] = '\0';
                }
            }
            
            if (bufferFila[letra] != ',') {
                if (columnaActual == 0) {
                    char letraCorregida;
                    switch (bufferFila[letra]) {
                        case 'á':
                            letraCorregida = 'a';
                            break;
                        case 'é':
                            letraCorregida = 'e';
                            break;
                        case 'í':
                            letraCorregida = 'i';
                            break;
                        case 'ó':
                            letraCorregida = 'o';
                            break;
                        case 'ú':
                            letraCorregida = 'u';
                            break;
                        case 'Á':
                            letraCorregida = 'A';
                            break;
                        case 'É':
                            letraCorregida = 'E';
                            break;
                        case 'Í':
                            letraCorregida = 'I';
                            break;
                        case 'Ó':
                            letraCorregida = 'O';
                            break;
                        case 'Ú':
                            letraCorregida = 'U';
                            break;
                        case 'ü':
                            letraCorregida = 'u';
                            break;
                        case 'Ü':
                            letraCorregida = 'U';
                            break;
                        default:
                            letraCorregida = bufferFila[letra];
                            break;
                    }
                    elemento[indiceLetra] = letraCorregida;
                                    } else {
                    elemento[indiceLetra] = bufferFila[letra];
                }
                indiceLetra++;
                printf("%s\n", elemento);
            }
        }
        
        elemento[indiceLetra - 1] = '\0';
        
        if (filaOriginal >= 4) {
            for (k = 0; elemento[k] != '\0'; k++) {
                matrizDatos[filaReal][columnaActual][k] = elemento[k];
                elemento[k] = '\0';
            }
            printf("%s", matrizDatos[filaReal][columnaActual]);
            printf(" %i %i \n", filaReal, columnaActual);
            printf("exito\n\n");
        }
    }
    
    
    for (i = 0; i < numeroFilas - 4; i++) {
        for (j = 0; j < numeroColumnas; j++) {
            printf("%s ", matrizDatos[i][j]);
            printf("%i %i\n", i, j);
        }
        printf("\n");
    }
    
      printf("\n\nImpresion de los datos limpios sin ningun simbolo ni error\n\n");
    for (i = 0; i < numeroFilas - 4; i++) {
        for (j = 0; j <numeroColumnas ; j++) {
            
            char *p = matrizDatos[i][j];
            while (*p != '\0') {
                if (*p < 32 || *p > 126) {
                    *p = ' '; // Reemplazar con un espacio en blanco
                }
                p++;
            }
            
            // Imprimir los datos limpios
            
            printf("%s ", matrizDatos[i][j]);
            printf("%i %i\n", i, j);
        }
        printf("\n");
    }
    
    //////////////////////////////////////////////////////////////////////////////

     matrizDatos[18][25][800];  // Matriz de datos
    
    int fila;  
    printf("\n Elige una fila de la matriz para crear un vector:\n");
    scanf("%i",&fila);
    float vector[25];  //Almacena la fila
    
    extraerFila(matrizDatos, fila, vector);
    
    printf("Fila %d:\n", fila);
    imprimirVector(vector, 25); //los decimales cuentan con un leve error
    
    
    
    /////////////////////////////////////////////////////////////////////////////////
    
    fclose(archivo);}


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
	
	archivo = fopen("Def.csv", "r");
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

void extraerFila(char matriz[18][25][800], int fila, float vector[25]) {
    int columna;
    for (columna = 0; columna < 25; columna++) {
        float valor = atof(matriz[fila][columna]); // paso a float.
        vector[columna] = valor;
    }
}

void imprimirVector(float vector[25], int longitud) {
    int i;
    for (i = 0; i < longitud; i++) {
        printf("%f ", vector[i]);
    }
    printf("\n");
}

void leerLineaCSV( char *nombreArchivo, int nLinea) {
    FILE *archivo = fopen("Def.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el fichero.\n");
        return;
    }

    char linea[1024];
    int cLineas = 1;
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (cLineas == nLinea) {
            printf("\nLinea %i:\n %s", nLinea, linea);
            break;
        }
        cLineas++;
    }

    fclose(archivo);
}

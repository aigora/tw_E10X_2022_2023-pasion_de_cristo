#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[40];
	float vector[24];
} datos;
//-------------------------------------------------------------------------

float cuasivarianza(float vector_3[], int tamanio_3);
void imprimir_estructura(datos vector_estructura[]);
void leer_fichero();
float media(float vector[], int tamanio);
float varianza(float vector_2[], int tamanio_2);
void extraerFila(char matriz[18][25][800], int fila, float vector[25]);
void imprimirVector(float vector[25], int longitud);
void leerLineaCSV( char *nombreArchivo, int nLinea);
void MatrizArchivo(float vector[25]);
void MatrizArchivoV();
float encontrarMaximo(float vector[], int longitud);
float encontrarMinimo(float vector[], int longitud);
int Validacion(int min, int max);
void ordenar_mayor_a_menor(float vector[], int longitud);
float incremento_en_porcentaje(float vector[], int longitud);
float valor_absoluto(float numero);
void intercambiar(int *a, int *b);
float encontrar_mediana(float vector[], int longitud);
void escribir_en_archivo(const char* nombre_archivo, const char* contenido); 
//-------------------------------------------------------------------------

 int main() 
  {
    int seleccion,ayuda,visual,operaciones;
    float vector[25];
    int longitud = sizeof(vector) / sizeof(vector[0]);
    datos todos[17] = {
	{"Hidraulica",4057.346783,4517.602492,3715.416012,2745.019022,2159.483245,2182.252545,2209.4646239999997,1883.2608030000001,1396.698883,1023.215446,1199.445532,2536.803672,2085.857451,1174.9701699999998,1764.806206,1782.053848,1922.3023759999999,1190.985484,1043.519078,972.977692,1153.775681,717.70239,1309.281418,2744.808065},
	{"Turbinacion bombeo",320.53138900000005,401.29321899999997,330.794555,153.67968,238.708927,105.706304,115.895307,159.688964,118.198104,232.112394,202.80659899999998,269.908819,215.637741,285.079947,273.84815299999997,336.712619,299.880038,270.92393,216.61759400000003,339.372152,304.810326,385.661431,361.66386700000004,485.359059},
	{"Nuclear",5199.740516,4358.515107,4833.065002,4197.33293,4373.250552,3684.377943,5119.328941,5151.337803,4890.618221,4748.364457000001,3562.2548070000003,3922.833452,5048.424951,4771.058269,4766.690052,4414.715447,4066.355361,4459.459166000001,5073.1524979999995,5122.0469299999995,4847.367123,4021.440771,4231.577244,5161.212451},
	{"Carbon",557.975979,176.26671900000002,242.138946,270.100026,331.93111300000004,473.579232,311.10233,319.182668,477.087202,527.419848,576.437576,719.9263739999999,709.9632190000001,568.629528,705.226125,691.004601,527.154558,833.22046,882.232497,819.592534,632.066719,380.972026,321.469754,693.672984},
	{"Motores diesel",203.759973,160.418085,173.283976,187.547789,178.36229999999998,206.220592,239.57681599999998,258.860338,256.964192,233.57056500000002,203.062243,215.79723800000002,210.125165,185.57552600000002,207.451789,205.100257,215.84438,224.847296,242.769547,245.673515,216.066723,202.310552,192.196854,200.24196799999999},
	{"Turbina de gas",28.766271,18.026130000000002,27.904377,24.553476999999997,24.916217,34.119217,40.565981,47.885346,71.402214,46.314807,30.058985,29.066882,34.446764,34.328002,38.861714,34.57236,42.307777,47.734021999999996,79.729885,85.527648,84.42261599999999,79.275334,47.409887000000005,48.856536},
	{"Turbina de vapor",116.282053,104.960847,100.75825900000001,70.652976,62.41677,33.486942000000006,66.13421000000001,99.64419000000001,113.21021300000001,112.484255,115.10902300000001,112.916219,117.429802,102.630663,114.410944,103.636366,86.849653,60.625902,73.213599,102.417012,110.95399099999999,118.59882,93.771169,122.69665499999999},
	{"Ciclo combinado",2729.183017,1544.065785,2151.091661,3384.471579,2444.871606,3658.878948,3718.134418,4047.368387,4943.197265,4407.05637,6317.636788,5154.143508,5898.394445,4671.261013,3873.2032000000004,3146.865903,3713.6394849999997,6478.937315,8460.459144999999,8082.027681,7704.900731,7066.859015,4672.406377,4368.592847},
	{"Hidroeolica",0.99317,1.226483,1.921443,0.835908,3.2270770000000004,3.002042,3.5782179999999997,2.663478,1.429314,1.8534549999999999,1.1397899999999999,1.227861,1.110916,1.482045,2.1263229999999997,1.752528,1.917174,2.44956,3.562943,3.517675,2.0750949999999997,1.350072,1.1694090000000001,0.367104},
	{"Eolica",7101.249123,6294.982856,5606.818805,4095.800569,4785.695033,3684.170619,4284.090513,3747.238495,3234.274816,4359.563921,6421.739529,6910.032613,5414.777160000001,4712.962772,6528.440466,5655.806361,4687.64999,3807.180833,4566.002106,4258.846638,4191.189274,5099.919318,6682.534764,5570.2825920000005},
	{"Solar fotovoltaica",848.4030740000001,973.686902,1688.757265,1665.571492,2388.831852,2325.571729,2617.534056,2395.8309,1927.916611,1777.274811,1347.957356,1023.70725,1569.2916839999998,1693.011465,1455.368818,2581.307811,3380.729182,3215.923445,3381.1566589999998,3239.672293,2693.50188,2005.3213540000002,1533.099321,1115.958},
	{"Solar termica",102.634029,138.18132699999998,355.01542700000005,266.787519,645.5974570000001,655.361716,828.492494,661.4451019999999,447.444657,328.182894,172.42624600000002,103.956001,170.978835,208.192368,120.56837399999999,412.77761,621.247495,534.185927,667.2357830000001,619.95899,437.343279,166.240105,104.768426,59.778183},
	{"Otras renovables",390.590396,365.191889,359.459071,392.274795,390.93192700000003,358.010046,352.713786,410.590237,396.278098,433.04749400000003,434.361576,436.423907,428.663218,374.913003,423.887477,430.376969,397.335983,415.748786,409.34559499999995,383.442347,341.437356,366.964524,364.536652,319.642072},
	{"Cogeneracion",2405.236806,1838.16573,2253.823616,2193.285205,2206.3288620000003,2181.2767940000003,2243.226356,2106.285519,2166.255198,2147.907197,2173.751719,2175.103528,2147.921609,2119.152721,2217.055737,1709.641446,1870.643862,1467.3834920000002,1053.7381990000001,779.410997,739.19081,1102.000335,1453.363695,1098.167328},
	{"Residuos no renovables",182.93208900000002,172.740345,184.342436,178.093968,177.333071,198.273452,205.014809,212.202012,179.817184,187.508,179.26082,181.223116,169.946929,144.54671599999998,183.995605,171.926116,170.585177,155.903954,181.020454,164.769537,139.77665599999997,155.069311,127.558061,134.66801500000003},
	{"Residuos renovables",59.850282,69.06586800000001,72.598535,74.357494,59.595065999999996,79.50385,81.91575,81.751572,68.076048,68.765996,80.249832,82.210439,79.365292,72.930818,82.06925100000001,72.848577,79.964147,76.946932,75.73252099999999,65.48815,59.668639000000006,71.884421,67.535659,73.273156},
	{"Generacion total",24305.47495,21134.389784,22097.189386,19900.364428999997,20471.481075,19863.791971000002,22436.768607999995,21585.235814,20688.868220000004,20634.64191,23017.698420999997,23875.280879,24302.335181000002,21120.725026,22758.010234000005,21751.098819,22084.406638,23242.456503999998,26409.488103,25284.741791,23658.546898999994,21941.569779,21564.342557,22197.577015}
	};

    do {
         printf("\n      *MENU PRINCIPAL*\n\n");
        printf("\t1. Opcion: Menu de visualizacion de datos \n");
        printf("\t2. Opcion: Menu de operaciones \n");
        printf("\t3. Salir \n");
        printf("\t4. Informacion y ayuda referente a las funciones del programa\n");
        printf("\t5. Escribir una resena\n");

        seleccion = Validacion(1, 5);

      switch(seleccion) {
            case 1:
            	printf("\t\t\t\t\t\t\t\t\t\tEstas en: MENU DE VISUALIZACION\n");
                printf("\n\tElija la funcion:\n");
                printf("\t 1 Visualizacion del csv. \n\t 2 Visualizacion de lineas en especifico \n\t 3 Creacion de una matriz y seleccion de vector \n\t 4 Visualizacion de datos por tipo \n\t 5 Generacion de vectores completa por fila de matriz \n\t");
                printf(" 6 ordenar un vector escogido de mayor a menor \n\t");
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
    					MatrizArchivo( vector);
    					break;
    				case 4:
    					printf("Visualizacion de datos por tipo");
    					imprimir_estructura(todos);
            			break;
            		case 5:
            			printf("Generacion de vectores completa por fila de matriz:\n");
    					MatrizArchivoV( vector);
    					break;
    				case 6:
    					printf("ordenar un vector escogido de mayor a menor\n");
    					MatrizArchivo( vector);
    					
    					ordenar_mayor_a_menor(vector, 25);
    					printf("vector ordenado de mayor a menor:\n");
    					imprimirVector(vector, 25);
    					break;
    				
    					
            		default:
                        printf("Elija una de las opciones vigentes\n");
                        break;
				}
                break;
            case 2:
                printf("\t\t\t\t\t\t\t\t\t\tEstas en MENU DE OPERACIONES\n");
                printf("\n\tElija la funcion:\n");
                printf("\t 1 Media \n\t 2 Varianza \n\t 3 Cuasivarianza \n\t 4 Maximo y minimo \n\t 5 Mediana \n\t 6.calcular el incremento en porcentaje de una fila escogida\n\t");
                scanf ("%d", &operaciones);
                
				switch(operaciones) {
            		case 1:
            			printf("Media:\n");
            			MatrizArchivo(vector);
            			
                        float med = media(vector, longitud);
						printf("La media es: %f\n", med);
						break;
            		case 2:
            			printf("Varianza:\n");
            			MatrizArchivo(vector);
            			
            			float var = varianza(vector, longitud);
            			printf("La varianza es: %f\n", var);
            			break;
            		case 3:
            			printf("Cuasivarianza:\n");
            			MatrizArchivo(vector);
            			
            			float cuasi = cuasivarianza(vector, longitud);
            			printf("La cuasivarianza es: %f", cuasi);
            			break;
            		case 4:
                        printf("Maximo y minimo del vector escogido de la matriz:\n");
    					MatrizArchivo( vector);
    
    					float maximo = encontrarMaximo(vector, longitud);
						printf("El maximo es: %.2lf\n", maximo);
						
    					float minimo = encontrarMinimo(vector, longitud);
						printf("El minimo es: %.2lf\n", minimo);
            			break;
            		case 5:
            			printf("Mediana:");
            			MatrizArchivo(vector);
            			
            			int longitud = 25;
            			float mediana = encontrar_mediana(vector, 25);
            			printf("la mediana del vector escogido es: %.2f\n", mediana);
            			break;
            		case 6:
    					printf("Incremento en porcentaje del vector escogido");
    					MatrizArchivo( vector);
    					
    					float incremento_porcentaje =  incremento_en_porcentaje( vector, 25);
    					
    					if(incremento_porcentaje < 0)
    					{
    						incremento_porcentaje = valor_absoluto(incremento_porcentaje);
    						printf("el valor del vector escogido ha disminuido un %f por ciento ", incremento_porcentaje);
						}
    					else
    					{
    						printf("el valor del vector escogido ha aumentado un %f por ciento", incremento_porcentaje);
						}
						break;
            		default:
                        printf("Elija una de las opciones vigentes\n");
                        break;
				}
               
                break;
            case 3:
                printf("Saliendo del menu\n");
                break;
            case 4:
            	
            	
                printf("\n\tElija la funcion del programa sobre la que le interese aprender\n");
                printf("\t 1 Visualizacion de datos \n\t 2 Media \n\t 3 Varianza \n\t 4 Cuasivarianza \n\t 5 Visualizacion de lineas en especifico \n\t 6 Creacion de una matriz y seleccion de vector \n\t 7 Maximo y minimo \n\t 8 Generacion de vectores completa por fila de matriz \n\t 9 Visualizacion de datos por tipo \n\t 10 Incremento en porcentaje del vector escogido \n\t 11 Mediana \n");
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
            		case 5:
            			printf("Visualizacion de lineas en especifico: Permite la selección de una linea del archivo csv para imprimir sus datos en la terminal\n");
            			break;	
            		case 6:
            			printf("Creacion de una matriz y seleccion de vector: Se imprimira una matriz de caracteres formada con los datos del archivo y permitirá crear un vector a partir de la matriz a seleccion del usuario (de datos float) \n");
            			break;	
            		case 7:
            			printf("Maximo y minimo: El valor mas grande y el valor mas pequeno (numerico) aplicado dentro de un vector \n");
            			break;	
            		case 8:
            			printf("Generacion de vectores completa por fila de matriz: Funcion encargada de generar un vector por cada fila de la matriz dando paso a una vectorizacion completa de la matriz.\n");
            			break;
					case 9:
            			printf("Visualizacion de datos por tipo: Impresión de los vectores evitando el 0 inicial de cada uno e introduciendo el titulo de cada fila del fichero como componente del vector a traves de un vector de estructuras.\n");
            			break;
					case 10:
            			printf("Incremento en porcentaje del vector escogido: Variacion positiva o negativa que registra el valor numerico en un variable vuelta porcentaje.\n");
            			break;
					case 11:
            			printf("Mediana: Valor de la variable de posicion central en un conjunto de datos ordenados ( en este caso el vector).\n");
            			break;	
				}
                break;
            case 5:
                printf("Puede empezar a escribir la evaluacion:\n");
                char nombre[50] = {'e','v','a','l','u','a','c','i','o','n','_','t','r','a','b','a','j','o'};
                char evaluacion[500];
                
                printf("Escriba la evaluacion: ");
                scanf(" %[^\n]s", evaluacion);
                
                escribir_en_archivo( nombre, evaluacion);
                
            default:
            	
                printf("Elija una de las opciones vigentes\n");
               
        }
    } while(seleccion != 3);

    return 0;
  }

 void MatrizArchivo(float vector[25]) {

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
        //printf("%s\n", bufferFila);
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
                        //printf("%s", matrizDatos[filaReal][columnaActual]);
                       // printf(" %i %i \nexito\n", filaReal, columnaActual);
                        columnaActual++;
                    }
                    indiceLetra = 0;
                } else {
                    elemento[indiceLetra] = '.';
                    indiceLetra++;
                   // printf("%s\n", elemento);
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
                //printf("%s\n", elemento);
            }
        }
        
        elemento[indiceLetra - 1] = '\0';
        
        if (filaOriginal >= 4) {
            for (k = 0; elemento[k] != '\0'; k++) {
                matrizDatos[filaReal][columnaActual][k] = elemento[k];
                elemento[k] = '\0';
            }
           // printf("%s", matrizDatos[filaReal][columnaActual]);
            //printf(" %i %i \n", filaReal, columnaActual);
            //printf("exito\n\n");
        }
    }
    
    
    for (i = 0; i < numeroFilas - 4; i++) {
        for (j = 0; j < numeroColumnas; j++) {
            //printf("%s ", matrizDatos[i][j]);
            //printf("%i %i\n", i, j);
        }
        //printf("\n");
    }
    
      //printf("\n\nImpresion de los datos limpios sin ningun simbolo ni error\n\n");
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
     vector[25];  //Almacena la fila
    
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
	resultado=suma_cuadrados/(tamanio_3-2);
	
	return resultado;
  }

  void imprimir_estructura(datos vector_estructura[])
  {
	int i=0, j=0;
	for(i=0; i<17; i++)
	{
		printf("\n\n%s:\n\n", vector_estructura[i].nombre);
		for(j=0; j<24; j++)
		{
		 	printf("%f  ", vector_estructura[i].vector[j]);
		}
	}
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
	resultado=resultado/(i-1);
	
	return resultado;
  }

  float varianza(float vector_2[], int tamanio_2)
  {
	float suma_cuadrados=0, x=media(vector_2, tamanio_2), resultado;
	int i=0;
	for(i=0; i<tamanio_2; i++)
	{
	    suma_cuadrados=suma_cuadrados+((vector_2[i]-x)*(vector_2[i]-x));
	}
	resultado=suma_cuadrados/(tamanio_2-1);
	
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
    for (i = 1; i < longitud; i++) {
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

  float encontrarMaximo(float vector[], int longitud) {
    float maximo = vector[0];  // Suponemos que el primer elemento es el máximo inicialmente
    
    int i;
    for ( i = 1; i < longitud; i++) {
        if (vector[i] > maximo) {
            maximo = vector[i];  // Actualizamos el máximo si encontramos un valor mayor
        }
    }
    
    return maximo;
  }

  float encontrarMinimo(float vector[], int longitud) {
    float minimo = vector[0];  // Suponemos que el primer elemento es el mínimo inicialmente
    int i;
    
      for (i = 1; i < longitud; i++) {
        if (vector[i] != 0 && (vector[i] < minimo || minimo == 0)) {
            minimo = vector[i];  // Actualizamos el mínimo si encontramos un valor menor y no es cero
        }
    }
    
    return minimo;
  }


  void MatrizArchivoV() {  // esta funcion sigue las mismas bases que la matriz y el vector individual pero con esta conseguimos una impresion de todos los vectores
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
    
    for (filaOriginal = 0; filaOriginal < numeroFilas; filaOriginal++) {
        columnaActual = 0;
        fgets(bufferFila, 1024, archivo);
        //printf("%s\n", bufferFila);
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
                        //printf("%s", matrizDatos[filaReal][columnaActual]);
                       // printf(" %i %i \nexito\n", filaReal, columnaActual);
                        columnaActual++;
                    }
                    indiceLetra = 0;
                } else {
                    elemento[indiceLetra] = '.';
                    indiceLetra++;
                   // printf("%s\n", elemento);
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
                //printf("%s\n", elemento);
            }
        }
        
        elemento[indiceLetra - 1] = '\0';
        
        if (filaOriginal >= 4) {
            for (k = 0; elemento[k] != '\0'; k++) {
                matrizDatos[filaReal][columnaActual][k] = elemento[k];
                elemento[k] = '\0';
            }
           // printf("%s", matrizDatos[filaReal][columnaActual]);
            //printf(" %i %i \n", filaReal, columnaActual);
            //printf("exito\n\n");
        }
    }
    
    
    for (i = 0; i < numeroFilas - 4; i++) {
        for (j = 0; j < numeroColumnas; j++) {
            //printf("%s ", matrizDatos[i][j]);
            //printf("%i %i\n", i, j);
        }
        //printf("\n");
    }
    
     printf("\n\nImpresión de los datos limpios sin ningún símbolo ni error\n\n");
    for (i = 0; i < numeroFilas - 4; i++) {
        for (j = 0; j < numeroColumnas; j++) {
            char *p = matrizDatos[i][j];
            while (*p != '\0') {
                if (*p < 32 || *p > 126) {
                    *p = ' '; // Reemplazar con un espacio en blanco
                }
                p++;
            }
            printf("%s ", matrizDatos[i][j]);
            printf("%i %i\n", i, j);
        }
        printf("\n");
    }

    // Imprimir vectores por cada fila
    printf("\nImpresión de los vectores:\n");
    for (i = 0; i < numeroFilas - 4; i++) {
        float vector[25];
        extraerFila(matrizDatos, i, vector);
        printf("Fila %d:\n", i);
        imprimirVector(vector, 25);
    }
    fclose(archivo);
  }

  int Validacion(int min, int max) {
    int opcion;
    printf("\nIntroduzca una opcion: ");
    scanf("%d", &opcion);
    while (opcion < min || opcion > max) {
        printf("Opción inválida. Introduzca una opción válida: ");
        scanf("%d", &opcion);
    }
    return opcion;
  }
  
  float incremento_en_porcentaje(float vector[], int longitud)
  {
	float incremento = vector[longitud-1] - vector[1];
	float incremento_porcentaje = (incremento/vector[1])*100;
	return incremento_porcentaje;
  }		
  float valor_absoluto(float numero) 
  {
    if (numero < 0)
	{
        return -numero;
    } 
	else
	{
        return numero;
    }
  }

  void escribir_en_archivo(const char* nombre_archivo, const char* contenido) 
  {
    // Abrir el archivo en modo escritura
    FILE* archivo = fopen("Reseña.txt", "w");
    // Comprobar si el archivo se abrió correctamente
    if (archivo == NULL) 
	{
        printf("Error al abrir el archivo.\n");
        return;
    }
    // Escribir el contenido en el archivo
    fprintf(archivo, "%s", contenido);
    
    fclose(archivo);
    printf("Se ha escrito en el archivo correctamente\n");
  }

  void intercambiar(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  float encontrar_mediana(float vector[], int longitud) 
   {	
    int i, j;
    for (i = 1; i < longitud - 1; i++) {
        for (j = 1; j < longitud - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                intercambiar(&vector[j], &vector[j + 1]);
            }
        }
    }

    int posicion_mediana = longitud / 2;
    // Si la longitud del vector es impar, la mediana es el valor en la posición del medio
    if (longitud % 2 != 0) 
	{
        return vector[posicion_mediana];
    }
    // Si la longitud del vector es par, la mediana es el promedio de los dos valores del medio
    else 
	{
        float valor_medio_1 = vector[posicion_mediana - 1];
        float valor_medio_2 = vector[posicion_mediana];
        return (valor_medio_1 + valor_medio_2) / 2.0;
    }
  }

  void ordenar_mayor_a_menor(float vector[], int longitud) 
  {
    int i, j;
    float temp;

    for (i = 1; i < longitud ; i++) {
        for (j = 1; j < longitud - i ; j++) {
            if (vector[j] < vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
  }

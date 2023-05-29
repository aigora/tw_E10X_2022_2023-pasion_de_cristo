
//1----------------------------------------------------------------------------------------------------------------------|
void MatrizArchivo(float vector[25]);
//2----------------------------------------------------------------------------------------------------------------------|
float cuasivarianza(float vector_3[], int tamanio_3);
//3----------------------------------------------------------------------------------------------------------------------|
void imprimir_estructura(datos vector_estructura[]);
//4----------------------------------------------------------------------------------------------------------------------|
void leer_fichero();
//5----------------------------------------------------------------------------------------------------------------------|
float media(float vector[], int tamanio);
//6----------------------------------------------------------------------------------------------------------------------|
float varianza(float vector_2[], int tamanio_2);
//7----------------------------------------------------------------------------------------------------------------------|
void extraerFila(char matriz[18][25][800], int fila, float vector[25]);
//8----------------------------------------------------------------------------------------------------------------------|
void imprimirVector(float vector[25], int longitud);
//9----------------------------------------------------------------------------------------------------------------------|
void leerLineaCSV( char *nombreArchivo, int nLinea);
//10----------------------------------------------------------------------------------------------------------------------|
float encontrarMaximo(float vector[], int longitud);
//11----------------------------------------------------------------------------------------------------------------------|
float encontrarMinimo(float vector[], int longitud);
//12----------------------------------------------------------------------------------------------------------------------|
void MatrizArchivoV();
//13----------------------------------------------------------------------------------------------------------------------|
int Validacion(int min, int max);
//14----------------------------------------------------------------------------------------------------------------------|
float incremento_en_porcentaje(float vector[], int longitud);
//15----------------------------------------------------------------------------------------------------------------------|
void escribir_en_archivo(const char* nombre_archivo, const char* contenido);
//16----------------------------------------------------------------------------------------------------------------------|
float valor_absoluto(float numero);
//17----------------------------------------------------------------------------------------------------------------------| 
void intercambiar(int *a, int *b);
//18----------------------------------------------------------------------------------------------------------------------|   
float encontrar_mediana(float vector[], int longitud);
//19----------------------------------------------------------------------------------------------------------------------| 
void ordenar_mayor_a_menor(float vector[], int longitud);







//1----------------------------------------------------------------------------------------------------------------------|
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
    

     matrizDatos[18][25][800];  // Matriz de datos
    
    int fila;  
    printf("\n Elige una fila de la matriz para crear un vector:\n");
    scanf("%i",&fila);
     vector[25];  //Almacena la fila
    
    extraerFila(matrizDatos, fila, vector);
    
    printf("Fila %d:\n", fila);
    imprimirVector(vector, 25); //los decimales cuentan con un leve error
    
    
    
    
    
    fclose(archivo);}


//2----------------------------------------------------------------------------------------------------------------------|
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


//3----------------------------------------------------------------------------------------------------------------------|
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


//4----------------------------------------------------------------------------------------------------------------------|
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
 
 //5----------------------------------------------------------------------------------------------------------------------|
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


//6----------------------------------------------------------------------------------------------------------------------|
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
  
  
//7----------------------------------------------------------------------------------------------------------------------|
  void extraerFila(char matriz[18][25][800], int fila, float vector[25]) {
    int columna;
    for (columna = 0; columna < 25; columna++) {
        float valor = atof(matriz[fila][columna]); // paso a float.
        vector[columna] = valor;
    }
  }


//8----------------------------------------------------------------------------------------------------------------------|
  void imprimirVector(float vector[25], int longitud) {
    int i;
    for (i = 1; i < longitud; i++) {
        printf("%f ", vector[i]);
    }
    printf("\n");
  }


//9----------------------------------------------------------------------------------------------------------------------|
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


//10----------------------------------------------------------------------------------------------------------------------|
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


//11----------------------------------------------------------------------------------------------------------------------|
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



//12----------------------------------------------------------------------------------------------------------------------|
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


//13----------------------------------------------------------------------------------------------------------------------|
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
  
  
//14----------------------------------------------------------------------------------------------------------------------|
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
  
  
//15----------------------------------------------------------------------------------------------------------------------|
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
  
  
//16----------------------------------------------------------------------------------------------------------------------| 
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
  
  
//17----------------------------------------------------------------------------------------------------------------------|   
  void intercambiar(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  
//18----------------------------------------------------------------------------------------------------------------------|   
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
  
  
//19----------------------------------------------------------------------------------------------------------------------|   
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

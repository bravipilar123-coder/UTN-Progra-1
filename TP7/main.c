#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

///Ejercicio 2
int contarPares(int arr[], int validos);
void copiarParesA(int arr[], int pares[], int validos);
int* copiarParesB(int arr[], int validos);
void copiarParesC(int arr[], int validos, int** pares);
///Ejercicio 3
void mostrarUnAlumno(stAlumno a);
int cantidadRegistros(char nombreArhcivo[], int tamRegistro);
void fileToArray1(char nombreArchivo[], stAlumno arr[], int validos);
stAlumno* fileToArray2(char nombreArchivo[]);
void fileToArray3(char nombreArchivo[], stAlumno** arr);
///Ejercicio 4
int* redimensionarArreglo(int* arr, int validos, int nuevoTam);
int main()
{
    /*
    ///Ej 1
    int valor;
    int *pint = &valor;
    int **ppint = &pint;

    printf("\n---DIRECCIONES DE MEMORIA---\n");
    printf("Direccion de valor: %p\n", &valor);
    printf("Direccion de *pint: %p\n", &pint);
    printf("Direccion de **ppint: %p\n", &ppint);

    *pint = 10;
    printf("Valor asignado con pint: %d\n", valor);

    **ppint = 20;
    printf("Valor asignado con ppint: %d\n", valor);

    printf("Contenido de pint: %p\n", pint);
    printf("Contenido de ppint: %p\n", ppint);
    system("pause");
    system("cls");


    ///Ej 2
    int arr[] = {1,2,3,4,5,6,7,8};
    int validos = 8;
    {

        int cantPares = contarPares(arr, validos);

        int* pares = (int*)malloc(cantPares * sizeof(int));
        copiarParesA(arr, pares, validos);

        for(int i = 0; i < cantPares; i++)
        {
            printf("%d \n", pares[i]);
        }

        free(pares);
    }

    {
        int cantPares = contarPares(arr, validos);
        int* pares = (int*)malloc(cantPares * sizeof(int));
        copiarParesA(arr, pares, validos);

        for(int i = 0; i < cantPares; i++)
        {
            printf("%d \n", pares[i]);
        }

        free(pares);
    }

    {
        int cantPares = contarPares(arr, validos);
        int* pares = NULL;
        copiarParesC(arr, validos, &pares);
        for(int i = 0; i < cantPares; i++)
        {
            printf("%d \n", pares[i]);
        }

        free(pares);
    }
    system("pause");
    system("cls");


    ///Ej 3
    {
        int cant = cantidadRegistros("alumnos.dat", sizeof(stAlumno));
        stAlumno* arr = (stAlumno*)malloc(cant * sizeof(stAlumno));
        fileToArray1("alumnos.dat", arr, cant);
        for(int i = 0; i < cant; i++)
        {
            mostrarUnAlumno(arr[i]);
        }

        free(arr);
    }

    {

        int cant = cantidadRegistros("alumnos.dat", sizeof(stAlumno));
        stAlumno* arr = fileToArray2("alumnos.dat");
        for(int i = 0; i < cant; i++)
        {
            mostrarUnAlumno(arr[i]);
        }
       free(arr);
    }

    int cant3 = cantidadRegistros("alumnos.dat", sizeof(stAlumno));
    stAlumno* arr3 = NULL;
    fileToArray3("alumnos.dat", &arr3);
    for(int i = 0; i < cant3; i++)
    {
        mostrarUnAlumno(arr3[i]);
    }
    free(arr3);
    system("pause");
    system("cls");

    

    ///Ej 4
    int validosNuevo = 5;
    int* arrNuevo = (int*)malloc(validosNuevo * sizeof(int));
    for(int i = 0; i < validosNuevo; i++)
    {
        arrNuevo[i] = i + 1;
    }
    arrNuevo = redimensionarArreglo(arrNuevo, validosNuevo, 10);
    free(arrNuevo);
    */
    return 0;
}


///Ejercicio 2
int contarPares(int arr[], int validos)
{
    int cont = 0;
    for(int i = 0; i < validos; i++)
    {
        if(arr[i] % 2 == 0)
        {
            cont++;
        }
    }
    return cont;
}

void copiarParesA(int arr[], int pares[], int validos)
{
    int i;
    int j = 0;
    for(i = 0; i < validos; i++)
    {
        if(arr[i] % 2 == 0)
        {
            pares[j] = arr[i];
            j++;
        }
    }
}


int* copiarParesB(int arr[], int validos)
{
    int cant = contarPares(arr, validos);
    int* pares = (int*)malloc(cant * sizeof(int));

    int i, j = 0;
    for(i = 0; i < validos; i++)
    {
        if(arr[i] % 2 == 0)
        {
            pares[j] = arr[i];
            j++;
        }
    }
    return pares;
}


void copiarParesC(int arr[], int validos, int** pares)
{
    int cant = contarPares(arr, validos);
    *pares = (int*)malloc(cant * sizeof(int));
    int i, j = 0;
    for(i = 0; i < validos; i++)
    {
        if(arr[i] % 2 == 0)
        {
            (*pares)[j] = arr[i];
            j++;
        }
    }
}


///Ejercicio 3
void mostrarUnAlumno(stAlumno a)
{
    printf("Legajo: %d | Nombre completo: %s | Edad: %d | Anio: %d\n",
           a.legajo, a.nombreYapellido, a.edad, a.anio);
}

int cantidadRegistros(char nombreArhcivo[], int tamRegistro)
{
    FILE* archi = fopen(nombreArhcivo, "rb");
    int contador = 0;
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        contador = ftell(archi) / tamRegistro;
        fclose(archi);
    }
    return contador;
}

void fileToArray1(char nombreArchivo[], stAlumno arr[], int validos)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        fread(arr, sizeof(stAlumno), validos, archi);
        fclose(archi);
    }
}

stAlumno* fileToArray2(char nombreArchivo[])
{
    int cant = cantidadRegistros(nombreArchivo, sizeof(stAlumno));
    stAlumno* arr = (stAlumno*)malloc(cant * sizeof(stAlumno));
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        fread(arr, sizeof(stAlumno), cant, archi);
        fclose(archi);
    }
    return arr;
}

void fileToArray3(char nombreArchivo[], stAlumno** arr)
{
    int cant = cantidadRegistros(nombreArchivo, sizeof(stAlumno));
    *arr = (stAlumno*)malloc(cant * sizeof(stAlumno));
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        fread(*arr, sizeof(stAlumno), cant, archi);
        fclose(archi);
    }
}


///Ejercicio 4
int* redimensionarArreglo(int* arr, int validos, int nuevoTam)
{
    if(nuevoTam < validos)
    {
        printf("Eror: El nuevo tamanio es menor a la cantidad de elemento validos\n");
    }

    int* aux = (int*)realloc(arr, nuevoTam * sizeof(int));
    if(aux != NULL)
    {
        arr = aux;
    }
    else
    {
        printf("Error al redimensionar el arreglo\n");
    }
    return arr;
}

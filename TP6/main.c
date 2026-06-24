#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pila.h"
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;
///Ejercicio 1
void agregarAlFinal(char nombreArchivo[], int dato);
///Ejercicio 2
void mostrarArchivoBinario(char nombreArchivo[]);
///Ejercicio 3
int contarElementos(char nombreArchivo[]);
///Ejercicio 4
stAlumno cargarUnAlumno();
void cargarAlumnos(char nombreArchivo[]);
///Ejercicio 5
void mostrarUnAlumno(stAlumno a);
void mostrarAlumnos(char nombreArchivo[]);
///Ejercicio 6
void agregarUnAlumno(char nombreArchivo[]);
///Ejercicio 7
void copiarLegajosMayoresAPila(char nombreArchivo[], Pila* p);
///Ejercicio 8
int contarMayores(char nombreArchivo[], int edad);
///Ejercicio 9
void mostrarNombreAlumno(stAlumno a);
void mostrarPorRangoEdad(char nombreArchivo[], int edadMin, int edadMax);
///Ejercicio 10
void mostrarMayorEdad(char nombreArchivo[]);
///Ejercicio 11
int contarAlumnosPorAnio(char nombreArchivo[], int anio);
///Ejercicio 12
void arrayToFile(char nombreArchivo[], stAlumno alumnos[], int validos);
int fileToArray(char nombreArchivo[], stAlumno alumnos[], int anio);
///Ejercicio 13
int cantidadRegistros(char nombreArhcivo[], int tamRegistro);
///Ejercicio 14
void mostrarRegistro(char nombreArchivo[], int numRegistro);
///Ejercicio 15
void cargarAlumnoPorReferencia(stAlumno* a);
void modificarAlumno(char nombreArchivo[], int nroRegistro);
///Ejercicio 16
void invertirArchivo(char nombreArchivo[]);
int main()
{
    char archivoEnteros[] = "datos.bin";
    char archivoAlumnos[] = "alumnos.dat";
    ///Ej 1 2 y 3
    srand(time(NULL));
    int numero = rand() % 100;
    agregarAlFinal(archivoEnteros, numero);

    printf("\nArchivo de datos simples:\n");

    mostrarArchivoBinario(archivoEnteros);

    int cantidad = contarElementos(archivoEnteros);
    printf("Cantidad de elemento en el archivo: %d\n", cantidad);
    system("pause");
    system("cls");

    ///Ej 4
    cargarAlumnos(archivoAlumnos);
    system("pause");
    system("cls");

    ///Ej 5
    mostrarAlumnos(archivoAlumnos);
    system("pause");
    system("cls");

    ///Ej 6
    printf("Antes de agregar al alumno: ");
    mostrarAlumnos(archivoAlumnos);
    system("pause");
    system("cls");

    agregarUnAlumno(archivoAlumnos);

    printf("Después de agregar al alumno: ");
    mostrarAlumnos(archivoAlumnos);
    system("pause");
    system("cls");

    ///Ej 7
    Pila mayores;
    inicpila(&mayores);

    copiarLegajosMayoresAPila(archivoAlumnos, &mayores);
    printf("Pila mayores:\n");
    mostrar(&mayores);
    system("pause");
    system("cls");

    ///Ej 8
    int cantM;
    int edad;
    printf("Ingrese la edad a comparar: ");
    scanf("%d", &edad);

    cantM = contarMayores(archivoAlumnos, edad);
    printf("Cantidad de alumnos mayores a la edad %d: %d\n", edad, cantM);
    system("pause");
    system("cls");

    ///Ej 9
    int edadMin, edadMax;
    printf("Ingrese la edad mínima y máxima: ");
    scanf("%d %d", &edadMin, &edadMax);

    printf("Alumnos entre %d y %d anios de edad:\n", edadMin, edadMax);
    mostrarPorRangoEdad(archivoAlumnos, edadMin, edadMax);
    system("pause");
    system("cls");


    ///Ej 10
    mostrarMayorEdad(archivoAlumnos);
    system("pause");
    system("cls");


    ///Ej 11
    int anio;
    int cantAnio;
    printf("Ingrese el anio a buscar: ");
    scanf("%d", &anio);

    cantAnio = contarAlumnosPorAnio(archivoAlumnos, anio);
    printf("Cantidad de alumnos en el %d anio: %d\n", anio, cantAnio);
    system("pause");
    system("cls");

    ///Ej 12
    stAlumno alumnos[100];
    int validos = 0;
    arrayToFile(archivoAlumnos, alumnos, validos);

    validos = fileToArray(archivoAlumnos, alumnos, 2);

    printf("Cantidad de alumos de 2° anio: %d\n", validos);
    system("pause");
    system("cls");

    ///Ej 13
    int cant = cantidadRegistros(archivoAlumnos, sizeof(stAlumno));

    printf("Cantidad de registros: %d\n", cant);
    system("pause");
    system("cls");

    ///Ej 14
    int nroRegistro;
    printf("Ingrese el nro de registro a mostrar: ");
    scanf("%d", &nroRegistro);

    mostrarRegistro(archivoAlumnos, nroRegistro);
    system("pause");
    system("cls");


    ///Ej 15
    modificarAlumno(archivoAlumnos, 0);
    system("pause");
    system("cls");

    ///Ej 16
    printf("\nAntes:\n");
    mostrarAlumnos(archivoAlumnos);

    invertirArchivo(archivoAlumnos);

    printf("\nAhora:\n");
    mostrarAlumnos(archivoAlumnos);
    system("pause");
    system("cls");
    return 0;
}


///Ejercicio 1
void agregarAlFinal(char nombreArchivo[], int dato)
{
    FILE* f = fopen(nombreArchivo, "ab");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fwrite(&dato, sizeof(int), 1, f);
    fclose(f);
}

///Ejercicio 2
void mostrarArchivoBinario(char nombreArchivo[])
{
    FILE* f = fopen(nombreArchivo, "rb");
    int aux;
    if(f != NULL)
    {
        printf("\nContenido del archivo: \n");
        while(fread(&aux, sizeof(int), 1, f) > 0)
        {
            printf("%d \n", aux);
        }
    }
    fclose(f);
}

///Ejercicio 3
int contarElementos(char nombreArchivo[])
{
    int rdo = 0;
    int aux;
    FILE* f = fopen(nombreArchivo, "rb");
    if(f != NULL)
    {
        while(fread(&aux, sizeof(int), 1, f) > 0)
        {
            rdo++;
        }
    }
    fclose(f);
    return rdo;
}


///Ejercicio 4
stAlumno cargarUnAlumno()
{
    stAlumno a;

    puts("\n----------------------\n");
    printf("Ingrese el legajo: ");
    scanf("%d", &a.legajo);
    getchar();

    printf("Ingrese nombre y apellido: ");
    fgets(a.nombreYapellido, 30, stdin);
    a.nombreYapellido[strcspn(a.nombreYapellido, "\n")] = '\0';

    printf("Ingrese la edad: ");
    scanf("%d", &a.edad);

    printf("Ingrese el anio que cursa: ");
    scanf("%d", &a.anio);
    puts("\n----------------------\n");

    return a;
}

void cargarAlumnos(char nombreArchivo[])
{
    int cont = 0;
    stAlumno a;
    FILE* archi = fopen(nombreArchivo, "ab");

    if(archi != NULL)
    {
        printf("Ingreso de 5 alumnos:\n");
        while(cont < 5)
        {
            a = cargarUnAlumno();
            fwrite(&a, sizeof(stAlumno), 1, archi);
            cont++;
        }
    }
    fclose(archi);
}


///Ejercicio 5
void mostrarUnAlumno(stAlumno a)
{
    printf("Legajo: %d | Nombre completo: %s | Edad: %d | Anio: %d\n",
           a.legajo, a.nombreYapellido, a.edad, a.anio);
}

void mostrarAlumnos(char nombreArchivo[])
{
    stAlumno a;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0)
        {
            mostrarUnAlumno(a);
        }
    }
    fclose(archi);
}

///Ejercicio 6
void agregarUnAlumno(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "ab");
    stAlumno a;
    if(archi != NULL)
    {
        a = cargarUnAlumno();
        fwrite(&a, sizeof(stAlumno), 1, archi);
        fclose(archi);
    }
}

///Ejercicio 7
void copiarLegajosMayoresAPila(char nombreArchivo[], Pila* p)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0)
        {
            if(a.edad >= 18)
            {
                apilar(p, a.legajo);
            }
        }
        fclose(archi);
    }
}

///Ejercicio 8
int contarMayores(char nombreArchivo[], int edad)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    int contador = 0;
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0)
        {
            if(a.edad > edad)
            {
                contador++;
            }
        }
        fclose(archi);
    }
    return contador;
}

///Ejercicio 9
void mostrarNombreAlumno(stAlumno a)
{
    printf("Nombre completo: %s\n", a.nombreYapellido);
}

void mostrarPorRangoEdad(char nombreArchivo[], int edadMin, int edadMax)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0)
        {
            if(a.edad >= edadMin && a.edad <= edadMax)
            {
                mostrarNombreAlumno(a);
            }
        }
        fclose(archi);
    }
}


///Ejercicio 10
void mostrarMayorEdad(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    stAlumno mayor;
    if(archi != NULL)
    {
        if (fread(&mayor, sizeof(stAlumno), 1, archi) > 0)
        {
            while (fread(&a, sizeof(stAlumno), 1, archi) > 0)
            {
                if (a.edad > mayor.edad)
                {
                    mayor = a;
                }
            }

            printf("Alumno de mayor edad:\n");
            mostrarUnAlumno(mayor);
        }
        else
        {
            printf("El archivo esta vacio.\n");
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

///Ejercicio 11
int contarAlumnosPorAnio(char nombreArchivo[], int anio)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    int contador = 0;
    if(archi != NULL)
    {
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0)
        {
            if(a.anio == anio)
            {
                contador++;
            }
        }
        fclose(archi);
    }
    return contador;
}

///Ejercicio 12
void arrayToFile(char nombreArchivo[], stAlumno alumnos[], int validos)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi != NULL)
    {
        fwrite(alumnos, sizeof(stAlumno), 1, archi);
        fclose(archi);
    }
}

int fileToArray(char nombreArchivo[], stAlumno alumnos[], int anio)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno aux;
    int i = 0;
    if(archi != NULL)
    {
        while(fread(&aux, sizeof(stAlumno), 1, archi) > 0)
        {
            if(aux.anio == anio)
            {
                alumnos[i] = aux;
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

///Ejercicio 13
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

///Ejercicio 14
void mostrarRegistro(char nombreArchivo[], int numRegistro)
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stAlumno a;
    int cantRegistros;
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        cantRegistros = ftell(archi) / sizeof(stAlumno);
        if(numRegistro >= 0 && numRegistro < cantRegistros)
        {
            fseek(archi, numRegistro * sizeof(stAlumno), SEEK_SET);
            fread(&a, sizeof(stAlumno), 1, archi);
            mostrarUnAlumno(a);
        }
        else
        {
            printf("Número de registro fuera de rango\n");
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
}


///Ejercicio 15
void cargarAlumnoPorReferencia(stAlumno* a)
{
    printf("Ingrese legajo: ");
    scanf("%d", &a->legajo);
    getchar();

    printf("Ingrese nombre y apellido: ");
    fgets(a->nombreYapellido, 30, stdin);
    a->nombreYapellido[strcspn(a->nombreYapellido, "\n")] = '\0';

    printf("Ingrese edad: ");
    scanf("%d", &a->edad);

    printf("Ingrese el anio que cursa: ");
    scanf("%d", &a->anio);
}
void modificarAlumno(char nombreArchivo[], int nroRegistro)
{
    FILE* archi = fopen(nombreArchivo, "r+b");
    stAlumno a;
    int cantRegistros;
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        cantRegistros = ftell(archi) / sizeof(stAlumno);

        if(nroRegistro >= 0 && nroRegistro < cantRegistros)
        {
            fseek(archi, nroRegistro * sizeof(stAlumno), SEEK_SET);
            fread(&a, sizeof(stAlumno), 1, archi);

            printf("\nIngrese los nuevos datos:\n");
            cargarAlumnoPorReferencia(&a);

            fseek(archi, nroRegistro * sizeof(stAlumno), SEEK_SET);
            fwrite(&a, sizeof(stAlumno), 1, archi);
            printf("Registro modificado correctamente\n");
        }
        else
        {
            printf("Nro de registro fuera de rango\n");
        }
        fclose(archi);
    }
}

///Ejercicio 16
void invertirArchivo(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "r+b");
    stAlumno a1, a2;
    int cantRegistros;
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        cantRegistros = ftell(archi) / sizeof(stAlumno);
        for(int i = 0; i < cantRegistros / 2; i++)
        {
            fseek(archi, i * sizeof(stAlumno), SEEK_SET);
            fread(&a1, sizeof(stAlumno), 1, archi);

            fseek(archi, (cantRegistros - 1 - i) * sizeof(stAlumno), SEEK_SET);
            fread(&a2, sizeof(stAlumno), 1, archi);

            fseek(archi, i * sizeof(stAlumno), SEEK_SET);
            fwrite(&a2, sizeof(stAlumno), 1, archi);

            fseek(archi, (cantRegistros - 1 - i) * sizeof(stAlumno), SEEK_SET);
            fwrite(&a1, sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}

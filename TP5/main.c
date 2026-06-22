#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;
///Ejercicio 1
int cargarArregloAlumnos(stAlumno alumnos[], int dim);
///Ejercicio 2
void mostrarUnAlumno(stAlumno a);
void mostrarArregloAlumnos(stAlumno alumnos[], int validos);
///Ejercicio 3
void mostrarPorMatricula(stAlumno alumnos[], int validos, int matriculaBuscada);
///Ejercicio 4
int buscarMenorMatricula(stAlumno alumnos[], int validos, int pos);
void intercambiar(stAlumno alumnos[], int pos1, int pos2);
void ordenamientoSeleccion(stAlumno alumnos[], int validos);
///Ejercicio 5
void mostrarPorGenero(stAlumno alumnos[], int validos, char generoBuscado);
///Ejercicio 6
int insertarOrdenado(stAlumno alumnos[], int validos, stAlumno nuevo, int dim);
///Ejercicio 7
void ordenamientoInsercion(stAlumno alumnos[], int validos);
///Ejercicio 8
int contarPorGenero(stAlumno alumnos[], int validos, char generoBuscado);
///Ejercicio 9

int main()
{
    stAlumno alumnos[100];
    stAlumno nuevo;
    int validos = 0;
    int opcion;
    int matricula;
    char genero;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Cargar alumnos\n");
        printf("2. Mostrar alumnos\n");
        printf("3. Buscar por matricula\n");
        printf("4. Ordenar por matricula (Seleccion)\n");
        printf("5. Mostrar por genero\n");
        printf("6. Insertar alumno ordenado por matricula\n");
        printf("7. Ordenar por nombre (Insercion)\n");
        printf("8. Contar alumnos por genero\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            validos = cargarArregloAlumnos(alumnos, 100);
            break;

        case 2:
            mostrarArregloAlumnos(alumnos, validos);
            break;

        case 3:
            printf("Ingrese la matricula: ");
            scanf("%d", &matricula);
            mostrarPorMatricula(alumnos, validos, matricula);
            break;

        case 4:
            ordenamientoSeleccion(alumnos, validos);
            printf("Arreglo ordenado por matricula.\n");
            break;

        case 5:
            printf("Ingrese el genero (m/f/o): ");
            scanf(" %c", &genero);
            mostrarPorGenero(alumnos, validos, genero);
            break;

        case 6:
            printf("Ingrese la matricula: ");
            scanf("%d", &nuevo.matricula);
            getchar();

            printf("Ingrese el nombre: ");
            fgets(nuevo.nombre, 30, stdin);
            nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

            printf("Ingrese el genero: ");
            scanf(" %c", &nuevo.genero);

            validos = insertarOrdenado(alumnos, validos, nuevo, 100);
            break;

        case 7:
            ordenamientoInsercion(alumnos, validos);
            printf("Arreglo ordenado por nombre.\n");
            break;

        case 8:
        {
            int cantidad;

            printf("Ingrese el genero (m/f/o): ");
            scanf(" %c", &genero);

            cantidad = contarPorGenero(alumnos, validos, genero);

            printf("Cantidad: %d\n", cantidad);
            break;
        }

        case 0:
            printf("Fin del programa.\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
        }

    } while(opcion != 0);
    return 0;
}


///Ejercicio 1
int cargarArregloAlumnos(stAlumno alumnos[], int dim)
{
    int validos = 0;
    char seguir = 's';
    while(validos < dim && (seguir == 's' || seguir == 'S'))
    {
        printf("Ingrese la matricula: ");
        scanf("%d", &alumnos[validos].matricula);
        getchar();

        printf("Ingrese el nombre: ");
        fgets(alumnos[validos].nombre, 30, stdin);
        alumnos[validos].nombre[strcspn(alumnos[validos].nombre, "\n")] = '\0';

        printf("Ingrese el género (m/f/o): ");
        scanf(" %c", &alumnos[validos].genero);

        validos++;

        printf("¿Desea cargar más alumnos? (s/n): ");
        scanf(" %c", &seguir);
    }
    return validos;
}

///Ejercicio 2
void mostrarUnAlumno(stAlumno a)
{
    printf("Matricula: %d | Nombre: %s | Género: %c\n",
           a.matricula, a.nombre, a.genero);
}


void mostrarArregloAlumnos(stAlumno alumnos[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        mostrarUnAlumno(alumnos[i]);
        printf("------------------------\n");
    }
}

///Ejercicio 3
void mostrarPorMatricula(stAlumno alumnos[], int validos, int matriculaBuscada)
{
    int i = 0;
    int flag = 0;
    while(i < validos && flag == 0)
    {
        if(alumnos[i].matricula == matriculaBuscada)
        {
            mostrarUnAlumno(alumnos[i]);
            flag = 1;
        }
        i++;
    }
    if(flag == 0)
    {
        printf("No se encontraron alumnos con esa matricula\n");
    }
}


///Ejercicio 4
int buscarMenorMatricula(stAlumno alumnos[], int validos, int pos)
{
    int i;
    int posMenor = pos;
    for(i = pos + 1; i < validos; i++)
    {
        if(alumnos[i].matricula < alumnos[posMenor].matricula)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void intercambiar(stAlumno alumnos[], int pos1, int pos2)
{
    stAlumno aux;
    aux = alumnos[pos1];
    alumnos[pos1] = alumnos[pos2];
    alumnos[pos2] = aux;
}

void ordenamientoSeleccion(stAlumno alumnos[], int validos)
{
    int i;
    int posMenor;
    for(i = 0; i < validos - 1; i++)
    {
        posMenor = buscarMenorMatricula(alumnos, validos, i);
        intercambiar(alumnos, i, posMenor);
    }
}

///Ejercicio 5
void mostrarPorGenero(stAlumno alumnos[], int validos, char generoBuscado)
{
    int flag = 0;
    int i = 0;
    for(i = 0; i < validos; i++)
    {
        if(alumnos[i].genero == generoBuscado)
        {
             mostrarUnAlumno(alumnos[i]);
            flag = 1;
            printf("\n------------------\n");
        }
    }

    if(flag == 0)
    {
        printf("No se encontraron alumnos con esa matricula\n");
    }
}


///Ejercicio 6
int insertarOrdenado(stAlumno alumnos[], int validos, stAlumno nuevo, int dim)
{
    int i;
    if(validos >= dim)
    {
        printf("El arreglo está lleno\n");
        return validos;
    }

    i = validos - 1;
    while(i >= 0 && alumnos[i].matricula > nuevo.matricula)
    {
        alumnos[i+1] = alumnos[i];
        i--;
    }
    alumnos[i+1] = nuevo;
    return validos + 1;
}

///Ejercicio 7
void ordenamientoInsercion(stAlumno alumnos[], int validos)
{
    int i, j;
    stAlumno aux;
    for(i = 1; i < validos; i++)
    {
        aux = alumnos[i];
        j = i - 1;
        while(j >= 0 && strcmp(alumnos[j].nombre, aux.nombre) > 0)
        {
            alumnos[j + 1] = alumnos[j];
            j--;
        }
        alumnos[j + 1] = aux;
    }
}

///Ejercicio 8
int contarPorGenero(stAlumno alumnos[], int validos, char generoBuscado)
{
    int i;
    int contador = 0;
    for(i = 0; i < validos; i++)
    {
        if(alumnos[i].genero == generoBuscado)
        {
            contador++;
        }
    }
    return contador;
}

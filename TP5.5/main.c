#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PELICULAS 50
#define MAX_SUCURSALES 20

typedef struct
{
    char nombre[50];
    char genero[30];
    int duracion;   // en minutos
} stPelicula;

typedef struct
{
    int id;
    char nombre[20];
    char direccion[20];

    stPelicula cartelera[MAX_PELICULAS];
    int validosPeliculas;
} stSucursal;
///Ejercicio 1
stPelicula cargarPelicula();
stSucursal cargarSucursal();
///Ejercicio 2
void mostrarPelicula(stPelicula p);
void mostrarSucursal(stSucursal s);
void mostrarSucursales(stSucursal sucursales[], int validos);
///Ejercicio 3
int buscarSucursalPorID(stSucursal sucursales[], int validos, int idBuscado);
void mostrarSucursalPorID(stSucursal sucursales[], int validos);
///Ejercicio 4
void filtrarGenero(stSucursal sucursales[], int validos);
///Ejercicio 5
int buscarMenorID(stSucursal sucursales[], int validos, int pos);
void intercambio(stSucursal* a, stSucursal* b);
void ordenamientoSeleccion(stSucursal sucursales[], int validos);
///Ejercicio 6
void actualizarCartelera(stSucursal sucursales[], int validos);
///Ejercicio 7
void eliminarPelicula(stSucursal sucursales[], int validos);
int buscarPelicula(stSucursal s, char nombre[]);
///Ejercicio 8
float calcularPromedio(stSucursal s);
void mostrarPromedioDuracion(stSucursal sucursales[], int validos);
///Ejercicio 9
void listarPeliculas(stSucursal sucursales[], int validos);
///Ejercicio 10
int buscarMenorDuracion(stPelicula cartelera[], int validos, int pos);
void intercambioPeli(stPelicula* a, stPelicula* b);
void ordenamientoSeleccionPeli(stSucursal sucursales[], int validos);
///Ejercicio 11
void buscarPeliculaSucursales(stSucursal sucursales[], int validos);
///Ejercicio 12
void generoMasComun(stSucursal sucursales[], int validos);
int main()
{
    ///Ej 1
    stSucursal sucursales[MAX_SUCURSALES];
    int validos = 0;
    char opcion = 's';
    while((opcion == 's' || opcion == 'S') && validos < MAX_SUCURSALES)
    {
        sucursales[validos] = cargarSucursal();
        validos++;

        printf("\n¿Desea cargar otra sucursal? (s/n): ");
        scanf(" %c", &opcion);
        getchar();
    }
    system("pause");
    system("cls");

    ///Ej 2
    mostrarSucursales(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 3
    mostrarSucursalPorID(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 4
    filtrarGenero(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 5
    printf("\nAntes:\n");
    mostrarSucursales(sucursales, validos);

    ordenamientoSeleccion(sucursales, validos);

    printf("\nAhora:\n");
    mostrarSucursales(sucursales, validos);
    system("pause");
    system("cls");


    ///Ej 6
    actualizarCartelera(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 7
    eliminarPelicula(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 8
    mostrarPromedioDuracion(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 9
    listarPeliculas(sucursales, validos);
    system("pause");
    system("cls");


    ///Ej 10
    ordenamientoSeleccionPeli(sucursales, validos);
    mostrarSucursalPorID(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 11
    buscarPeliculaSucursales(sucursales, validos);
    system("pause");
    system("cls");

    ///Ej 12
    generoMasComun(sucursales, validos);
    system("pause");
    system("cls");
    return 0;
}


///Ejercicio 1
stPelicula cargarPelicula()
{
    stPelicula aux;

    printf("Nombre de la pelicula: ");
    fgets(aux.nombre, 50, stdin);
    aux.nombre[strcspn(aux.nombre, "\n")] = '\0';

    printf("Género: ");
    fgets(aux.genero, 30, stdin);
    aux.genero[strcspn(aux.genero, "\n")] = '\0';

    printf("Duración: ");
    scanf("%d", &aux.duracion);
    getchar();

    return aux;
}

stSucursal cargarSucursal()
{
    stSucursal aux;

    char opcion = 's';

    printf("ID de la sucursal: ");
    scanf("%d", &aux.id);
    getchar();

    printf("Nombre de la sucursal: ");
    fgets(aux.nombre, 20, stdin);
    aux.nombre[strcspn(aux.nombre, "\n")] = '\0';

    printf("Dirección: ");
    fgets(aux.direccion, 20, stdin);
    aux.direccion[strcspn(aux.direccion, "\n")] = '\0';

    aux.validosPeliculas = 0;
    while((opcion == 's' || opcion == 'S') && aux.validosPeliculas < MAX_PELICULAS)
    {
        aux.cartelera[aux.validosPeliculas] = cargarPelicula();
        aux.validosPeliculas++;

        printf("\n¿Desea cargar otra pelicula? (s/n): ");
        scanf(" %c", &opcion);
        getchar();
    }

    return aux;
}

///Ejercicio 2
void mostrarPelicula(stPelicula p)
{
    printf("Nombre: %s | Género: %s | Duración: %d mins\n",
           p.nombre, p.genero, p.duracion);
}

void mostrarSucursal(stSucursal s)
{
    printf("\n==================\n");
    printf("ID: %d | Nombre: %s | Direccion: %s\n",
           s.id, s.nombre, s.direccion);

    for(int i = 0; i < s.validosPeliculas; i++)
    {
        printf("Pelicula %d\n", i + 1);
        mostrarPelicula(s.cartelera[i]);
    }
}

void mostrarSucursales(stSucursal sucursales[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        mostrarSucursal(sucursales[i]);
    }
}


///Ejercicio 3
int buscarSucursalPorID(stSucursal sucursales[], int validos, int idBuscado)
{
    int i = 0;
    while(i < validos && sucursales[i].id != idBuscado)
    {
        i++;
    }

    if(i == validos)
    {
        return -1;
    }

    else
    {
        return i;
    }
}

void mostrarSucursalPorID(stSucursal sucursales[], int validos)
{
    int idBuscado;
    int pos;

    printf("Ingrese el ID de la sucursal a buscar: ");
    scanf("%d", &idBuscado);

    pos = buscarSucursalPorID(sucursales, validos, idBuscado);
    if(pos != -1)
    {
        mostrarSucursal(sucursales[pos]);
    }
    else
    {
        printf("No existe ninguna sucursal con ese ID\n");
    }
}

///Ejercicio 4
void filtrarGenero(stSucursal sucursales[], int validos)
{
    int id, pos, i;
    char generoBuscado[30];
    int encontrado = 0;

    printf("Ingrese el ID de la sucursal: ");
    scanf("%d", &id);
    getchar();
    pos = buscarSucursalPorID(sucursales, validos, id);

    if(pos == -1)
    {
        printf("No existe ninguna sucursal con ese ID\n");
    }
    else
    {
        printf("Ingrese el género a buscar: ");
        fgets(generoBuscado, 30, stdin);
        generoBuscado[strcspn(generoBuscado, "\n")] = '\0';

        printf("Peliculas del género %s:\n\n", generoBuscado);
        for(i = 0; i < sucursales[pos].validosPeliculas; i++)
        {
            if(strcmp(sucursales[pos].cartelera[i].genero, generoBuscado) == 0)
            {
                mostrarPelicula(sucursales[pos].cartelera[i]);
                printf("\n");
                encontrado = 1;
            }
        }
        if(encontrado == 0)
        {
            printf("No hay peliculas de ese género\n");
        }
    }
}

///Ejercicio 5
int buscarMenorID(stSucursal sucursales[], int validos, int pos)
{
    int i;
    int posMenor = pos;

    for(i = pos + 1; i < validos; i++)
    {
        if(sucursales[i].id < sucursales[posMenor].id)
        {
            posMenor = i;
        }
    }
    return posMenor;
}


void intercambio(stSucursal* a, stSucursal* b)
{
    stSucursal aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenamientoSeleccion(stSucursal sucursales[], int validos)
{
    int i;
    int posMenor;
    for(i = 0; i < validos - 1; i++)
    {
        posMenor = buscarMenorID(sucursales, validos, i);
        intercambio(&sucursales[i], &sucursales[posMenor]);
    }
}


///Ejercicio 6
void actualizarCartelera(stSucursal sucursales[], int validos)
{
    int id, pos;
    char opcion = 's';

    printf("Ingrese el ID de la sucursal a buscar: ");
    scanf("%d", &id);
    getchar();

    pos = buscarSucursalPorID(sucursales, validos, id);

    if(pos == -1)
    {
        printf("La sucursal no existe\n");
    }
    else
    {
        sucursales[pos].validosPeliculas = 0;
        while((opcion == 's' || opcion == 'S') && sucursales[pos].validosPeliculas < MAX_PELICULAS)
        {
            sucursales[pos].cartelera[sucursales[pos].validosPeliculas] = cargarPelicula();
            sucursales[pos].validosPeliculas++;

            printf("¿Desea cargar otra pelicula? (s/n): ");
            scanf(" %c", &opcion);
            getchar();
        }
        printf("Cartelera actualizada correctamente\n");
    }
}


///Ejercicio 7
int buscarPelicula(stSucursal s, char nombre[])
{
    int i = 0;
    while(i < s.validosPeliculas && strcmp(s.cartelera[i].nombre, nombre) != 0)
    {
        i++;
    }
    if(i == s.validosPeliculas)
    {
        return -1;
    }
    return i;
}

void eliminarPelicula(stSucursal sucursales[], int validos)
{
    int id, posSucursal, posPelicula;
    int i;
    char nombre[50];

    printf("Ingrese el ID de la sucursal a buscar: ");
    scanf("%d", &id);
    getchar();

    posSucursal = buscarSucursalPorID(sucursales, validos, id);
    if(posSucursal == -1)
    {
        printf("No existen sucursales con ese ID\n");
    }
    else
    {
        printf("Ingrese el nombre de la pelicula: ");
        fgets(nombre, 50, stdin);
        nombre[strcspn(nombre, "\n")] = '\0';

        posPelicula = buscarPelicula(sucursales[posSucursal], nombre);
        if(posPelicula == -1)
        {
            printf("La pelicula no existe en ninguna sucursal\n");
        }
        else
        {
            for(i = posPelicula; i < sucursales[posSucursal].validosPeliculas - 1; i++)
            {
                sucursales[posSucursal].cartelera[i] =
                    sucursales[posSucursal].cartelera[i + 1];
            }
            sucursales[posSucursal].validosPeliculas--;
            printf("Pelicula eliminada correctamente\n");
        }
    }
}


///Ejercicio 8
float calcularPromedio(stSucursal s)
{
    int i;
    int suma = 0;
    float promedio = 0;
    if(s.validosPeliculas > 0)
    {
        for(i = 0; i < s.validosPeliculas; i++)
        {
            suma+= s.cartelera[i].duracion;
        }
        promedio = (float)suma / s.validosPeliculas;
    }
    return promedio;
}

void mostrarPromedioDuracion(stSucursal sucursales[], int validos)
{
    int id, pos;

    printf("Ingrese el ID de la sucursal a buscar: ");
    scanf("%d", &id);

    pos = buscarSucursalPorID(sucursales, validos, id);

    if(pos == -1)
    {
        printf("No existen sucursales con ese ID\n");
    }
    else
    {
        printf("\nPromedio de duración: %.2f minutos\n",
               calcularPromedio(sucursales[pos]));
    }
}


///Ejercicio 9
void listarPeliculas(stSucursal sucursales[], int validos)
{
    int i, j;
    printf("\n---LISTA DE PELÍCULAS---\n");
    for(i = 0; i < validos; i++)
    {
        for(j = 0; j < sucursales[i].validosPeliculas; j++)
        {
            mostrarPelicula(sucursales[i].cartelera[j]);
            printf("\n-------------------------------\n");
        }
    }
}

///Ejercicio 10
int buscarMenorDuracion(stPelicula cartelera[], int validos, int pos)
{
    int i;
    int posMenor = pos;
    for(i = pos + 1; i < validos; i++)
    {
        if(cartelera[i].duracion < cartelera[posMenor].duracion)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void intercambioPeli(stPelicula* a, stPelicula* b)
{
    stPelicula aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenamientoSeleccionPeli(stSucursal sucursales[], int validos)
{
    int id;
    int pos, menor;
    printf("Ingrese el ID de la sucursal a buscar: ");
    scanf("%d", &id);

    pos = buscarSucursalPorID(sucursales, validos, id);
    if(pos == -1)
    {
        printf("No existen sucursales con ese ID\n");
    }
    else
    {
        for(int i = 0; i < sucursales[pos].validosPeliculas - 1; i++)
        {
            menor = buscarMenorDuracion(sucursales[pos].cartelera, sucursales[pos].validosPeliculas, i);
            intercambioPeli(&sucursales[pos].cartelera[i], &sucursales[pos].cartelera[menor]);
        }
    }
}


void buscarPeliculaSucursales(stSucursal sucursales[], int validos)
{
    char nombre[50];
    int i, pos;
    int encontrado = 0;

    printf("Ingrese el nombre de la pelicula: ");
    getchar();
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    printf("\nLa pelicula se encuentra en:\n\n");

    for(i = 0; i < validos; i++)
    {
        pos = buscarPelicula(sucursales[i], nombre);

        if(pos != -1)
        {
            printf("ID: %d\n", sucursales[i].id);
            printf("Nombre: %s\n\n", sucursales[i].nombre);
            encontrado = 1;
        }
    }

    if(encontrado == 0)
    {
        printf("La pelicula no se encuentra en ninguna sucursal\n");
    }
}

///Ejercicio 12
void generoMasComun(stSucursal sucursales[], int validos)
{
    int id, pos;
    int i, j;
    int contador;
    int mayor = 0;
    char genero[30];

    printf("Ingrese el ID de la sucursal: ");
    scanf("%d", &id);

    pos = buscarSucursalPorID(sucursales, validos, id);
    if(pos == -1)
    {
        printf("No existen sucursales con ese ID\n");
    }
    else
    {
        if(sucursales[pos].validosPeliculas == 0)
        {
            printf("La sucursal no tiene peliculas.\n");
            return;
        }
        for(i = 0; i < sucursales[pos].validosPeliculas; i++)
        {
            contador = 1;
            for(j = i + 1; j < sucursales[pos].validosPeliculas; j++)
            {
                if(strcmp(sucursales[pos].cartelera[i].genero, sucursales[pos].cartelera[j].genero) == 0)
                {
                    contador++;
                }
            }
            if(contador > mayor)
            {
                mayor = contador;
                strcpy(genero, sucursales[pos].cartelera[i].genero);
            }
        }
        printf("\nGénero más comun: %s\n", genero);
        printf("\nCantidad de películas: %d\n", mayor);
    }
}

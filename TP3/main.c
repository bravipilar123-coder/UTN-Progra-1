#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Ejercicio 1
int cargarArreglo(int A[], int dimension);
int cargarArregloChar(char B[], int dimension);
int cargarReales(float D[], int dimension);
///Ejercicio 2
void mostrarArreglo(int A[], int validos);
void mostrarArregloChar(char B[], int validos2);
///Ejercicio 3
int sumarArreglo(int A[], int validos);
///Ejercicio 4
void copiarPila(int A[], Pila* p, int validos);
///Ejercicio 5
float sumaReales(float D[], int validosR);
///Ejercicio 6
int buscarChar(char B[], int validos, char dato);
///Ejercicio 7
int insertarCaracter(char B[], int validos, char elemento);
///Ejercicio 8
char buscarMayor(char B[], int validos2);
int buscarMenor(int B[], int validos);
///Ejercicio 9
int esCapicua(int E[], int validos);
///Ejercicio 10
void invertirArreglo(int A[], int validos);
///Ejercicio 11
int posicionMenor(int A[], int validos, int pos);
void ordenamientoSeleccion(int A[], int validos);
void insertar(int A[], int u, int dato);
void ordenamientoInsercion(int A[], int validos);
///Ejercicio 12
int charIntercalado(char F[], int validosF, char G[], int validosG, char H[], int cantidadH);
int main()
{
    int A[5] = {0};
    char B[10] = {0};
    //int C[5] = {0};
    float D[100] = {0};
    int E[5] = {0};
    char F[4] = {0};
    char G[5] = {0};
    char H[20] = {0};
    ///Ejercicio 1
    int validos = cargarArreglo(A, 5);
    printf("Cantidad de elementos cargados en el arreglo: %d\n", validos);

    ///Ejercicio 2
    mostrarArreglo(A, validos);


    ///Ejercicio 3
    int rdo = sumarArreglo(A, validos);
    printf("El resultado de la suma de la lista A es: %d\n", rdo);

    ///Ejercicio 4
    Pila miPila;
    inicpila(&miPila);
    copiarPila(A, &miPila, validos);
    printf("\nPila miPila:\n");
    mostrar(&miPila);

    ///Ejercicio 5
    int validosR = cargarReales(D, 100);
    float sumaR = sumaReales(D, validosR);
    printf("El resultado de la suma de la lista D es: %.2f\n", sumaR);

    ///Ejercicio 6
    int validos2 = cargarArregloChar(B, 10);
    char dato3 = 0;
    printf("Ingrese la letra a buscar en el arreglo: ");
    fflush(stdin);
    scanf(" %c", &dato3);
    int flag = buscarChar(B, validos2, dato3);
    if(flag == 1)
    {
        printf("Le letra %c se encuentra en el arreglo\n", dato3);
    }
    else
    {
        printf("Le letra %c no se encuentra en el arreglo\n", dato3);
    }

    ///Ejercicio 7
    char elemento = 0;
    printf("Ingrese el caracter a insertar en el arreglo ordenado:\n");
    fflush(stdin);
    scanf(" %c", &elemento);
    validos2 = insertarCaracter(B, validos2, elemento);
    printf("Arreglo luego de insertar el nuevo carácter:\n");
    mostrarArregloChar(B, validos2);

    ///Ejercicio 8
    char mayor = buscarMayor(B, validos2);
    printf("El elemento mayor de la lista B es: %c\n", mayor);

    ///Ejercicio 9
    int validosC = cargarArreglo(E, 5);
    int flag2 = esCapicua(E, validosC);
    if(flag2 == 0)
    {
        printf("El arreglo es capicua\n");
    }
    else
    {
        printf("El arreglo no es capicua\n");
    }

    ///Ejercicio 10
    invertirArreglo(A, validos);
    printf("\nArreglo invertido:\n");
    mostrarArreglo(A, validos);

    ///Ejercicio 11
    printf("\nArreglo en ordenamiento por selección:\n");
    int arregloSeleccion[] = {4,1,2,8,9,10,3,5};
    mostrarArreglo(arregloSeleccion, 8);
    ordenamientoSeleccion(arregloSeleccion, 8);
    mostrarArreglo(arregloSeleccion, 8);

    printf("\nArreglo en ordenamiento por inserción:\n");
    int arregloInsercion[] = {4,1,2,8,9,10,3,5};
    mostrarArreglo(arregloInsercion, 8);
    ordenamientoInsercion(arregloInsercion, 8);
    mostrarArreglo(arregloInsercion, 8);


    ///Ejercicio 12
    int validosF = cargarArregloChar(F, 4);
    printf("Arreglo F:\n");
    mostrarArregloChar(F, validosF);

    int validosG = cargarArregloChar(G, 5);
    printf("Arreglo G:\n");
    mostrarArregloChar(G, validosG);

    int validosH = charIntercalado(F, validosF, G, validosG, H, 20);
    printf("Arreglo H:\n");
    mostrarArregloChar(H, validosH);
    return 0;
}


///Ejercicio 1
int cargarArreglo(int A[], int dimension)
{
    int validos = 0;
    char control = 's';
    while((control == 's') && (validos < dimension))
    {
        printf("Imgrese un nro entero: ");
        scanf("%d", &A[validos]);

        validos++;

        printf("¿Desea cargar más nros? (s/n): ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return validos;
}


int cargarArregloChar(char B[], int dimension)
{
    int validos2 = 0;
    while(validos2 < dimension)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf(" %c", &B[validos2]);
        validos2++;
    }
    return validos2;
}

int cargarReales(float D[], int dimension)
{
    int validosR = 0;
    char control = 's';
    while((control == 's') && (validosR < dimension))
    {
        printf("Ingrese un nro decimal: ");
        scanf("%f", &D[validosR]);

        validosR++;

        printf("¿Desea cargar más nros decimales? (s/n): ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return validosR;
}


///Ejercicio 2
void mostrarArreglo(int A[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("  [%d]  ", A[i]);
    }
    printf("\n");
}

void mostrarArregloChar(char B[], int validos2)
{
    for(int i = 0; i < validos2; i++)
    {
        printf(" | %c |", B[i]);
    }
}


///Ejercicio 3
int sumarArreglo(int A[], int validos)
{
    int suma = 0;
    int i = 0;
    for(i = 0; i < validos; i++)
    {
        suma = suma + A[i];
    }
    return suma;
}

///Ejercicio 4
void copiarPila(int A[], Pila* p, int validos)
{
    int i = 0;
    while(i < validos && i < 50)
    {
        apilar(p, A[i]);
        i++;
    }
}

///Ejercicio 5
float sumaReales(float D[], int validosR)
{
    float suma = 0;
    int i = 0;
    for(i = 0; i < validosR; i++)
    {
        suma = suma + D[i];
    }
    return suma;
}


///Ejercicio 6
int buscarChar(char B[], int validos, char dato)
{
    int i = 0;
    int flag = 0;
    while((i < validos) && (flag == 0))
    {
        if(dato == B[i])
        {
            flag = 1;
        }
        else
        {
            i++;
        }
    }
    return flag;
}


///Ejercicio 7
int insertarCaracter(char B[], int validos, char elemento)
{
    int ult = validos - 1;
    while(ult >= 0 && elemento < B[ult])
    {
        B[ult+1] = B[ult];
        ult--;
    }
    B[ult+1] = elemento;
    return validos+1;
}

///Ejercicio 8
char buscarMayor(char B[], int validos2)
{
    char miMayor = B[0];
    int i = 1;
    for(i = 1; i < validos2; i++)
    {
        if(miMayor < B[i])
        {
            miMayor = B[i];
        }
    }
    return miMayor;
}

int buscarMenor(int B[], int validos)
{
    int i = 1;
    int miMenor = B[0];
    for(i = 1; i < validos; i++)
    {
        if(miMenor > B[i])
        {
            miMenor = B[i];
        }
    }
    return miMenor;
}

///Ejercicio 9
int esCapicua(int E[], int validos)
{
    int flag = 0;
    int i = 0;
    int ult = validos - 1;
    while(i < ult && flag == 0)
    {
        if(E[i] == E[ult])
        {
            i++;
            ult--;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}


///Ejercicio 10
void invertirArreglo(int A[], int validos)
{
    int i = 0;
    int u = validos - 1;
    int aux;
    int tope = validos/2;
    while(i < tope)
    {
        aux = A[u];
        A[u] = A[i];
        A[i] = aux;
        i++;
        u--;
    }
}


///Ejercicio 11
int posicionMenor(int A[], int validos, int pos)
{
    int menor = A[pos];
    int posMenor = pos;
    int i = pos + 1;
    while(i < validos)
    {
        if(menor < A[i])
        {
            menor = A[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenamientoSeleccion(int A[], int validos)
{
    int posMenor;
    int aux;
    int i = 0;
    while(i < validos - 1)
    {
        posMenor = posicionMenor(A, validos, i);
        aux = A[posMenor];
        A[posMenor] = A[i];
        A[i] = aux;
        i++;
    }
}

void insertar(int A[], int u, int dato)
{
    while(u >= 0 && dato < A[u])
    {
        A[u+1] = A[u];
        u--;
    }
    A[u+1] = dato;
}

void ordenamientoInsercion(int A[], int validos)
{
    int i = 0;
    while(i < validos - 1)
    {
        insertar(A, i, A[i+1]);
        i++;
    }
}


///Ejercicio 12
int charIntercalado(char F[], int validosF, char G[], int validosG, char H[], int cantidadH)
{
    int iF = 0;
    int iG = 0;
    int iH = 0;

    while((iF < validosF) && (iG < validosG) && (iH < cantidadH))
    {
        if(F[iF] < G[iG])
        {
            H[iH] = F[iF];
            iH++;
            iF++;
        }
        else
        {
            H[iH] = G[iG];
            iH++;
            iG++;
        }
    }
    while(iF < validosF)
    {
        H[iH] = F[iF];
        iH++;
        iF++;
    }
    while(iG < validosF)
    {
        H[iH] = G[iG];
        iH++;
        iG++;
    }
    return iH;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"
///Ejercicio 1
Pila cargarPila(Pila A);
///Ejercicio 2
Pila pasarDeUnaPilaAOtra(Pila origen);
///Ejercicio 3
Pila pasarEnElMismoOrden(Pila origen);
///Ejercicio 4
int encontrarMenor(Pila* A);
///Ejercicio 5
Pila ordenarSeleccion(Pila desordenada);
///Ejercicio 6
Pila insertarEnOrden(Pila ordenada, int insertar);
///Ejercicio 7
Pila ordenarInsercion(Pila desordenada);
///Ejercicio 8
int sumaTopeYAnterior(Pila A);
///Ejercicio 9
int sumarPila(Pila A);
int contarPila(Pila A);
float dividirPila(int suma, int cantidad);
float calcularPromedio(Pila A);
///Ejercicio 10
int transformarPilaEnNro(Pila A);
int main()
{
    ///Ejercicio 1
    Pila P1;
    inicpila(&P1);
    P1 = cargarPila(P1);
    printf("Pila P1:\n");
    mostrar(&P1);

    ///Ejercicio 2
    Pila P2;
    inicpila(&P2);
    P2 = pasarDeUnaPilaAOtra(P1);
    printf("Pila P2:\n");
    mostrar(&P2);

    ///Ejercicio 3
    Pila P3;
    inicpila(&P3);
    P3 = pasarEnElMismoOrden(P1);
    printf("Pila P3:\n");
    mostrar(&P3);

    ///Ejercicio 4
    int menor = encontrarMenor(&P1);
    printf("Menor encontrado en Pila P1: %d\n", menor);
    printf("Pila P1 con el menor extraído:\n");
    mostrar(&P1);

    ///Ejercicio 5
    Pila ordenada;
    inicpila(&ordenada);
    ordenada = ordenarSeleccion(P1);
    printf("Pila ordenada por selección:\n");
    mostrar(&ordenada);

    ///Ejercicio 6
    Pila POrdenada;
    inicpila(&POrdenada);
    POrdenada = cargarPila(P1);
    printf("Pila POrdenada:\n");
    mostrar(&POrdenada);

    int numInsertar = 7;
    POrdenada = insertarEnOrden(POrdenada, numInsertar);
    printf("Pila POrdenada después de la inserción:\n");
    mostrar(&POrdenada);

    ///Ejercicio 7
    Pila P7;
    inicpila(&P7);
    P7 = cargarPila(P7);
    Pila POrdenada7;
    inicpila(&POrdenada7);
    POrdenada7 = ordenarInsercion(P7);
    printf("Pila POrdernada7 luego de inserción:\n");
    mostrar(&POrdenada7);

    ///Ejercicio 8
    Pila P8;
    inicpila(&P8);
    P8 = cargarPila(P8);
    int resulrado8 = sumaTopeYAnterior(P8);
    printf("\nEl resultado de la suma del tope y el anterior de la Pila P8 es: %d\n", resulrado8);
    mostrar(&P8);

    ///Ejercicio 9
    float promedio;
    promedio = calcularPromedio(P8);
    printf("El promedio de la pila P8 es: %.2f\n", promedio);


    ///Ejercicio 10
    Pila P10;
    inicpila(&P10);
    printf("Advertencia: Solo se pueden ingresar nros de un solo dígito\n");
    P10 = cargarPila(P10);
    int rdo = transformarPilaEnNro(P10);
    printf("\nLos dígitos de la pila corresponden al número decimal: %d\n", rdo);
    mostrar(&P10);
    return 0;
}


///Ejercicio 1
Pila cargarPila(Pila A)
{
    char opcion = 's';
    while(opcion == 's' || opcion == 'S')
    {
        leer(&A);

        printf("¿Desea cargar más elementos? (s/n): ");
        fflush(stdin);
        scanf(" %c", &opcion);
    }
    return A;
}

///Ejercicio 2
Pila pasarDeUnaPilaAOtra(Pila origen)
{
    Pila destino;
    inicpila(&destino);
    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }
    return destino;
}


///Ejercicio 3
Pila pasarEnElMismoOrden(Pila origen)
{
    Pila destino;
    inicpila(&destino);
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    while(!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }
    return destino;
}


///Ejercicio 4
int encontrarMenor(Pila* A)
{
    int menor;
    Pila aux;
    inicpila(&aux);

    if (!pilavacia(A))
        menor = desapilar(A);
    while (!pilavacia(A))
    {
        if (tope(A) < menor)
        {
            apilar(&aux, menor);
            menor = desapilar(A);
        }
        else
        {
            apilar(&aux, desapilar(A));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(A, desapilar(&aux));
    }
    return menor;
}


///Ejercicio 5
Pila ordenarSeleccion(Pila desordenada)
{
    Pila ordenada;
    inicpila(&ordenada);
    int Menor;
    while(!pilavacia(&desordenada))
    {
        Menor = encontrarMenor(&desordenada);
        apilar(&ordenada, Menor);
    }
    return ordenada;
}


///Ejercicio 6
Pila insertarEnOrden(Pila ordenada, int insertar)
{
   Pila aux;
   inicpila(&aux);
   while(!pilavacia(&ordenada) && insertar > tope(&ordenada))
   {
       apilar(&aux, desapilar(&ordenada));
   }

   apilar(&ordenada, insertar);
   while(!pilavacia(&aux))
   {
       apilar(&ordenada, desapilar(&aux));
   }
   return ordenada;
}

///Ejercicio 7
Pila ordenarInsercion(Pila desordenada)
{
    Pila ordenada;
    inicpila(&ordenada);
    int datoInsertar;
    while(!pilavacia(&desordenada))
    {
        datoInsertar = desapilar(&desordenada);
        ordenada = insertarEnOrden(ordenada, datoInsertar);
    }
    return ordenada;
}

///Ejercicio 8
int sumaTopeYAnterior(Pila A)
{
    Pila aux;
    inicpila(&aux);
    int suma = 0;
    int contador = 0;
     while ((!pilavacia(&A)) && (contador<2))
    {
        suma = suma + tope(&A);
        apilar(&aux, desapilar(&A));
        contador++;
    }
    return suma;
}


///Ejercicio 9
int sumarPila(Pila A)
{
    int rta = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&aux))
    {
        rta = rta + tope(&A);
        apilar(&aux, desapilar(&A));
    }
    return rta;
}

int contarPila(Pila A)
{
    int cantidad = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&A))
    {
        apilar(&aux, desapilar(&A));
        cantidad++;
    }
    return cantidad;
}

float dividirPila(int suma, int cantidad)
{
    float result = (float)suma / (float)cantidad;
    return result;
}

float calcularPromedio(Pila A)
{
    int suma = sumarPila(A);
    int cantidad = contarPila(A);
    float promedio = dividirPila(suma, cantidad);
    return promedio;
}


///Ejercicio 10
int transformarPilaEnNro(Pila A)
{
    int numero;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&A))
    {
        numero = (numero * 10) + tope(&A);
        apilar(&aux, desapilar(&A));
    }
    return numero;
}

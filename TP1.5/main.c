#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Ejercicio 1
void calcularTotal(float precioUnitario, int cantidad, float* total);
///Ejercicio 2
void aplicarDescuento(float* precio, float porcentaje);
///Ejercicio 3
void calcularPromedio(Pila p, float* promedio);
///Ejercicio 4
float cargarVenta(int* cantidad, float* precio);
///Ejercicio 5
void intercambiarValores(int* a, int* b, int* c, int* d, int* e);
int main()
{
    ///Ejercicio 1
    float precioUnitario, total;
    int cantidad;

    printf("Ingrese el precio unitario: ");
    scanf("%f", &precioUnitario);

    printf("Ingrese la cantidad de productos: ");
    scanf("%d", &cantidad);

    calcularTotal(precioUnitario, cantidad, &total);

    printf("Total: %.2f\n", total);


    ///Ejercicio 2
    float porcentaje, precio;

    printf("Ingrese el precio: ");
    scanf("%f", &precio);

    printf("Ingrese el descuento a aplicar: ");
    scanf("%f", &porcentaje);

    aplicarDescuento(&precio, porcentaje);

    printf("Precio con descuento: %.2f\n", precio);

    ///Ejercicio 3
    float promedio;
    Pila ventas;
    inicpila(&ventas);
    apilar(&ventas, 10);
    apilar(&ventas, 20);
    apilar(&ventas, 30);
    apilar(&ventas, 40);
    apilar(&ventas, 50);

    calcularPromedio(ventas, &promedio);

    printf("Promedio de ventas: %.2f\n", promedio);

    ///Ejercicio 4
    float totalVenta;
    totalVenta = cargarVenta(&cantidad, &precio);
    printf("Cantidad: %d\n", cantidad);
    printf("Precio: %.2f\n", precio);
    printf("Total: %.2f\n", totalVenta);


    ///Ejercicio 5
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    printf("Antes: a = %d b= %d c = %d d = %d e = %d\n", a, b, c, d, e);

    intercambiarValores(&a, &b, &c, &d, &e);

    printf("Después: a = %d b= %d c = %d d = %d e = %d\n", a, b, c, d, e);
    return 0;
}


///Ejercicio 1
void calcularTotal(float precioUnitario, int cantidad, float* total)
{
    *total = precioUnitario * cantidad;
}


///Ejercicio 2
void aplicarDescuento(float* precio, float porcentaje)
{
    *precio = *precio - (*precio * porcentaje / 100);
}


///Ejercicio 3
void calcularPromedio(Pila p, float* promedio)
{
    int suma = 0;
    int cantidad = 0;

    while(!pilavacia(&p))
    {
        suma+= tope(&p);
        desapilar(&p);
        cantidad++;
    }

    *promedio = (float)suma / cantidad;
}


///Ejercicio 4
float cargarVenta(int* cantidad, float* precio)
{
    float total;

    printf("Ingrese la cantidad vendida: ");
    scanf("%d", cantidad);

    printf("Imgrese el precio unitario: ");
    scanf("%f", precio);

    calcularTotal(*precio, *cantidad, &total);

    return total;
}


///Ejercicio 5
void intercambiarValores(int* a, int* b, int* c, int* d, int* e)
{
    int aux;

    aux = *a;

    *a = *b;
    *b = *c;
    *c = *d;
    *d = *e;
    *e = aux;
}


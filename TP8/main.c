#include <stdio.h>
#include <stdlib.h>
///Ejercicio 1
int factorial(int num);
///Ejercicio 2
int potencia(int base, int exponente);
///Ejercicio 3
void recorrerArreglo(int arr[], int validos, int i);
///Ejercicio 4
void invertirArreglo(int arr[], int validos, int i);
///Ejercicio 5
int esCapicua(int arr[], int inicio, int fin);
///Ejercicio 6
int sumarArreglo(int arr[], int validos, int i);
///Ejercicio 7
int buscarMenor(int arr[], int validos, int i);
int main()
{
    int num;
    int base, exp;
    int opcion;

    do
    {
        printf("1. Factorial\n");
        printf("2.Potencia\n");
        printf("3.Recorrer arreglo\n");
        printf("4.Invertir arreglo\n");
        printf("5.Capicua\n");
        printf("6.Sumar arreglo\n");
        printf("7.Buscar elemento menor\n");
        printf("0.Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("Elija un número para calcular su factorial: ");
            scanf("%d", &num);
            printf("Resultado: %d\n", factorial(num));
            break;


        case 2:
            printf("Ingrese la base y el exponente: ");
            scanf("%d %d", &base, &exp);
            if(exp < 0)
            {
                printf("No se permiten números negativos\n");
            }
            else
            {
                printf("%d elevado a %d = %d\n", base, exp, potencia(base, exp));
            }
            break;

        case 3:
        {
            int arr[] = {10, 20, 30, 40, 50};
            int validos = 5;
            printf("Elementos del arreglo: ");
            recorrerArreglo(arr, validos, 0);
            printf("\n");
            break;
        }

        case 4:
        {
            int arr[] = {10, 20, 30, 40, 50};
            int validos = 5;
            printf("Arreglo invertido: ");
            invertirArreglo(arr, validos, 0);
            printf("\n");
            break;
        }

        case 5:
        {
            int arr[] = {2,0,0,2};
            int validos = 4;
            if(esCapicua(arr, 0, validos -1))
            {
                printf("El arreglo es capicua\n");
            }
            else
            {
                printf("El arreglo no es capicua\n");
            }
            break;
        }

        case 6:
        {
            int arr[] = {10,20,30,40,50};
            int validos = 5;
            printf("La suma del arreglo es: %d\n", sumarArreglo(arr, validos, 0));
            break;
        }

        case 7:
        {
            int arr[] = {30, 10,5,20,40};
            int validos = 5;
            printf("El elemento menor es: %d\n", buscarMenor(arr, validos, 0));
            break;
        }
        case 0:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida\n");
            break;
        }
    }
    while(opcion != 0);
    return 0;
}

///Ejercicio 1
int factorial(int num)
{
    if(num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

///Ejercicio 2
int potencia(int base, int exponente)
{
    if(exponente == 0)
    {
        return 1;
    }
    else
    {
        return base * potencia(base, exponente - 1);
    }
}


///Ejercicio 3
void recorrerArreglo(int arr[], int validos, int i)
{
    if(i < validos)
    {
        printf("%d ", arr[i]);
        recorrerArreglo(arr, validos, i + 1);
    }
}


///Ejercicio 4
void invertirArreglo(int arr[], int validos, int i)
{
    if(i < validos)
    {
        invertirArreglo(arr, validos, i + 1);
        printf("%d ", arr[i]);
    }
}

///Ejercicio 5
int esCapicua(int arr[], int inicio, int fin)
{
    if(inicio >= fin)
    {
        return 1;
    }

    if(arr[inicio] != arr[fin])
    {
        return 0;
    }
    return esCapicua(arr, inicio + 1, fin - 1);
}

///Ejercicio 6
int sumarArreglo(int arr[], int validos, int i)
{
    if(i == validos)
    {
        return 0;
    }

    else
    {
        return arr[i] + sumarArreglo(arr, validos, i + 1);
    }
}


///Ejercicio 7
int buscarMenor(int arr[], int validos, int i)
{
    if(i == validos - 1)
    {
        return arr[i];
    }

    else
    {
        int menorResto = buscarMenor(arr, validos, i + 1);
        if(arr[i] < menorResto)
        {
            return arr[i];
        }
        else
        {
            return menorResto;
        }
    }
}

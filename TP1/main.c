#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///Ejercicio 1
int numRandom();
///Ejercicio 2
void mostrarMayorMenor(int a, int b, int c);
///Ejercicio 3
int sumarN(int n);
///Ejercicio 4
void mostrarTabla(int N);
///Ejercicio 5
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);
///Ejercicio 6
void cambiarANegativo(int* num);
///Ejercicio 7
void cargarPorReferencia(int* a, int* b);
int main()
{
    ///Ejercicio 1
    srand(time(NULL));
    printf("Valor random: %d\n", numRandom());


    ///Ejercicio 2
    mostrarMayorMenor(18, 5, 23);

    ///Ejercicio 3;
    int N;

    printf("Ingrese el número para sumar: ");
    scanf("%d", &N);


    printf("Resultado: %d\n", sumarN(N));


    ///Ejercicio 4
    int numTabla;
    printf("Ingrese el numero para mostrar su tabla: ");
    scanf("%d", &numTabla);

    mostrarTabla(numTabla);


    ///Ejercicio 5
    float num1, num2;
    int opcion;

    printf("Ingrese dos números: ");
    scanf("%f %f", &num1, &num2);
    printf("\n===CALCULAODRA===\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("Elija una opción: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        printf("Resultado: %.2f\n", suma(num1, num2));
        break;

    case 2:
        printf("Resultado: %.2f\n", resta(num1, num2));
        break;

    case 3:
        printf("Resultado: %.2f\n", multiplicacion(num1, num2));
        break;

    case 4:
        printf("Resultado: %.2f\n", division(num1, num2));
        break;

    default:
        printf("Opción inválida\n");
        break;
    }

    ///Ejercicio 6
    int valor;
    printf("Ingrese el número a cambiarle el signo: ");
    scanf("%d", &valor);

    printf("Antes: %d\n", valor);

    cambiarANegativo(&valor);

    printf("Después: %d\n", valor);

    ///Ejercicio 7
    int numero1, numero2;

    cargarPorReferencia(&numero1, &numero2);

    printf("\nNum 1: %d\n", numero1);
    printf("\nNum 2: %d\n", numero2);
    return 0;
}


///Ejercicio 1
int numRandom()
{
    return rand() % 101;
}


///Ejercicio 2
void mostrarMayorMenor(int a, int b, int c)
{
    int menor = a;
    int mayor = a;

    if(b > mayor)
    {
        mayor = b;
    }

    if(c > mayor)
    {
        mayor = c;
    }

    if(b < menor)
    {
        menor = b;
    }

    if(c < menor)
    {
        menor = b;
    }

    printf("Mayor: %d\n", mayor);
    printf("Menor: %d\n", menor);
}


///Ejercicio 3
int sumarN(int n)
{
    int suma = 0;
    for(int i = 0; i <= n; i++)
    {
        suma+= i;
    }
    return suma;
}


///Ejercicio 4
void mostrarTabla(int N)
{
    for(int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", N, i, N * i);
    }
}

///Ejercicio 5
float suma(float a, float b)
{
    return a + b;
}


float resta(float a, float b)
{
    return a - b;
}

float multiplicacion(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    if(b != 0)
    {
        return a / b;
    }
        printf("Error: No se puede dividir por 0\n");
        return 0;
}


///Ejercicio 6
void cambiarANegativo(int* num)
{
    *num = -(*num);
}


///Ejercicio 7
void cargarPorReferencia(int* a, int* b)
{
    printf("Ingrese el primer número: ");
    scanf("%d", a);

    printf("Ingrese el segundo número: ");
    scanf("%d", b);
}


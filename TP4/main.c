#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///Ejercicio 1
void cargarMatriz(int dimF, int dimC, int M[dimF][dimC]);
///Ejercicio 2
void mostrarMatriz(int dimF, int dimC, int M[dimF][dimC]);
///Ejercicio 3
void cargarMatrizRandom(int dimF, int dimC, int M[dimF][dimC]);
///Ejercicio 4
int sumarMatriz(int dimF, int dimC, int M[dimF][dimC]);
///Ejercicio 5
float promediarMatriz(int dimF, int dimC, int M[dimF][dimC]);
///Ejercicio 6
int buscarEnMatriz(int dimF, int dimC, int M[dimF][dimC], int num);
///Ejercicio 7
int cargarArregloPalabras(int dimF, int dimC, char mPal[dimF][dimC]);
///Ejercicio 8
void mostrarArregloPalabras(int validosPalabras, int dimC, char mPal[][dimC]);
///Ejercicio 9
int buscarPalabra(int validosF, int dimC, char mPal[][dimC], char palabraBuscada[]);
///Ejercicio 10
int buscarPalabraEnArregloOrdenado(int validosF, int dimC, char mPal[][dimC], char palabraBuscada[]);
///Ejercicio 11
int buscarEnMenor(int validosF, int dimC, char mPal[][dimC], int pos);
void intercambioPalabra(int dimC, char mPal[][dimC], int posMen, int indF);
void ordenamientoSeleccionPalabra(int validosF, int dimC, char mPal[][dimC]);
///Ejercicio 12
int determinante2x2(int M[2][2]);
///Ejercicio 13
int matrizInversa(int M[2][2]);
int main()
{
    ///Ejercicio 1
    int M[3][3];
    cargarMatriz(3, 3, M);

    ///Ejercicio 2
    mostrarMatriz(3, 3, M);

    ///Ejercicio 3
    int mRand[5][5];
    srand(time(NULL));
    cargarMatrizRandom(5, 5, mRand);
    mostrarMatriz(5, 5, mRand);

    ///Ejercicio 4
    int rta = sumarMatriz(3, 3, M);
    printf("El resultado de la suma es: %d\n", rta);

    ///Ejercicio 5
    float promedio = promediarMatriz(3, 3, M);
    printf("El promedio de todos los elementos de la matriz es: %.2f\n", promedio);

    ///Ejercicio 6
    int num;
    printf("Ingrese el número a buscar: ");
    scanf("%d", &num);
    int flag = buscarEnMatriz(3, 3, M, num);
    if(flag == 1)
    {
         printf("El nro %d fue encontrado en la matriz\n", num);
    }
    else
    {
        printf("El nro %d no se encuentra en la matriz\n", num);
    }

    ///Ejercicio 7
    char mPal[20][30];
    getchar();
    int validosPalabras = cargarArregloPalabras(20, 30, mPal);

    ///Ejercicio 8
    mostrarArregloPalabras(validosPalabras, 30, mPal);

    ///Ejercicio 9
    char palabraBuscada[30];
    printf("Ingrese la palabra a buscar: ");
    scanf("%29s", palabraBuscada);

    int pos = buscarPalabra(validosPalabras, 30, mPal, palabraBuscada);
    if(pos == -1)
    {
        printf("La palabra %s no existe en el arreglo\n", palabraBuscada);
    }
    else
    {
        printf("La palabra %s está en la posición %d\n", palabraBuscada, pos);
    }

    ///Ejercicio 11
    ordenamientoSeleccionPalabra(validosPalabras, 30, mPal);
    printf("Arreglo de palabras ordenado:\n");
    mostrarArregloPalabras(validosPalabras, 30, mPal);

    ///Ejercicio 10
    char palabrasBuscadaBis[30];
    printf("Ingrese la palabra a buscar: ");
    scanf("%29s", palabrasBuscadaBis);
    int posBis = buscarPalabraEnArregloOrdenado(validosPalabras, 30, mPal, palabrasBuscadaBis);
    if(posBis == -1)
    {
        printf("La palabra %s no se encuentra en el arreglo\n", palabrasBuscadaBis);
    }
    else
    {
        printf("La palabra %s está en la posición %d\n", palabrasBuscadaBis, posBis);
    }

    ///Ejercicio 12
    int M12[2][2] = {
        {10, 4},
        {6,8}
    };
    printf("La determinante de la matriz es: %d\n", determinante2x2(M12));

    ///Ejercicio 13
    int M13[2][2] = {
        {10, 4},
        {6,8}
    };
    if(matrizInversa(M13))
    {
        printf("La matriz tiene inversa\n");
    }
    else
    {
        printf("La matriz no tiene inversa\n");
    }
    return 0;
}


///Ejercicio 1
void cargarMatriz(int dimF, int dimC, int M[dimF][dimC])
{
    int f = 0;
    int c = 0;
    for(f = 0; f < dimF; f++)
    {
        for(c = 0; c < dimC; c++)
        {
            printf("Ingrese el valor para [%d] [%d]: ", f, c);
            scanf("%d", &M[f][c]);
        }
    }
}


///Ejercicio 2
void mostrarMatriz(int dimF, int dimC, int M[dimF][dimC])
{
    int f, c = 0;
    for(f = 0; f < dimF; f++)
    {
        for(c = 0; c < dimC; c++)
        {
            printf("%3d", M[f][c]);
        }
        printf("\n");
    }
}


///Ejercicio 3
void cargarMatrizRandom(int dimF, int dimC, int M[dimF][dimC])
{
    int f, c;
    for(f = 0; f < dimF; f++)
    {
        for(c = 0; c < dimC; c++)
        {
            M[f][c] = rand() % 101;
        }
    }
}


///Ejercicio 4
int sumarMatriz(int dimF, int dimC, int M[dimF][dimC])
{
    int f, c;
    int suma = 0;
    for(f = 0; f < dimF; f++)
    {
        for(c = 0; c < dimC; c++)
        {
            suma+= M[f][c];
        }
    }
    return suma;
}

///Ejercicio 5
float promediarMatriz(int dimF, int dimC, int M[dimF][dimC])
{
    int f, c;
    int suma = 0;
    float promedio;
    for(f = 0; f < dimF; f++)
    {
        for(c = 0; c < dimC; c++)
        {
            suma+= M[f][c];
        }
    }
    promedio = (float)suma / (dimF * dimC);
    return promedio;
}


///Ejercicio 6
int buscarEnMatriz(int dimF, int dimC, int M[dimF][dimC], int num)
{
    int f, c;
    int flag = 0;
    for(f = 0; f < dimF && flag == 0; f++)
    {
        for(c = 0; c < dimC && flag == 0; c++)
        {
            if(M[f][c] == num)
            {
                flag = 1;
            }
        }
    }
    return 0;
}


///Ejercicio 7
int cargarArregloPalabras(int dimF, int dimC, char mPal[dimF][dimC])
{
    int f = 0;
    char control = 's';
    while((f < dimF) && (control == 's'))
    {
        printf("Ingrese la palabra %d: ", f);
        fgets(mPal[f], dimC, stdin);
        mPal[f][strcspn(mPal[f], "\n")] = '\0';

        printf("¿Desea seguir cargando palabras? (s/n): ");
        fflush(stdin);
        scanf(" %c", &control);
        getchar();
        f++;
    }
    return f;
}


///Ejercicio 8
void mostrarArregloPalabras(int validosPalabras, int dimC, char mPal[][dimC])
{
    int c = 0;
    for(c = 0; c < validosPalabras; c++)
    {
        printf("%s\n", mPal[c]);
    }
}


///Ejercicio 9
int buscarPalabra(int validosF, int dimC, char mPal[][dimC], char palabraBuscada[])
{
    int pos = -1;
    int indFilas = 0;
    while((indFilas < validosF) && (pos == -1))
    {
        if(strcmp(palabraBuscada, mPal[indFilas]) == 0)
        {
            pos = indFilas;
        }
        indFilas++;
    }
    return pos;
}

///Ejercicio 10
int buscarPalabraEnArregloOrdenado(int validosF, int dimC, char mPal[][dimC], char palabraBuscada[])
{
    int pos = -1;
    int indFilas = 0;
    while((indFilas < validosF) && (pos == -1) && (strcmp(palabraBuscada, mPal[indFilas]) <= 0))
    {
        if(strcmp(palabraBuscada, mPal[indFilas]) == 0)
        {
            pos = indFilas;
        }
        indFilas++;
    }
    return pos;
}

///Ejercicio 11
int buscarEnMenor(int validosF, int dimC, char mPal[][dimC], int pos)
{
    int posMenor = pos;
    char palabraMenor[dimC];
    strcpy(palabraMenor, mPal[pos]);
    for(int i = pos + 1; i < validosF; i++)
    {
        if(strcmp(palabraMenor, mPal[i]) > 0)
        {
            strcpy(palabraMenor, mPal[i]);
            posMenor = i;
        }
    }
    return posMenor;
}

void intercambioPalabra(int dimC, char mPal[][dimC], int posMen, int indF)
{
    char aux[dimC];
    strcpy(aux, mPal[posMen]);
    strcpy(mPal[posMen], mPal[indF]);
    strcpy(mPal[indF], aux);
}

void ordenamientoSeleccionPalabra(int validosF, int dimC, char mPal[][dimC])
{
    int indF = 0;
    int posMen;
    for(indF = 0; indF < validosF; indF++)
    {
        posMen = buscarEnMenor(validosF, dimC, mPal, posMen);
        intercambioPalabra(dimC, mPal, posMen, indF);
    }
}


///Ejercicio 12
int determinante2x2(int M[2][2])
{
    return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
}


///Ejercicio 13
int matrizInversa(int M[2][2])
{
    int determinante;
    determinante = (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
    if(determinante != 0)
    {
        return 1;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int codigo; // Código único del producto
    char nombre[50]; // Nombre del producto
    float precio; // Precio unitario
    int stock; // Cantidad en stock
    int activo; // 1 si está activo, 0 si está "eliminado" lógicamente
} stProducto;
///Ejercicio 1
stProducto cargarProducto(char nombreArchivo[]);
int existeCodigo(char nombreArchivo[], int codigo);
void agregarProducto(char nombreArchivo[], stProducto producto);
///Ejercicio 2
void mostrarProducto(stProducto p);
void mostrarProductosActivos(char nombreArchivo[]);
void buscarProductoCodigo(char nombreArchivo[]);
void buscarProductoNombre(char nombreArchivo[]);
void menuVisualizar(char nombreArchivo[]);
///Ejercicio 3
void modificarDatos(stProducto* p);
void modificarProducto(char nombreArchivo[]);
///Ejercicio 4
void cambiarEstadoProducto(char nombreArchivo[], int nuevoEstado);
void bajaProducto(char nombreArchivo[]);
void altaProducto(char nombreArchivo[]);
///Menú
void menu();
int main()
{
    char archivoInventario[] = "inventario.dat";
    stProducto nuevo;
    int opcion;
    do
    {
        menu();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            nuevo = cargarProducto(archivoInventario);
            agregarProducto(archivoInventario, nuevo);
            break;

        case 2:
            menuVisualizar(archivoInventario);
            break;

        case 3:
            printf("\n1. Buscar por codigo\n2. Buscar por nombre\nOpcion: ");
            scanf("%d", &opcion);

            if(opcion == 1)
                buscarProductoCodigo(archivoInventario);
            else
                buscarProductoNombre(archivoInventario);
            break;

        case 4:
            modificarProducto(archivoInventario);
            break;

        case 5:
            bajaProducto(archivoInventario);
            break;
        case 6:
            altaProducto(archivoInventario);
            break;

        case 7:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida\n");

        }
        system("pause");
        system("cls");
    }
    while(opcion != 7);
    return 0;
}


///Ejercicio 1
int existeCodigo(char nombreArchivo[], int codigo)
{
    FILE *pArch = fopen(nombreArchivo, "rb");
    stProducto aux;

    if(pArch == NULL)
    {
        // Si el archivo no existe, el código no existe.
        return 0;
    }

    while(fread(&aux, sizeof(stProducto), 1, pArch) > 0)
    {
        if(aux.codigo == codigo)
        {
            fclose(pArch);
            return 1;
        }
    }

    fclose(pArch);
    return 0;
}


stProducto cargarProducto(char nombreArchivo[])
{
    stProducto p;

    int existe;
    do
    {
        printf("Código: ");
        scanf("%d", &p.codigo);

        existe = existeCodigo(nombreArchivo, p.codigo);
        if(existe)
        {
            printf("Ya existe ese código, ingrese otro\n");
        }
    }
    while(existe);

    while(getchar() != '\n');

    printf("Nombre: ");
    fgets(p.nombre, 50, stdin);
    p.nombre[strcspn(p.nombre, "\n")] = '\0';

    printf("Precio: ");
    scanf("%f", &p.precio);

    printf("Stock: ");
    scanf("%d", &p.stock);

    p.activo = 1;

    return p;
}

void agregarProducto(char nombreArchivo[], stProducto producto)
{
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi != NULL)
    {
        fwrite(&producto, sizeof(stProducto), 1, archi);
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
}


///Ejercicio 2
void mostrarProducto(stProducto p)
{
    printf("\n-------------------\n");
    printf("\nCodigo: %d\n", p.codigo);
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: %.2f\n", p.precio);
    printf("Stock: %d\n", p.stock);
}

void mostrarProductosActivos(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stProducto p;
    if(archi == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }

    while(fread(&p, sizeof(stProducto), 1, archi) > 0)
    {
        if(p.activo == 1)
        {
            mostrarProducto(p);
        }
    }
    fclose(archi);
}
void buscarProductoCodigo(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stProducto p;
    int codigo;
    int flag = 0;

    if(archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    printf("Ingrese el código: ");
    scanf("%d", &codigo);

    while(fread(&p, sizeof(stProducto), 1, archi) > 0)
    {
        if(p.codigo == codigo && p.activo == 1)
        {
            mostrarProducto(p);
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("No existen productos con ese código\n");
    }
    fclose(archi);
}


void buscarProductoNombre(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "rb");
    stProducto p;
    char nombreProducto[50];
    int flag = 0;
    if(archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    while(getchar() != '\n');
    printf("Ingrese el nombre del producto: ");
    fgets(nombreProducto, 50, stdin);
    nombreProducto[strcspn(nombreProducto, "\n")] = '\0';

    while(fread(&p, sizeof(stProducto), 1, archi) > 0)
    {
        if(strcmp(p.nombre, nombreProducto) == 0 && p.activo == 1)
        {
            mostrarProducto(p);
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("No existen productos con ese nombre\n");
    }
    fclose(archi);
}
void menuVisualizar(char nombreArchivo[])
{
    int opcion;

    do
    {
        printf("\n1. Mostrar todos\n");
        printf("2. Buscar por codigo\n");
        printf("3. Buscar por nombre\n");
        printf("4. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            mostrarProductosActivos(nombreArchivo);
            break;

        case 2:
            buscarProductoCodigo(nombreArchivo);
            break;

        case 3:
            buscarProductoNombre(nombreArchivo);
            break;

        case 4:
            break;

        default:
            printf("Opcion invalida\n");
        }

    } while(opcion != 4);
}
///Menú
void menu()
{
    printf("\n===INVENTARIO===\n");
    printf("1. Agregar producto\n");
    printf("2. Mostrar producto\n");
    printf("3. Modificar producto\n");
    printf("4. Eliminar producto(lógicamente)\n");
    printf("5. Dar de baja un producto\n");
    printf("6. Dar de alta un producto\n");
    printf("7. Salir\n");
    printf("\n------------------------------\n");
    printf("Elija una opción: ");

}


///Ejercicio 3
void modificarDatos(stProducto* p)
{
    while(getchar() != '\n');
    printf("Nuevo nombre: ");
    fgets(p->nombre, 50, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Nuevo precio: ");
    scanf("%f", &p->precio);

    printf("Nuevo stock: ");
    scanf("%d", &p->stock);
}

void modificarProducto(char nombreArchivo[])
{
    FILE* archi = fopen(nombreArchivo, "r+b");
    stProducto p;
    int codigo;
    int flag = 0;

    if(archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    printf("Ingrese el código: ");
    scanf("%d", &codigo);

    while(fread(&p, sizeof(stProducto), 1, archi) > 0 && !flag)
    {
        if(p.codigo == codigo && p.activo == 1)
        {
            modificarDatos(&p);
            fseek(archi, -((long)sizeof(stProducto)), SEEK_CUR);
            fwrite(&p, sizeof(stProducto), 1, archi);
            flag = 1;
        }
    }
    if(flag)
    {
        printf("Producto modificado correctamente\n");
    }
    else
    {
        printf("Producto no encontrado\n");
    }
    fclose(archi);
}

///Ejercicio 4
void cambiarEstadoProducto(char nombreArchivo[], int nuevoEstado)
{
    FILE* archi = fopen(nombreArchivo, "r+b");
    stProducto p;
    int codigo;
    int flag = 0;

    if(archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    printf("Ingrese el código: ");
    scanf("%d", &codigo);

    while(fread(&p, sizeof(stProducto), 1, archi) > 0)
    {
        if(p.codigo == codigo)
        {
            p.activo = nuevoEstado;
            fseek(archi, sizeof(stProducto), SEEK_CUR);
            fwrite(&p, sizeof(stProducto), 1, archi);
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("Operación realizada correctamente\n");
    }
    else
    {
        printf("Producto no encontrado\n");
    }
}

void bajaProducto(char nombreArchivo[])
{
    cambiarEstadoProducto(nombreArchivo, 0);
}

void altaProducto(char nombreArchivo[])
{
    cambiarEstadoProducto(nombreArchivo, 1);
}

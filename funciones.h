#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
// puesto en el template
typedef struct TProducto
{
    char * Descripcion;
    char * Categoria;
    int Precio;
    int Stock;

}TProducto;

typedef struct Tnodo
{
    TProducto dato;
    struct Tnodo *siguiente;
}Tnodo;

typedef struct Tnodo* Lista;

TProducto CrearProducto(const char * descripcion,const char * categoria,int precio,int stock);
TProducto * ProveedorDeLacteosPanaderiaLiquidos();
void MostrarProductosDeArreglo(TProducto * producto, int cantidad, const char * nombreProveedor);
void MostrarProducto(TProducto prod);

void MostrarLista(Tnodo *lista, const char *tituloLista);
void MostrarCantidadSinStock(int cantidad);

 
 /*
 ESTE CODIGO GENERA PRODUCTOS PARA LOS ARREGLOS, Y MUESTRA POR PANTALLA LAS SALIDAS PARA COMPORBAR EL FUNCIONAMIENTO DE LOS PUNTOS
 NO MODIFICAR!
*/
  void MostrarLista(Tnodo *lista, const char *tituloLista)
{
    printf("\n LISTA: %s\n", tituloLista);
    int i = 0;
    while (lista!=NULL)
    {
        i++;
        printf("\nNODO - %d ",i);
        MostrarProducto(lista->dato);
        lista = lista->siguiente;
    }
    printf("\nCantidad de elementos: %d\n", i);
}
void MostrarProducto(TProducto prod)
{
    printf("Descripcion: %s Categoria: %s precio: %d Stock: %d", prod.Descripcion, prod.Categoria, prod.Precio, prod.Stock);
}

void MostrarCantidadSinStock(int cantidad)
{
    printf("\nCantidad de productos sin stock: %d\n", cantidad);
}



TProducto CrearProducto(const char * descripcion, const char * categoria,int precio,int stock)
{
    TProducto Producto;
    Producto.Descripcion = (char *)malloc(strlen(descripcion));
    strcpy(Producto.Descripcion, descripcion);

    Producto.Categoria =(char *)malloc(strlen(categoria));
    strcpy(Producto.Categoria, categoria);

    Producto.Precio = precio;
    Producto.Stock = stock;  
    return Producto;
}

TProducto * ProveedorDeLacteosPanaderiaLiquidos()
{
    TProducto * Productos = (TProducto *) malloc(sizeof(TProducto) * 17);
    //Lacteos
    Productos[0] = CrearProducto("Queso Crema Clasico Casancrem 480gr", "Lacteos",931,200);
    Productos[1] = CrearProducto("Queso Untable Finlandia 180 Gr", "Lacteos",501,100);
    Productos[2] = CrearProducto("Leche Entera Clasica La Serenisima Sachet 1 L", "Lacteos",265,10);
    Productos[3] = CrearProducto("Yogur Cremix Conicet Vainilla Pack X4 Yogurisimo 120gr", "Lacteos",745,200);
    Productos[4] = CrearProducto("Manteca Casanto 200g", "Lacteos",401,200);
    Productos[5] = CrearProducto("Yogur Bebible Descremado Frutilla La Serenisima Clasico 900gr", "Lacteos",375,200);
    //Panaderia
    Productos[6] = CrearProducto("Rapiditas Bimbo Clasicas X 275grs", "Panaderia",442,0);
    Productos[7] = CrearProducto("Palmeritas De Manteca 200 Gr", "Panaderia",741,0);
    Productos[8] = CrearProducto("Cookies Con Chip De Chocolate", "Panaderia",681,2200);
    Productos[9] = CrearProducto("Bizcochuelo Humedo", "Panaderia",1039,160);
    Productos[10] = CrearProducto("Alfajorcitos De Maizena 240 Gr", "Panaderia",584,98);
    //Liquidos 
    Productos[11] = CrearProducto("Agua Mineral Cuisine & Co Sin Gas 2l", "Liquidos",208,57);
    Productos[12] = CrearProducto("Soda Sifon 1", "Liquidos",321,25);
    Productos[13] = CrearProducto("Aceite De Oliva Extra Virgen Cuisine & Co 500", "Liquidos",1166,7);
    Productos[14] = CrearProducto("Gaseosa Cola Pepsi Regular 2.25l", "Liquidos",499,4);
    Productos[15] = CrearProducto("Gaseosa Coca-cola Sabor Original 500 Ml", "Liquidos",234,26); 
    Productos[16] = CrearProducto("Gaseosa Sprite Lima-limon 2,25 Lt", "Liquidos",628,33);


    return Productos;
}

void MostrarProductosDeArreglo(TProducto * producto, int cantidad, const char * nombreProveedor)
{
    printf("%s \n\r" ,nombreProveedor);
    printf("------------------------- \n\r");
    for (int i = 0; i < cantidad; i++)
    {
        MostrarProducto(producto[i]);
        printf("\n");
    }
    printf("------------------------- \n\r");
}

# TP5 - Auto-Evaluativo de Listas Enlazadas

## Enunciado
1. Utilice el puntero listaDeProductos para crear una lista y *copie* todos los elementos del array ProductosDeProveedor1 a la lista. La inserción del nodo tiene que ser al inicio de la lista.
2. Construya una funcion que *copie* en la lista productosFiltradosPorPrecio todos los productos de la lista listaDeProductos cuyo precio sea menor al precio ingresado por consola
3. Construya una funcion que devuelva la *cantidad* de productos de la lista listaDeProductos cuyo stock sea igual a 0 y guardelo en la variable cantidadSinStock.
4. Construya una funcion que *quite* todos los productos de listaProductos cuyo stock sea mayor a un valor ingresado por consola y los *mueva* a una nueva lista productosFiltradoPorStock. 
5. Libere todas las listas utilizadas.

## Instrucciones para correr el script de auto corrección
El script de autocorrección posee un script que permite comprobar mediante la salida de su programa si el mismo funciona correctamente o no, comparando la salida de su programa con las salidas que debería generar un programa que funciona correctamente. El script devuelve "identico" si la salida de su programa es identico a la salida correcta, y diferente si la misma es diferente a la salida correcta.
### UNIX (MacOs o Linux)
En la consola de VS Code escriba:
1. chmod +x Autograding.sh
2. ./Autograding.sh
### Windows
Abra powershell con permiso de administrador y escriba:
1. Set-ExecutionPolicy RemoteSigned
En la consola powershell de VS Code escriba:
2. ./Autograding.ps1
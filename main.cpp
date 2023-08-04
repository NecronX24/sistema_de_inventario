#include <iostream>
#include <fstream>
#include <string>
#include "agregar_producto.h"
#include "buscar_por_codigo.h"
#include "buscar_producto.h"
#include "compra_de_producto.h"
#include "editar_producto.h"
#include "mostrar_producto.h"
#include "reporte_de_ventas.h"
#include "borrar_producto.h"
#include "copia_base_de_datos.h"
using namespace std;

void inicio();

void menu_eleccion(int temp);

void volver_a_inicio();

int main(){
    infile.open("Datos_Inventario.csv");
     if (!infile){
        cout<<"No se encontro tu vaina"<< endl;
        return 0;
    }
    csv_to_struct();
    infile.close();
    inicio();
}

void inicio(){
    int eleccion;
    cout<< "Programa de Sistema de Inventario, elige tu opcion"<<endl;
    cout<< "1. Agregar un producto nuevo"<<endl;
    cout<< "2. Editar un producto" <<endl;
    cout<< "3. Mostrar un producto" <<endl;
    cout<< "4. Buscar un producto" <<endl;
    cout<< "5. Buscar por otras opciones " <<endl;
    cout<< "6. Realizar una compra" <<endl;
    cout<< "7. Reporte de ventas (100 mejores)" <<endl;
    cout<< "8. Borrar un producto por id"<<endl;
    cout<< "9. Copiar la base de datos"<<endl;
    cout<< ">> "; 
    cin>> eleccion;
    menu_eleccion(eleccion);
}

void volver_a_inicio(){
    cout<< "Quiere volver al menu para seleccionar otra opcion? (1 para si y 0 para no)"<<endl;
    cout<<">> ";
    int eleccion;
    cin>> eleccion;
    string nombre;
    switch(eleccion){
        case 0:
            nombre = "Datos_Inventario.csv";
            struct_to_csv(nombre);
            break;
        case 1:
            inicio();
            break;
        default:
            cout<<"Elige bien";
            volver_a_inicio();
            break;
    }
}

void menu_eleccion(int temp){
    switch (temp)
    {
    case 1:
        if (productos>=lenght){
            extender_datos_inv();
        }
        agregar(productos);
        productos++;
        break;

    case 2:
        editarFun(productos);
        break;

    case 3:
        mostrarFun();
        break;

    case 4:
        buscarCodFun();
        break;

    case 5:{
        menu_buscar(productos);
        quicksort(datos_inv,0,productos-1,6);
        break;}

    case 6:
        compraFun(productos);
        break;

    case 7:
        menu_reporte(productos);
        quicksort(datos_inv,0,productos-1,6);
        break;

    case 8:
        borrar_producto();
        break;

    case 9:
        copiar_base();
        break;    

    default:
        cout<<"Eleccion erronea"<<endl;
        inicio();
        break;
    }
    volver_a_inicio();
}

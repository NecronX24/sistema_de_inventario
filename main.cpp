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
using namespace std;

int productos = 0;
string titulo;

ifstream infile;
ofstream outfile;

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
    cout<< ">> "; 
    cin>> eleccion;
    menu_eleccion(eleccion);
}

void volver_a_inicio(){
    cout<< "Quiere volver al menu para seleccionar otra opcion? (1 para si y 0 para no)"<<endl;
    cout<<">> ";
    int eleccion;
    cin>> eleccion;
    switch(eleccion){
        case 0:
            struct_to_csv();
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

    default:
        cout<<"Eleccion erronea"<<endl;
        inicio();
        break;
    }
    volver_a_inicio();
}

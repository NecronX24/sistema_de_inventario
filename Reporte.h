#pragma once
#include <iostream>
#include "struct.h"
#include "Buscar.h"
#include <iomanip>
using namespace std;

void reporte_dia(int productos){
    quicksort(datos_inv, 0, productos-1, 3);
    cout<<left<<setw(6)<<"ID"<<left<<setw(8)<<"Ventas"<<left<<setw(40)<<"Nombre del Producto"<<endl;
    int temp = productos-1;
    for (int i = 0; i < 100; i++){
        cout<<left<<setw(6)<<datos_inv[temp-i].id<<left<<setw(8)<<datos_inv[temp-i].ventas_dia<<left<<setw(40)<<datos_inv[temp-i].nombre<<endl;
    }
}

void reporte_mes(int productos){
    quicksort(datos_inv, 0, productos-1, 4);
    cout<<left<<setw(6)<<"ID"<<left<<setw(8)<<"Ventas"<<left<<setw(40)<<"Nombre del Producto"<<endl;
    int temp = productos-1;
    for (int i = 0; i < 100; i++){
        cout<<left<<setw(6)<<datos_inv[temp-i].id<<left<<setw(8)<<datos_inv[temp-i].ventas_mes<<left<<setw(40)<<datos_inv[temp-i].nombre<<endl;
    }
}

void reporte_ano(int productos){
    quicksort(datos_inv, 0, productos-1, 5);
    cout<<left<<setw(6)<<"ID"<<left<<setw(8)<<"Ventas"<<left<<setw(40)<<"Nombre del Producto"<<endl;
    int temp = productos-1;
    for (int i = 0; i < 100; i++){
        cout<<left<<setw(6)<<datos_inv[temp-i].id<<left<<setw(8)<<datos_inv[temp-i].ventas_ano<<left<<setw(40)<<datos_inv[temp-i].nombre<<endl;
    }
}

void menu_reporte(int productos){
    cout<< "Elige que ventas quieres ver: "<<endl;
    cout<< "1. 100 mejores ventas del dia"<<endl;
    cout<< "2. 100 mejores ventas del mes"<<endl;
    cout<< "3. 100 mejores ventas del ano"<<endl;
    cout<< ">> ";
    int eleccion;
    cin>>eleccion;
    switch(eleccion){
    case 1:
        reporte_dia(productos);
        break;
    case 2:
        reporte_mes(productos);
        break;
    case 3:
        reporte_ano(productos);
        break;
    default:
        cout<<"Elige bien"<<endl;
        menu_reporte(productos);
        break;
    }

}


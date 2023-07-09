#pragma once
#include <iostream>
#include "struct.h"

void agregar_ventas(int x){
    cout<<"Quieres anadir ventas del producto?(1 para si, 0 para no): ";
    int eleccion;
    cin>> eleccion;
    switch(eleccion){
        case 0:
            break;
        case 1:
            cout<<"Indica las ventas del dia: ";
            cin>> datos_inv[x].ventas_dia;
            cout<<"Indica las ventas del mes: ";
            cin>> datos_inv[x].ventas_mes;
            cout<<"Indica las ventas del ano: ";
            cin>> datos_inv[x].ventas_ano;
            break;
        default:
            cout<<"Elige bien"<<endl;
            agregar_ventas(x);
            break;
    }
}

void agregar(int x){
    datos_inv[x].id = to_string(x+1);
    cout<<"Indica el nombre del producto a agregar: ";
    cin>> datos_inv[x].nombre;
    cout<<"Indica el precio del producto: ";
    cin>> datos_inv[x].precio;
    cout<<"Indica la cantidad en existencia del producto: ";
    cin>> datos_inv[x].existencia;
    cout<<"Indica el maximo que puedes tener del producto";
    cin>> datos_inv[x].max;
    cout<<"Indica el minimo que puedes tener del producto";
    cin>> datos_inv[x].min;  
    agregar_ventas(x);
}
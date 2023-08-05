#pragma once
#include <iostream>
#include "struct.h"

void agregar_ventas(int x){
    cout<<"Quieres anadir ventas del producto?(1 para si, 0 para no): ";
    int eleccion;
    cin>> eleccion;
    switch(eleccion){
        case 0:
            datos_inv[x].ventas_dia = "0";
            datos_inv[x].ventas_mes = "0";
            datos_inv[x].ventas_ano = "0";
            break;
        case 1:
            cout<<"Indica las ventas del dia"<<endl;
            cout<<">> ";
            cin>> datos_inv[x].ventas_dia;
            cout<<"Indica las ventas del mes"<<endl;
            cout<<">> ";
            cin>> datos_inv[x].ventas_mes;
            cout<<"Indica las ventas del ano"<<endl;
            cout<<">> ";
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
    cout<<"Indica el nombre del producto a agregar"<<endl;
    cout<<">> ";
    cin>> datos_inv[x].nombre;
    cout<<"Indica el precio del producto"<<endl;
    cout<<">> ";
    cin>> datos_inv[x].precio;
    cout<<"Indica la cantidad en existencia del producto"<<endl;
    cout<<">> ";
    cin>> datos_inv[x].existencia;
    int error;
    do{
        error = 0;
        cout<<"Indica el maximo que puedes tener del producto"<<endl;
        cout<<">> ";
        cin>> datos_inv[x].max;
        cout<<"Indica el minimo que puedes tener del producto"<<endl;
        cout<<">> ";
        cin>> datos_inv[x].min;
        int max = stoi(datos_inv[x].max);
        int min = stoi(datos_inv[x].min);
        if (min>=max){
            cout<<"El minimo del producto no puede ser mayor o igual al maximo del producto"<<endl;
            error=1;
        }
    }while (error == 1);
    agregar_ventas(x);
}
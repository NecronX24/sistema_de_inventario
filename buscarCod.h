#pragma once
#include <iostream>
#include "struct.h"
#include <iomanip>

void buscarCodFun(){
    int idprod;
    cout<<"Ingrese ID del producto a mostrar"<<endl;
    cout<<">> ";
    cin>>idprod;

    idprod=idprod-1;

    cout<<left<<setw(19)<<"Nombre:"<<datos_inv[idprod].nombre<<endl;

    cout<<left<<setw(19)<<"Precio:"<<datos_inv[idprod].precio<<endl;

    cout<<left<<setw(19)<<"Existencia:"<<datos_inv[idprod].existencia<<endl;

    cout<<left<<setw(19)<<"Maximo:"<<datos_inv[idprod].max<<endl;

    cout<<left<<setw(19)<<"Minimo:"<<datos_inv[idprod].min<<endl;

    cout<<left<<setw(19)<<"Ventas del dia:"<<datos_inv[idprod].ventas_dia<<endl;

    cout<<left<<setw(19)<<"Ventas del mes:"<<datos_inv[idprod].ventas_mes<<endl;

    cout<<left<<setw(19)<<"Ventas del ano:"<<datos_inv[idprod].ventas_ano<<endl;
}
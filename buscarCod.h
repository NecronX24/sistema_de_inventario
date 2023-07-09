#pragma once
#include <iostream>
#include "struct.h"

void buscarCodFun(){
    int idprod;
    cout<<"ingrese ID del producto a mostrar:";
    cin>>idprod;

    idprod=idprod-1;

    cout<<" 1-Nombre:------"<<datos_inv[idprod].nombre<<endl;

    cout<<"2-Precio:------"<<datos_inv[idprod].precio<<endl;

    cout<<"3-Existencia:------"<<datos_inv[idprod].existencia<<endl;

    cout<<"4-Maximo:------"<<datos_inv[idprod].max<<endl;

    cout<<"5-Minimo:------"<<datos_inv[idprod].min<<endl;

    cout<<"6-Ventas al dia:------"<<datos_inv[idprod].ventas_dia<<endl;

    cout<<"7-Ventas al mes:------"<<datos_inv[idprod].ventas_mes<<endl;

    cout<<"8-Ventas al ano:------"<<datos_inv[idprod].ventas_ano<<endl;
}
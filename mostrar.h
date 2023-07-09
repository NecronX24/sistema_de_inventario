#pragma once
#include <iostream>
#include "struct.h"

void mostrarFun(){
    int idprod;
    cout<<"ingrese ID del producto a buscar:";
    cin>>idprod;

    idprod=idprod-1;

    cout<<"El producto que buscas es "<<datos_inv[idprod].nombre<<" y tiene un costo de "<<datos_inv[idprod].precio<<endl;

}

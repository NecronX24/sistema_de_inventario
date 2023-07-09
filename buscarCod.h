#pragma once
#include <iostream>
#include "struct.h"

void buscarCodFun(){
    int idprod;
    cout<<"ingrese ID del producto a buscar:";
    cin>>idprod;

    idprod=idprod-1;

    cout<<" 1-Nombre:------"<<datos_inv[idprod].nombre<<endl;

    cout<<"2-Precio:------"<<datos_inv[idprod].precio<<endl;

}
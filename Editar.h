#pragma once
#include <iostream>
#include "struct.h"

void editarFun(int idprod){

    cout<<"ingrese ID del producto a editar:";
    cin>>idprod;

    idprod=idprod-1;

    cout<<"1-Nombre:------"<<datos_inv[idprod].nombre<<endl;

    cout<<"2-Precio:------"<<datos_inv[idprod].precio<<endl;

    cout<<"3-Existencia:------"<<datos_inv[idprod].existencia<<endl;

    cout<<"4-Maximo:------"<<datos_inv[idprod].max<<endl;

    cout<<"5-Minimo:------"<<datos_inv[idprod].min<<endl;

    cout<<"6-Ventas al dia:------"<<datos_inv[idprod].ventas_dia<<endl;

    cout<<"7-Ventas al mes:------"<<datos_inv[idprod].ventas_mes<<endl;

    cout<<"8-Ventas al ano:------"<<datos_inv[idprod].ventas_ano<<endl;

    cout<<"Inserta el numero del dato que quieres editar:"<<endl;
    int edEleccion;
    cin>>edEleccion;
    
    switch(edEleccion){
    case 1:
      cout<<"Inserta el nuevo nombre:"<<endl;
      cin.ignore();
      getline(cin, datos_inv[idprod].nombre);
      break;

    case 2:
    cout<<"Inserta el nuevo precio:"<<endl;
    cin>>datos_inv[idprod].precio;
        break;

    case 3:
    cout<<"Inserta la nueva existencia:"<<endl;
    cin>>datos_inv[idprod].existencia;
        break;

    case 4:
    cout<<"Inserta el nuevo maximo de producto:"<<endl;
    cin>>datos_inv[idprod].max;
        break;

    case 5:{
        cout<<"Inserta el nuevo minimo de producto:"<<endl;
    cin>>datos_inv[idprod].min;
        break;}

    case 6:
    cout<<"Inserta las nuevas ventas por dia:"<<endl;
    cin>>datos_inv[idprod].ventas_dia;
        break;

    case 7:
    cout<<"Inserta las nuevas ventas por mes:"<<endl;
    cin>>datos_inv[idprod].ventas_mes;
        break;
    
    case 8:
    cout<<"Inserta las nuevas ventas por anio:"<<endl;
    cin>>datos_inv[idprod].ventas_ano;
      break;

    default:
        break;
    }
}
#pragma once
#include <iostream>
#include "struct.h"

void editarFun(int idprod){

    cout<<"Ingrese ID del producto a editar";
    cout<<">>";
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

    cout<<"Inserta el numero del dato que quieres editar"<<endl;
    cout<<">> ";
    int edEleccion;
    cin>>edEleccion;
    
    switch(edEleccion){
    case 1:
      cout<<"Inserta el nuevo nombre"<<endl;
      cout<<">> ";
      cin.ignore();
      getline(cin, datos_inv[idprod].nombre);
      break;

    case 2:
    cout<<"Inserta el nuevo precio"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].precio;
        break;

    case 3:
    cout<<"Inserta la nueva existencia"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].existencia;
        break;

    case 4:
    cout<<"Inserta el nuevo maximo de producto"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].max;
        break;

    case 5:{
        cout<<"Inserta el nuevo minimo de producto"<<endl;
        cout<<">> ";
    cin>>datos_inv[idprod].min;
        break;}

    case 6:
    cout<<"Inserta las nuevas ventas por dia"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].ventas_dia;
        break;

    case 7:
    cout<<"Inserta las nuevas ventas por mes"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].ventas_mes;
        break;
    
    case 8:
    cout<<"Inserta las nuevas ventas por anio"<<endl;
    cout<<">> ";
    cin>>datos_inv[idprod].ventas_ano;
      break;

    default:
        break;
    }
}
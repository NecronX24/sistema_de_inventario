#pragma once
#include <iostream>
#include <string>
#include "struct.h"

void compraFun(int idcomp){
    cout<<"Inserta el id del producto que quieres comprar:"<<endl;
    cin>>idcomp;
    idcomp=idcomp-1;

    int cantcomp;
    cout<<"Que cantidad deseas comprar de este producto?"<<endl;
    cin>>cantcomp;
//Suma de la compra

    int compAno;
    compAno=stoi(datos_inv[idcomp].ventas_ano);
    compAno=compAno+cantcomp;

    int compDia;
    compDia=stoi(datos_inv[idcomp].ventas_dia);
    compDia=compDia+cantcomp;

    int compMes;
    compMes=stoi(datos_inv[idcomp].ventas_mes);
    compMes=compMes+cantcomp;

//Resta de existencia

    int compEx;
    compEx=stoi(datos_inv[idcomp].existencia);
    compEx=compEx-cantcomp;

//Pasar ints a string

datos_inv[idcomp].ventas_ano=to_string(compAno);
datos_inv[idcomp].ventas_dia=to_string(compDia);
datos_inv[idcomp].ventas_mes=to_string(compMes);
datos_inv[idcomp].existencia=to_string(compEx);

cout<<"Compra hecha exitosamente!";
  
}
#pragma once
#include "struct.h"

void devolver_producto(){
    int id_dev;
    cout<<"Inserta el ID del producto que quieres devolver"<<endl;
    cout<<">> ";
    cin>>id_dev;
    id_dev=id_dev-1;

    int cant_dev;
    cout<<"Que cantidad deseas devolver de este producto?"<<endl;
    cout<<">> ";
    cin>>cant_dev;
    int dev_ex=stoi(datos_inv[id_dev].existencia);
    
    //Resta de la compra

    int compAno;
    compAno=stoi(datos_inv[id_dev].ventas_ano);
    compAno=compAno-cant_dev;

    int compDia;
    compDia=stoi(datos_inv[id_dev].ventas_dia);
    compDia=compDia-cant_dev;

    int compMes;
    compMes=stoi(datos_inv[id_dev].ventas_mes);
    compMes=compMes-cant_dev;

    //Suma de existencia

    dev_ex += cant_dev;

    //Pasar ints a string

    datos_inv[id_dev].ventas_ano=to_string(compAno);
    datos_inv[id_dev].ventas_dia=to_string(compDia);
    datos_inv[id_dev].ventas_mes=to_string(compMes);
    datos_inv[id_dev].existencia=to_string(dev_ex);

    cout<<"Devolucion realizada exitosamente"<<endl;
}
  
#pragma once
#include "struct.h"

void borrar_producto(){
    try{
        cout<<"Indique el id del producto que desea eliminar\n>> ";
        int id_borrar;
        cin>> id_borrar;
        id_borrar--;
        if (id_borrar>=productos){
            bool flag;
            throw flag;
        }
        int eleccion = 0;
        do{
            cout<<"Desea borrar "<< datos_inv[id_borrar].nombre<<" de id: " << datos_inv[id_borrar].id << "? (1 para si, 0 para no)\n>> ";
            cin>> eleccion;
            if (eleccion== 1){
                for (id_borrar; id_borrar<productos; id_borrar++){
                    datos_inv[id_borrar].nombre = datos_inv[id_borrar+1].nombre;
                    datos_inv[id_borrar].precio = datos_inv[id_borrar+1].precio;
                    datos_inv[id_borrar].id = to_string(id_borrar+1);
                    datos_inv[id_borrar].existencia = datos_inv[id_borrar+1].existencia;
                    datos_inv[id_borrar].max = datos_inv[id_borrar+1].max;
                    datos_inv[id_borrar].min = datos_inv[id_borrar+1].min;
                    datos_inv[id_borrar].ventas_dia = datos_inv[id_borrar+1].ventas_dia;
                    datos_inv[id_borrar].ventas_mes = datos_inv[id_borrar+1].ventas_mes;
                    datos_inv[id_borrar].ventas_ano = datos_inv[id_borrar+1].ventas_ano;
                }
                productos--;
            } else if (eleccion!=0 && eleccion !=1){
                cout<<"Elige bien"<<endl;
            }
        } while (eleccion!=0 && eleccion !=1);
    }catch(bool flag){
        cout<< "El id indicado es mayor a la cantidad de productos que se tiene"<<endl;
        borrar_producto();
    }
}
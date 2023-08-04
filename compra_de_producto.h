#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "struct.h"
#include <ctime>

int eleccion;

using namespace std;

ifstream onfactura;
ofstream outfactura;

void compraFun(int idcomp){;
    cout<<"Inserta el ID del producto que quieres comprar"<<endl;
    cout<<">> ";
    cin>>idcomp;
    idcomp=idcomp-1;

    int cantcomp;
    cout<<"Que cantidad deseas comprar de este producto?"<<endl;
    cout<<">> ";
    cin>>cantcomp;

    int compEx=0; 
    compEx=stoi(datos_inv[idcomp].existencia);

    eleccion=1;
    if(compEx-cantcomp<10){
        cout<<"ADVERTENCIA -- ESCAZES DE PRODUCTO"<<endl;
        cout<<"Desea continuar? (1 para si y 0 para no)"<<endl;
        cout<<">> ";
        cin>>eleccion;}

    if(eleccion == 0){
        compraFun(idcomp); 
    }else{

    
    if (cantcomp<=compEx){
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
        compEx=compEx-cantcomp;

        //Pasar ints a string

        datos_inv[idcomp].ventas_ano=to_string(compAno);
        datos_inv[idcomp].ventas_dia=to_string(compDia);
        datos_inv[idcomp].ventas_mes=to_string(compMes);
        datos_inv[idcomp].existencia=to_string(compEx);

        cout<<"Compra hecha exitosamente!"<<endl;

        //FACTURA
        int facturaeleccion;
        cout<<"Desea generar una factura? (1 para si y 0 para no)"<<endl;
        cout<<">> ";
        cin>>facturaeleccion;

        if(facturaeleccion == 1){

    // Obtener la marca de tiempo actual
    time_t now = time(0);
    
    // Convertir la marca de tiempo en una estructura tm con la fecha y hora actual
    tm* timeinfo = localtime(&now);
    
    // Crear un buffer para almacenar la fecha formateada
    char buffer[80];
    
    // Formatear la fecha y hora actual utilizando la función strftime()
    strftime(buffer, 80, "%d/%m/%Y", timeinfo);

    //Impresión de la factura
    float total;
    total=stoi(datos_inv[idcomp].precio);
        total=total*cantcomp;

    outfactura.open("factura.txt");
    outfactura<<"               FACTURA"<<endl;
    outfactura<<"              "<<buffer<<endl;
    outfactura<<"--------------------------------------------"<<endl<<endl;
    outfactura<<"Cantidad: "<<cantcomp<<endl;
    outfactura<<datos_inv[idcomp].nombre<<"    --------    "<<datos_inv[idcomp].precio<<endl<<endl;
    outfactura<<"--------------------------------------------"<<endl<<endl;
    outfactura<<"Total: "<<total<<"$"<<endl<<endl;
    outfactura<<"--------------------------------------------";

outfactura.close();

        cout<<"Factura realizada correctamente!"<<endl;
        }
        

    }
    else{
        cout<<"No se puede realizar la compra porque no hay suficientes existencias"<<endl;
    }
  
}
}
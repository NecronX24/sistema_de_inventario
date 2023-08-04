#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "struct.h"
#include <ctime>

int eleccion, promoproducto, numerocaja;
float descuentoporcentaje, totaldescuento;
string nombreempleado, nombrecliente;

int numCompras;
bool esClienteFrecuente = false;
double descuento = 0.0;

using namespace std;

ifstream onfactura;
ofstream outfactura;

void compraFun(int idcomp){
    eleccion=1;
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

    if(cantcomp>=compEx){
        cout<<"No se puede procesar tu compra(Falta de existencia)"<<endl<<"Existencia: "<<compEx<<endl;
    }else if(compEx-cantcomp<10){
        cout<<"ADVERTENCIA -- ESCAZES DE PRODUCTO"<<endl;
        cout<<"Desea continuar? (1 para si y 0 para no)"<<endl;
        cout<<">> ";
        cin>>eleccion;
    }

    if(eleccion == 0){
        compraFun(idcomp); 
    }else{
        if (cantcomp<=compEx){
        //Suma de la compra

        //PROMO AÑADIDA
        int promoeleccion;
        cout<<"Deseas insertar una promo a tu producto? (1 para si y 0 para no)"<<endl;
        cin>>promoeleccion;

        if(promoeleccion == 1){
            cout<<"Inserta el porcentaje de promo a tu producto (entre 0 y 100)"<<endl;
            cin>>promoproducto;
        }
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
            
            cout<<"Ingrese la caja que realizo la compra:"<<endl;
            cout<<">> "<<endl;
            cin>>numerocaja;

            cout<<"Ingresa el nombre del empleado que realizó la factura:"<<endl;
            cout<<">> "<<endl;
            cin>>nombreempleado;

             cout<<"Ingresa el nombre del cliente que realizó la compra:"<<endl;
            cout<<">> "<<endl;
            cin>>nombrecliente;

            cout<<"Indica la cantidad de compras del cliente:"<<endl;
            cout<<">> "<<endl;
            cin>>numCompras;

    // Obtener la marca de tiempo actual
    time_t now = time(0);
    // Convertir la marca de tiempo en una estructura tm con la fecha y hora actual
    tm* timeinfo = localtime(&now);
    
    // Crear un buffer para almacenar la fecha formateada
    char buffer[80];
    
    // Formatear la fecha y hora actual utilizando la función strftime()
    strftime(buffer, 80, "%d/%m/%Y", timeinfo);

    //Impresión de la factura
    int total;
    total=stoi(datos_inv[idcomp].precio);
        total=total*cantcomp;

    outfactura.open("factura.txt");
    outfactura<<"               FACTURA"<<endl;
    outfactura<<"              "<<buffer<<endl;
    outfactura<<"Cliente: "<<nombrecliente<<endl;
    outfactura<<"--------------------------------------------"<<endl<<endl;
    outfactura<<"Cantidad: "<<cantcomp<<endl;
      if(promoeleccion == 1){
        int promoprecio;
        promoprecio=total*(promoproducto/100);
    outfactura<<datos_inv[idcomp].nombre<<"    --------    "<<promoprecio<<endl<<endl;
      }else{
    outfactura<<datos_inv[idcomp].nombre<<"    --------    "<<datos_inv[idcomp].precio<<endl<<endl;
      }
    outfactura<<"--------------------------------------------"<<endl<<endl;

    //descuentos
    if (numCompras >= 100) {
        esClienteFrecuente = true;
    }

      if (esClienteFrecuente) {
        descuento = 0.15; // Descuento del 15% para clientes frecuentes

        // Calcular incremento adicional por cada 300 compras
        int numComprasAdicionales = numCompras - 100;
        int incrementoPorCada300Compras = numComprasAdicionales / 300 * 2;
        descuento += incrementoPorCada300Compras * 0.01; // Aumento del 2% por cada 300 compras adicionales
        descuentoporcentaje=descuento*100;
        totaldescuento=total*descuentoporcentaje;

        outfactura<<"Total: "<<totaldescuento<<"$"<<endl;
    }
    outfactura<<"Total: "<<total<<"$"<<endl;
    outfactura<<"Realizado por caja "<<numerocaja<<endl;
    outfactura<<"Realizada por empleado: "<<nombreempleado<<endl<<endl;
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

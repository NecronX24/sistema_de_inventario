#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;
int productos = 0;
string titulo;

struct inventario{
string nombre, precio, id, existencia,max, min, ventas_dia, ventas_mes, ventas_ano,precio_promo;
}; 

int lenght = 1001;
inventario *datos_inv=new inventario [1001];

void extender_datos_inv(){
    inventario *temp= new inventario[lenght];
            for (int i=0; i<productos; i++){
                temp[i]=datos_inv[i];
            }
            delete[] datos_inv;
            lenght = lenght * 2;
            datos_inv = new inventario [lenght];
            for (int i=0; i<productos; i++){
                datos_inv[i]=temp[i];
            }
            delete[] temp;
}


void csv_to_struct(){
    string dato;
    int get_title=0;
    int i = 0;
    while(infile){
        if (productos>=lenght){
            extender_datos_inv();
        }
        if(get_title==0){
            getline(infile,dato,'\n');
            titulo=dato;
            get_title=1;
        }
        i++;
        switch(i){
            case 1:
                getline(infile,dato,';');
                datos_inv[productos].id=dato;
                break;
            case 2:
                getline(infile,dato,';');
                datos_inv[productos].nombre=dato;
                break;
            case 3:
                getline(infile,dato,';');
                datos_inv[productos].precio=dato;
                break;
            case 4:
                getline(infile,dato,';');
                datos_inv[productos].existencia=dato;
                break;
            case 5:
                getline(infile,dato,';');
                datos_inv[productos].max=dato;
                break;
            case 6:
                getline(infile,dato,';');
                datos_inv[productos].min=dato;
                break;
            case 7:
                getline(infile,dato,';');
                datos_inv[productos].ventas_dia=dato;
                break;
            case 8:
                getline(infile,dato,';');
                datos_inv[productos].ventas_mes=dato;
                break;
            case 9:
                getline(infile,dato,';');
                datos_inv[productos].ventas_ano=dato;
                datos_inv[productos].precio_promo="0";
                i=0;
                productos++;
                break;
        }
    }
}

void struct_to_csv(string direccion){
    int i = 0;
    outfile.open(direccion);
    outfile<<titulo<<endl;
    while(outfile){ 
        if(i<productos){
            outfile<<datos_inv[i].id<<";"<<datos_inv[i].nombre<<";"<<datos_inv[i].precio<<";"<<datos_inv[i].existencia<<";"<<datos_inv[i].max<<";"<<datos_inv[i].min<<";"<<datos_inv[i].ventas_dia<<";"<<datos_inv[i].ventas_mes<<";"<<datos_inv[i].ventas_ano<<";"<<datos_inv[i].precio_promo<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}
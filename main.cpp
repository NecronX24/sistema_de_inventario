#include <iostream>
#include <fstream>
#include <string>
#include "Buscar.h"
#include "Agregar.h"
using namespace std;

int eleccion;
int productos = 0;
string titulo;

ifstream infile;
ofstream outfile;

void csv_to_struct();

void inicio();

void menu_eleccion(int temp);

void struct_to_csv();

int main(){
    infile.open("Datos_Inventario.csv");
     if (!infile){
        cout<<"No se encontro tu vaina"<< endl;
        return 0;
    }
    csv_to_struct();
    infile.close();
    inicio();
}

void inicio(){
    cout<< "Programa de Sistema de Inventario, elige tu opcion"<<endl;
    cout<< "1. Agregar un producto nuevo"<<endl;
    cout<< "2. Editar un producto" <<endl;
    cout<< "3. Mostrar un producto" <<endl;
    cout<< "4. Buscar un producto" <<endl;
    cout<< "5. Buscar por otras opciones " <<endl;
    cout<< "6. Realizar una compra" <<endl;
    cout<< "7. Reporte de ventas (100 mejores)" <<endl;
    cout<< ": "; 
    cin>> eleccion;
    menu_eleccion(eleccion);
}

void menu_eleccion(int temp){
    switch (temp)
    {
    case 1:
        agregar(productos);
        productos++;
        struct_to_csv();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:{
        quicksort_Existencia(datos_inv,0,productos-1);
        cout<<datos_inv[0].existencia<<";"<<datos_inv[1].existencia<<";"<<datos_inv[2].existencia;
        break;}

    case 6:
        break;

    case 7:
        break;

    default:
        cout<<"Eleccion erronea"<<endl;
        inicio();
        break;
    }
}

void csv_to_struct(){
    string dato;
    int datoint;
    int get_title=0;
    int i = 0;
    while(infile){
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
                getline(infile,dato,'\n');
                datos_inv[productos].ventas_ano=dato;
                i=0;
                productos++;
                break;
        }
    }
}

void struct_to_csv(){
    int i = 0;
    outfile.open("prueba.csv");
    outfile<<titulo<<endl;
    while(outfile){ 
        if(i<productos){
            outfile<<datos_inv[i].id<<";"<<datos_inv[i].nombre<<";"<<datos_inv[i].precio<<";"<<datos_inv[i].existencia<<";"<<datos_inv[i].max<<";"<<datos_inv[i].min<<";"<<datos_inv[i].ventas_dia<<";"<<datos_inv[i].ventas_mes<<";"<<datos_inv[i].ventas_ano<<endl;
        }
        else{
            outfile.close();
        }
        i++;
    }
}

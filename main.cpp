#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int eleccion;

ifstream infile;
ofstream outfile;

struct inventario{
string id, nombre, precio, existencia, max, min, ventas_dia, ventas_mes, ventas_ano;
}datos_inv[10000];

void cvs_to_struct();

void inicio();

void menu_eleccion(int temp);

int main(){
    infile.open("Datos_Inventario.csv");
     if (!infile){
        cout<<"No se encontro tu vaina"<< endl;
        return 0;
    }
    cvs_to_struct();
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
        break;
        
    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

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

void cvs_to_struct(){
    string dato;
    int i = 0;
    int j = 0;
    while(infile){
        i++;
        switch(i){
            case 1:
            getline(infile,dato,';');
                datos_inv[j].id=dato;
                break;
            case 2:
            getline(infile,dato,';');
                datos_inv[j].nombre=dato;
                break;
            case 3:
            getline(infile,dato,';');
                datos_inv[j].precio=dato;
                break;
            case 4:
            getline(infile,dato,';');
                datos_inv[j].existencia=dato;
                break;
            case 5:
            getline(infile,dato,';');
                datos_inv[j].max=dato;
                break;
            case 6:
            getline(infile,dato,';');
                datos_inv[j].min=dato;
                break;
            case 7:
            getline(infile,dato,';');
                datos_inv[j].ventas_dia=dato;
                break;
            case 8:
            getline(infile,dato,';');
                datos_inv[j].ventas_mes=dato;
                break;
            case 9:
            getline(infile,dato,'\n');
                datos_inv[j].ventas_ano=dato;
                i=0;
                j++;
                break;
        }
    }
}
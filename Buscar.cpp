#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream infile;
ofstream outfile;

struct inventario{
string id, nombre, precio, existencia, max, min, ventas_dia, ventas_mes, ventas_ano;
}datos_inv[10000];

void cvs_to_struct(){
    string dato;
    int i = 0;
    int j = 0;
    while(infile){
    //while(infile){
        //infile>> dato;
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

int main(){
    infile.open("Datos_Inventario.csv");
     if (!infile){
        cout<<"No se encontro tu vaina"<< endl;
        return 0;
    }
    cvs_to_struct();
    cout<<datos_inv[1001].id<<datos_inv[1].nombre<<datos_inv[1000].ventas_ano;
    infile.close();
}
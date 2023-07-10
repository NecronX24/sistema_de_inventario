#pragma once
#include <iostream>
#include "struct.h"
using namespace std;

//Orden de menor a mayor existencia
int partion_Existencia(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    int num = stoi(arr[j].existencia);
    int pivote_int = stoi(pivote.existencia);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

//Orden de menor a mayor precio
int partion_Precio(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    float num = stof(arr[j].precio);
    float pivote_int = stof(pivote.precio);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

//Orden de menor a mayor venta por dia
int partion_V_Dia(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    int num = stoi(arr[j].ventas_dia);
    int pivote_int = stoi(pivote.ventas_dia);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

//Orden de menor a mayor venta por mes
int partion_V_Mes(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    int num = stoi(arr[j].ventas_mes);
    int pivote_int = stoi(pivote.ventas_mes);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

//Orden de menor a mayor venta por ano
int partion_V_Ano(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    int num = stoi(arr[j].ventas_ano);
    int pivote_int = stoi(pivote.ventas_ano);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

//Orden por ID
int partion_ID(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    int num = stoi(arr[j].id);
    int pivote_int = stoi(pivote.id);
    if(num<=pivote_int){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

void quicksort (inventario arr[], int low, int high, int eleccion){
  if (low<high){
    int pi;
    switch (eleccion){
    case 1:
      pi=partion_Existencia(arr,low,high);
      break;

    case 2:
      pi=partion_Precio(arr,low,high);
      break;

    case 3:
      pi=partion_V_Dia(arr,low,high);
      break;

    case 4:
      pi=partion_V_Mes(arr,low,high);
      break;

    case 5:
      pi=partion_V_Ano(arr,low,high);
      break;

    case 6:
      pi=partion_ID(arr,low,high);
      break;

    default:
      cout<<"Error desconocido";
      break;
    }
    quicksort(arr,low,pi-1, eleccion);
    quicksort(arr,pi+1,high, eleccion);
  }
}

void ventas_dia_comparation(int productos, int i){
  cout<<datos_inv[i].nombre<< " | ";
  i--;
  if (datos_inv[productos-1].ventas_dia == datos_inv[i].ventas_dia) ventas_dia_comparation(productos, i);
}

void menu_buscar(int productos){
  cout<<"Elige lo que quiere buscar:"<<endl;
  cout<<"1. Producto con menor cantidades en existencias"<<endl;
  cout<<"2. Producto con mayor cantidades en existencias"<<endl;
  cout<<"3. El producto con el menor precio y el producto con el mayor precio"<<endl;
  cout<<"4. Las mejores ventas del dia, del mes y del ano"<<endl;
  cout<<">> ";
  int eleccion;
  cin>> eleccion;
  switch(eleccion){
    case 1:
      quicksort(datos_inv, 0, productos-1, 1);
      cout<< "El producto con menor cantidades en existencia es "<<datos_inv[0].nombre<<" con "<< datos_inv[0].existencia<<" productos en existencia"<<endl;
      break;

    case 2:
      quicksort(datos_inv, 0, productos-1, 1);
      cout<< "El producto con mayor cantidades en existencia es "<<datos_inv[productos-1].nombre<<" con "<< datos_inv[productos-1].existencia<<" productos en existencia"<<endl;
      break;
    
    case 3:
      quicksort(datos_inv, 0, productos-1, 2);
      cout<< "El producto con menor precio es "<<datos_inv[0].nombre<<" costando "<< datos_inv[0].precio<<endl;
      cout<< "El producto con mayor precio es "<<datos_inv[productos-1].nombre<<" costando "<< datos_inv[productos-1].precio<<endl;
      break;
    
    case 4:
      quicksort(datos_inv, 0, productos-1, 3);
      cout<< "El producto con mayor ventas del dia es "<<datos_inv[productos-1].nombre<<" vendiendo "<<datos_inv[productos-1].ventas_dia<<" en el dia"<<endl;
      if (datos_inv[productos-1].ventas_dia == datos_inv[productos-2].ventas_dia){
        cout<< "Otros productos con las mismas ventas en el dia son: ";
        int i = productos-2;
        ventas_dia_comparation(productos, i);
        cout<<"\n";
      }
      quicksort(datos_inv, 0, productos-1, 4);
      cout<< "El producto con mayor ventas del mes es "<<datos_inv[productos-1].nombre<<" vendiendo "<<datos_inv[productos-1].ventas_mes<<" en el mes"<<endl;
      quicksort(datos_inv, 0, productos-1, 5);
      cout<< "El producto con mayor ventas del ano es "<<datos_inv[productos-1].nombre<<" vendiendo "<<datos_inv[productos-1].ventas_ano<<" en el ano"<<endl;
      break;

    default:
      cout<<"Elige bien"<<endl;
      menu_buscar(productos);
      break;
  }
  }
#pragma once
#include <iostream>
#include "struct.h"
using namespace std;

int partion_Existencia(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    if(arr[j].existencia<=pivote.existencia){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

void quicksort_Existencia (inventario arr[], int low, int high){
  if (low<high){
    int pi=partion_Existencia(arr,low,high);
    quicksort_Existencia(arr,low,pi-1);
    quicksort_Existencia(arr,pi+1,high);
  }
}
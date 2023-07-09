#pragma once
#include <iostream>
#include "struct.h"

int partion_id(inventario arr[], int low, int high){
  inventario pivote = arr[high];
  int i = low-1;
  int j=0;
  for (j=low; j<=high-1; j++){
    if(arr[j].id<=pivote.id){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[j]);
  return (i+1);
}

void quicksort_id(inventario arr[], int low, int high){
  if (low<high){
    int pi=partion_id(arr,low,high);
    quicksort_id(arr,low,pi-1);
    quicksort_id(arr,pi+1,high);
  }
}
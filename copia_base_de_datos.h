#pragma once
#include "struct.h"
#include <time.h>
#include <direct.h>

void copiar_base(){
    string meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    mkdir("copia_de_seguridad");

    time_t t = time(0);
    struct tm * now = localtime( & t );

    char fecha [80];
    strftime (fecha,80,"%d-%m-%Y",now);

    char mes [80];
    strftime (mes,80,"%m",now);
    int i = stoi(mes);
    string carpeta_mes = "copia_de_seguridad/"+meses[i-1];
    const char* carpeta_mes_cstr = carpeta_mes.c_str();
    mkdir(carpeta_mes_cstr);

    string nombre_archivo;
    nombre_archivo = nombre_archivo + "copia_de_seguridad/" + meses[i-1] + "/" + fecha + ".csv";
    
    struct_to_csv(nombre_archivo);
    cout<< "Base de datos copiada con exito"<<endl;
}


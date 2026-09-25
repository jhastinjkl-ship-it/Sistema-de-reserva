/**
 * Proyecto: Sistema de reserva de asientos para cine
 * Estudiantes: 
 * Leonardo Jhastin Herrera Navinta | 20261PRECS01006
 * Benjamin Zevallos Bautista | 202520093
 * Clase: settings.cpp
 */
#include <iostream>
#include "enlace.h"
#include <vector>
using namespace std;

//función para mostrar la matriz por defecto y los valores random de L y O
char** crearSala(int filas, int columnas) //Usando reserva memoria dinamica
{
    char** sala = new char*[filas];
    for (int f=0; f<filas; f++) {
        sala[f]=new char[columnas];
        for (int c=0; c<columnas; c++)
            {
                sala[f][c] = 'L';
            }
    }
    return sala;
}

void matriz(char** sala, int filas, int columnas) //muestra la sala actual
{
    cout << "\n ASIENTOS\n ";
    for (int j=1; j<=columnas; j++) cout << j << " ";
    cout<<endl;
    for (int i=0; i<filas; i++) {
        cout<<"Fila "<<i+1<<" ";
        for (int j=0; j<columnas; j++) cout<<sala[i][j]<<" ";
        cout<<endl;
    }
}

void AsientoSiNo(char** sala, int filas, int columnas) //Mostrará cantidad de asientos Libres y Ocupados
{
    int libres=0, ocupados=0;
    for (int f=0; f<filas; f++)
        for (int c=0; c<columnas; c++)
            if (sala[f][c]=='L') {
                libres++;
                    }
            else {
                ocupados++;
                }

    cout<<"Asientos libres: "<<libres<<endl;
    cout<<"Asientos ocupados: "<<ocupados<<endl;
}
void Reserv_Cancel(char** sala, int filas, int columnas, int operacion  ) //Operaciones de reserva y cancelación de asientos.
{
    int fila, asiento;
    cout<<"Ingrese fila : ";
    cin>>fila;
    cout<<"Ingrese asiento : ";
    cin>>asiento;

    if (fila<1 || fila>filas || asiento<1 || asiento>columnas) {
        cout<<"Posicion invalida."<< endl;
        return;
    }

    int f=fila - 1, a=asiento-1;

    if (operacion==1) { //reservar
        if (sala[f][a]=='L') {
            sala[f][a]='R';
            cout<<"Reserva realizada correctamente."<<endl;
            cout<<"Fila : "<<fila<<endl;
            cout<<"Asiento : "<<asiento<<endl;
        } else {
            cout<<"El asiento ya se encuentra reservado."<<endl;
        }
    } else { //cancelar
        if (sala[f][a]=='R') {
            sala[f][a]='L';
            cout<<"Cancelacion realizada correctamente."<<endl;
            cout<<"Fila : "<<fila<<endl;
            cout<<"Asiento : "<<asiento<<endl;
        } else {
            cout << "El asiento ya se encuentra libre." << endl;
        }
    }
}

void buscarAsiento(char** sala, int filas, int columnas, int personas) //Opción que permita buscar asientos consecutivos para un grupo de personas
{
    for (int f=0; f<filas; f++) {
        int consecutivos=0, inicio=0;
        for (int c=0; c<columnas; c++) {
            if (sala[f][c]=='L') {
                if (consecutivos==0) {
                    inicio=c;
                }
                consecutivos++;
                if (consecutivos == personas) {
                    cout<<"Se encontraron " << personas << " asientos consecutivos." << endl;
                    cout<<"Fila : " << f + 1 << endl;
                    cout<<"Asientos : " << inicio + 1 << " - "<<c + 1<<endl;
                    return;
                }
            } else {
                consecutivos = 0;
            }
        }
    }
    cout<<"No se encontraron "<<personas<<" asientos consecutivos disponibles."<<endl;
}

/**
 * Esta función simula la reserva de asientos en la sala
 * @param sala: puntero a un arreglo de punteros que representa la sala
 * @param filas: cantidad de filas de la sala
 * @param asientos: cantidad de asientos por fila
 * @param cantidad: cantidad de reservas a simular
 * @return: void (Imprime mensajes de las reservas hechas)
 */
void simularReservas(char** sala, int filas, int asientos, int cantidad)
{
    vector<pair<int, int>> asientosLibres;
    
    for (int f = 0; f < filas; f++)
        for (int c = 0; c < asientos; c++)
            if (sala[f][c]=='L') {
                asientosLibres.push_back({f, c});
            }

    if (cantidad > int(asientosLibres.size())) {
        cout<<"No hay suficientes asientos libres para simular "<<cantidad<<" reservas."<<endl;
        return;
    }

    for (int reservasHechas = 1; reservasHechas <= cantidad; reservasHechas++) {
        int index = rand() % asientosLibres.size();
        int fila = asientosLibres[index].first;
        int asiento = asientosLibres[index].second;
        cout<<"Reserva "<< reservasHechas <<": Fila "<<fila + 1 <<"- Asiento "<< asiento + 1<<endl;

        // Quitar la posición elegida para no repetirla
        asientosLibres[index] = asientosLibres.back();
        asientosLibres.pop_back();
    }
}

int mostrarEstadistica(char** sala, int filas, int columnas, int* reservasPorFila) //opcion 5
{
    int totalReservados = 0;

    for (int f=0 ; f<filas; f++) {
        reservasPorFila[f]=0;
        for (int c=0; c<columnas; c++){
            if (sala[f][c]=='R') {
                reservasPorFila[f]++;
            }
        totalReservados+=reservasPorFila[f];
        }
    }

    int total=filas*columnas;
    int libres=total-totalReservados;
    double porcentaje=(totalReservados * 100.0) / total;

    int filaMax=0, filaMin=0;
    for (int f=1; f<filas; f++) {
        if (reservasPorFila[f]>reservasPorFila[filaMax]) filaMax=f;
        if (reservasPorFila[f]<reservasPorFila[filaMin]) filaMin=f;
    }

    cout<<"\n================================\n";
    cout<<" ESTADISTICAS DE SALA\n";
    cout<<"================================\n";
    cout<<"Total de asientos : " <<total<<endl;
    cout<<"Asientos reservados : " <<totalReservados<<endl;
    cout<<"Asientos disponibles : " <<libres<<endl;
    cout<<"Porcentaje de ocupacion : " <<porcentaje<<" %"<<endl;
    cout<<"Reservas por fila:" << endl;
    for (int f=0; f<filas; f++)
        cout<<"Fila "<<f + 1<<" : "<<reservasPorFila[f]<<endl;
    cout<<"Fila con mayor ocupacion: "<<filaMax + 1<<endl;
    cout<<"Fila con menor ocupacion: "<<filaMin + 1<<endl;

    return totalReservados;
}

void Apagar(char** sala, int filas) //Opción 7 (Salir) para apagar el programa
{
    for (int f=0; f<filas;f++) delete[] sala[f]; //Liberamos sala
        delete[] sala; //Liberamos el arreglo de punteros
        cout<<"===Programa Cerrado==="<<endl;
}

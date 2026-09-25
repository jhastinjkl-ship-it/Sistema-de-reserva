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

/**
 * Esta función crea la sala con la cantidad de filas y asientos ingresados por el usuario
 * @param filas: cantidad de filas de la sala
 * @param asientos: cantidad de asientos por fila
 * @return: retorna un puntero a un arreglo de punteros que representa la sala
 */
char** crearSala(int filas, int asientos) //Usando reserva memoria dinamica
{
    char** sala = new char*[filas];

    for (int f = 0; f < filas; f++) {
        sala[f] = new char[asientos];

        for (int c = 0; c < asientos; c++) {
            sala[f][c] = 'L'; // L = Libre, R = Reservado
        }
    }
    
    return sala;
}

/**
 * Esta función muestra la sala actualizada con las filas y asientos ingresados por el usuario
 * @param sala: puntero a un arreglo de punteros que representa la sala
 * @param filas: cantidad de filas de la sala
 * @param asientos: cantidad de asientos por fila
 * @return: void (Imprime la sala en la consola)
 */
void mostrarSala(char** sala, int filas, int asientos)
{
    cout << "\n ASIENTOS\n ";

    // Creamos una cabecera para los asientos
    // 1 2 3 ... n
    for (int cabecera = 1; cabecera <= asientos; cabecera++) {
        cout << cabecera << " ";
    }
    cout<<endl;

    for (int f = 0; f < filas; f++) {
        cout<<"Fila "<< f + 1 <<" ";

        for (int c = 0; c < asientos; c++) {
            cout<<sala[f][c]<<" ";
        }
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

/**
 * Esta función gestiona la reserva y cancelación de asientos en la sala
 * @param sala: puntero a un arreglo de punteros que representa la sala
 * @param filas: cantidad de filas de la sala
 * @param asientos: cantidad de asientos por fila
 * @param operacion: 1 para reservar, 2 para cancelar
 * @return: void (Imprime mensajes de confirmación o error)
 */
void gestionarReserva(char** sala, int filas, int asientos, int operacion  ) //Operaciones de reserva y cancelación de asientos.
{
    int fila, asiento;

    cout<<"Ingrese fila: ";
    cin>>fila;

    cout<<"Ingrese asiento: ";
    cin>>asiento;

    if (fila < 1 || fila > filas || asiento < 1 || asiento > asientos) {
        cout<<"Posicion invalida."<< endl;
        return;
    }

    int f = fila - 1, a = asiento - 1;

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


/**
 * Esta función devuelve la cantidad de asientos consecutivos disponibles en la sala
 * @param sala: puntero a un arreglo de punteros que representa la sala
 * @param filas: cantidad de filas de la sala
 * @param asientos: cantidad de asientos por fila
 * @return: void (imprime el resultado de la búsqueda de asientos)
 */
void buscarAsientosConsecutivos(char** sala, int filas, int asientos)
{
    int personas;
    do {
        cout << "Ingrese cantidad de personas del grupo: ";
        cin >> personas;

        if (personas < 1) {
            cout << "Cantidad invalida. Intente nuevamente." << endl;
        }

        if (personas > asientos) {
            cout << "No hay suficientes asientos en una fila para el grupo. Intente nuevamente." << endl;
        }

    } while (personas < 1 || personas > asientos);

    for (int f = 0; f < filas; f++) {

        int consecutivos=0, inicio=0;

        for (int c = 0; c < asientos; c++) {

            if (sala[f][c]=='L') {

                if (consecutivos == 0) {
                    inicio = c;
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

/**
 * Esta función muestra las estadísticas de la sala
 * @param sala: puntero a un arreglo de punteros que representa la sala
 * @param filas: cantidad de filas de la sala
 * @param columnas: cantidad de asientos por fila
 * @param reservasPorFila: puntero a un arreglo que almacena la cantidad de reservas por fila
 * @return: void (Imprime las estadísticas en la consola)
 */
void mostrarEstadistica(char** sala, int filas, int asientos, int* reservasPorFila)
{
    int totalReservados = 0;

    for (int f = 0 ; f < filas; f++) {
        reservasPorFila[f]=0;

        for (int c = 0; c < asientos; c++){
            if (sala [f][c] =='R') {
                reservasPorFila[f]++;
            }
        }

        totalReservados += reservasPorFila[f];
    }

    int total = filas * asientos;
    int libres = total - totalReservados;
    double porcentaje = (totalReservados * 100.0) / total;

    int filaMax=0, filaMin=0;
    for (int f = 1; f < filas; f++) {
        
        if (reservasPorFila[f] > reservasPorFila[filaMax]) {
            filaMax = f;
        }
        
        if (reservasPorFila[f] < reservasPorFila[filaMin]){
            filaMin = f;
        }
    }

    cout<<"\n================================\n";
    cout<<" ESTADISTICAS DE SALA\n";
    cout<<"================================\n";
    cout<<"Total de asientos : " <<total<<endl;
    cout<<"Asientos reservados : " <<totalReservados<<endl;
    cout<<"Asientos disponibles : " <<libres<<endl;
    cout<<"Porcentaje de ocupacion : " <<porcentaje<<" %"<<endl;
    cout<<"Reservas por fila:" << endl;
    
    for (int f=0; f<filas; f++){
        cout<<"Fila "<<f + 1<<" : "<<reservasPorFila[f]<<endl;
    }

    cout<<"Fila con mayor ocupacion: "<<filaMax + 1<<endl;
    cout<<"Fila con menor ocupacion: "<<filaMin + 1<<endl;
}

void Apagar(char** sala, int filas) //Opción 7 (Salir) para apagar el programa
{
    for (int f=0; f<filas;f++) delete[] sala[f]; //Liberamos sala
        delete[] sala; //Liberamos el arreglo de punteros
        cout<<"===Programa Cerrado==="<<endl;
}

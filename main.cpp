/**
 * Proyecto: Sistema de reserva de asientos para cine
 * Estudiantes: 
 * Leonardo Jhastin Herrera Navinta | 20261PRECS01006
 * Benjamin Zevallos Bautista | 202520093
 * Clase: main.cpp
 */
#include <iostream>
#include "enlace.h"

using namespace std;

int main()
{
    srand(time(0));
    int filas, asientos;

    // Solicitar ingreso de filas y asientos con validación para crear sala
    do {
        cout << "Ingrese numero de filas (5-10): ";
        cin >> filas;
    } while (filas < 5 || filas > 10);

    do {
        cout << "Ingrese numero de asientos por fila (8-15): ";
        cin >> asientos;
    } while (asientos < 8 || asientos > 15);

    // Creara sala con la cantidad de filas y asientos ingresados
    char** sala = crearSala(filas, asientos);

    // Crear un arreglo para almacenar la cantidad de reservas por fila
    int* reservasPorFila = new int[filas];

    int opcion;
    do {
        cout << "\n========================================\n";
        cout << " SISTEMA DE RESERVAS DEL CINE\n";
        cout << "========================================\n";
        cout << "1. Mostrar sala\n";
        cout << "2. Reservar asiento\n";
        cout << "3. Cancelar reserva\n";
        cout << "4. Buscar asientos consecutivos\n";
        cout << "5. Mostrar estadisticas\n";
        cout << "6. Simular reservas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarSala(sala, filas, asientos);
                break;
            case 2:
                gestionarReserva(sala, filas, asientos, 1);
                break;
            case 3:
                gestionarReserva(sala, filas, asientos, 2);
                break;
            case 4: 
                buscarAsientosConsecutivos(sala, filas, asientos);
                break;
            case 5:
                mostrarEstadistica(sala, filas, asientos, reservasPorFila);
                break;
            case 6: {
                int cantidad;
                cout << "Ingrese cantidad de reservas a simular: ";
                cin >> cantidad;
                simularReservas(sala, filas, columnas, cantidad);
                break;
            }
            case 7:
                delete[] reservasPorFila;
                Apagar(sala, filas);
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 7);

    return 0;
}



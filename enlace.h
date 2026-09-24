//
// Created by Jhastin on 9/11/2026.
//

#ifndef UNTITLED1_ENLACE_H
#define UNTITLED1_ENLACE_H

char** crearSala(int filas, int columnas);
void matriz(char** sala, int filas, int columnas);
void AsientoSiNo(char**sala, int filas, int columnas);
void Reserv_Cancel(char** sala, int filas, int columnas, int operacion);
void buscarAsiento(char** sala, int filas, int columnas, int personas);
void simularReservas(char** sala, int filas, int columnas, int cantidad);
int mostrarEstadistica(char** sala, int filas, int columnas, int* reservasPorFila);
void Apagar(char** sala, int filas);

#endif //UNTITLED1_ENLACE_H

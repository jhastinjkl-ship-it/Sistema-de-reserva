/**
 * Proyecto: Sistema de reserva de asientos para cine
 * Estudiantes: 
 * Leonardo Jhastin Herrera Navinta | 20261PRECS01006
 * Benjamin Zevallos Bautista | 202520093
 * Clase: enlace.h
 */
#ifndef UNTITLED1_ENLACE_H
#define UNTITLED1_ENLACE_H

char** crearSala(int filas, int asientos);

void mostrarSala(char** sala, int filas, int asientos);

void gestionarReserva(char** sala, int filas, int asientos, int operacion);

void buscarAsientosConsecutivos(char** sala, int filas, int asientos);

void simularReservas(char** sala, int filas, int asientos);

void mostrarEstadistica(char** sala, int filas, int asientos, int* reservasPorFila);

void apagar(char** sala, int filas);

#endif //UNTITLED1_ENLACE_H

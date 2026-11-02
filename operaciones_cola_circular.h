#ifndef OPERACIONES_COLA_CIRCULAR_H
#define OPERACIONES_COLA_CIRCULAR_H

#include "cola_circular.h"
#include <iostream>

template <typename T>
ColaCircular<T>::ColaCircular() : frente(nullptr), fin(nullptr), cantidad(0) {}

template <typename T>
ColaCircular<T>::~ColaCircular() {
    vaciar();
}

template <typename T>
bool ColaCircular<T>::estaVacia() const {
    return frente == nullptr;
}

template <typename T>
int ColaCircular<T>::obtenerTamanio() const {
    return cantidad;
}

template <typename T>
void ColaCircular<T>::encolar(const T& valor) {
    Nodo* nuevo = new Nodo(valor);
    if (estaVacia()) {
        frente = nuevo;
        fin = nuevo;
        fin->sig = frente;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
        fin->sig = frente;
    }
    cantidad++;
}

template <typename T>
bool ColaCircular<T>::desencolar(T& valorAtendido) {
    if (estaVacia()) return false;

    Nodo* temp = frente;
    valorAtendido = temp->dato;

    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->sig;
        fin->sig = frente;
    }

    delete temp;
    cantidad--;
    return true;
}

template <typename T>
bool ColaCircular<T>::verFrente(T& valor) const {
    if (estaVacia()) return false;
    valor = frente->dato;
    return true;
}

template <typename T>
void ColaCircular<T>::mostrarEstado() const {
    if (estaVacia()) {
        std::cout << "\n[El bufer de impresion esta vacio]\n";
        return;
    }

    Nodo* actual = frente;
    std::cout << "\n--- ESTADO DEL BUFER DE IMPRESION (COLA CIRCULAR) ---\n";
    int i = 1;
    do {
        std::cout << "Posicion " << i++ << " -> [ID: " << actual->dato.id
                  << " | Archivo: " << actual->dato.nombreArchivo
                  << " | Paginas: " << actual->dato.paginas << "]\n";
        actual = actual->sig;
    } while (actual != frente);
    std::cout << "Total de documentos en cola: " << cantidad << "\n================================================\n";
}

template <typename T>
void ColaCircular<T>::vaciar() {
    T temporal;
    while (!estaVacia()) {
        desencolar(temporal);
    }
template <typename T>
T ColaCircular<T>::obtenerEnPosicion(int pos) const {
    if (estaVacia() || pos < 0 || pos >= cantidad) {
        throw std::out_of_range("Posicion fuera de rango");
    }
    Nodo* actual = frente;
    for (int i = 0; i < pos; ++i) {
        actual = actual->sig;
    }
    return actual->dato;
}   
}

#endif

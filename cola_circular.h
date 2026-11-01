#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

#include <string>

struct Documento {
    int id;
    std::string nombreArchivo;
    int paginas;
};

template <typename T>
class ColaCircular {
private:
    struct Nodo {
        T dato;
        Nodo* sig;
        Nodo(const T& valor) : dato(valor), sig(nullptr) {}
    };

    Nodo* frente;
    Nodo* fin;
    int cantidad;

public:
    ColaCircular();
    ~ColaCircular();

    ColaCircular(const ColaCircular&) = delete;
    ColaCircular& operator=(const ColaCircular&) = delete;

    bool estaVacia() const;
    int obtenerTamanio() const;
    void encolar(const T& valor);
    bool desencolar(T& valorAtendido);
    bool verFrente(T& valor) const;
    void mostrarEstado() const;
    void vaciar();
};

#endif

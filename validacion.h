#ifndef VALIDACION_H
#define VALIDACION_H

#include <iostream>
#include <string>
#include <sstream>

inline bool leerEntero(const std::string& mensaje, int& valor) {
    std::string linea;
    std::cout << mensaje;
    if (!std::getline(std::cin, linea)) return false;

    std::stringstream flujo(linea);
    char sobrante;
    if (!(flujo >> valor) || (flujo >> sobrante)) {
        std::cout << "Error: Entrada invalida. Ingrese un numero entero.\n";
        return false;
    }
    return true;
}

inline void mostrarMenu() {
    std::cout << "\n===== SISTEMA DE IMPRESION EN RED (SPOOLER) =====\n";
    std::cout << "1. Enviar documento a imprimir (Encolar)\n";
    std::cout << "2. Imprimir siguiente documento (Desencolar)\n";
    std::cout << "3. Consultar documento actual en proceso\n";
    std::cout << "4. Mostrar estado del bufer (Cola Circular)\n";
    std::cout << "0. Salir\n";
    std::cout << "================================================\n";
}

#endif

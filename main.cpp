#include <iostream>
#include "cola_circular.h"
#include "validacion.h"
#include "interfaz.h"

using namespace std;

int main() {
    ColaCircular<Documento> colaImpresion;
    int opcion = 0;
    int contadorId = 1;

    Interfaz::iniciar();

    do {
        Interfaz::dibujar(colaImpresion);

        mostrarMenu();
        if (!leerEntero("Seleccione una opcion: ", opcion)) {
            continue;
        }

        switch (opcion) {
            case 1: {
                Documento nuevoDoc;
                nuevoDoc.id = contadorId++;
                cout << "ID del documento asignado: " << nuevoDoc.id << "\n";
                cout << "Ingrese el nombre del archivo (ej. Reporte.pdf): ";
                cin >> nuevoDoc.nombreArchivo;
                cin.ignore(10000, '\n');

                if (leerEntero("Ingrese el numero de paginas: ", nuevoDoc.paginas) && nuevoDoc.paginas > 0) {
                    colaImpresion.encolar(nuevoDoc);
                    cout << "Documento enviado a la impresora exitosamente.\n";
                } else {
                    cout << "Error: El numero de paginas debe ser mayor a cero.\n";
                    contadorId--;
                }
                break;
            }
            case 2: {
                Documento docAtendido;
                if (colaImpresion.desencolar(docAtendido)) {
                    cout << "\n[IMPRIMIENDO...]\n";
                    cout << "ID: " << docAtendido.id << " | Archivo: " << docAtendido.nombreArchivo << "\n";
                } else {
                    cout << "Advertencia: El bufer de impresion esta vacio.\n";
                }
                break;
            }
            case 3: {
                Documento docFrente;
                if (colaImpresion.verFrente(docFrente)) {
                    cout << "\nDocumento en el cabezal: " << docFrente.nombreArchivo << "\n";
                } else {
                    cout << "El bufer esta vacio.\n";
                }
                break;
            }
            case 4:
                colaImpresion.mostrarEstado();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }

        cout << "\nPresione Enter para continuar...";
        cin.get();

        Interfaz::dibujar(colaImpresion);

    } while (opcion != 0);

    Interfaz::cerrar();
    return 0;
}

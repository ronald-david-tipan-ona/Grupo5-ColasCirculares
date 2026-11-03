# Simulador de Búfer de Impresora en Red (Cola Circular)

## 1. Nombre del Proyecto
Simulador de Búfer de Impresora en Red utilizando una estructura de Cola Circular.

## 2. Integrantes
- Ronald Tipán
- Katrina Mendoza
- Joel Martínez

## 3. Problema Real
En una oficina, una impresora en red recibe múltiples documentos de diferentes computadoras. La impresora tiene una memoria temporal (búfer) de tamaño fijo. Si llegan más documentos de los que puede almacenar, se debe gestionar el orden de llegada (FIFO) para imprimir de forma justa y, a medida que se imprimen, se debe liberar espacio para los nuevos documentos sin desperdiciar memoria.

## 4. Objetivo
Diseñar e implementar en C++ un sistema que simule el búfer de una impresora utilizando una estructura de datos dinámica (Cola Circular), aplicando tipos de datos abstractos (TDA), clases genéricas (templates) y gestión de memoria dinámica, con una interfaz gráfica que permita visualizar el estado del búfer en tiempo real.

## 5. Justificación de la Estructura
Se eligió una **Cola Circular** implementada con memoria dinámica y enlaces circulares (punteros) porque:
- **Eficiencia:** Permite encolar (enviar a imprimir) y desencolar (imprimir) en tiempo O(1).
- **Ahorro de memoria:** Al ser circular, reutiliza los espacios que se van liberando en el frente, sin necesidad de desplazar todos los elementos.
- **TDA Genérico:** Se usó `template <typename T>` para que la cola pueda almacenar cualquier tipo de dato (en este caso, la estructura `Documento`).

## 6. Operaciones Requeridas (TDA)
- `encolar(T valor)`: Añade un documento al final de la cola.
- `desencolar(T& valor)`: Saca el documento del frente (simula la impresión).
- `verFrente(T& valor)`: Consulta qué documento se imprimirá a continuación.
- `mostrarEstado()`: Recorre la cola circular para mostrar todos los documentos en espera.
- `vaciar()`: Libera toda la memoria dinámica ocupada.

## 7. Diseño del TDA
El TDA está diseñado con las siguientes características:
- **Clase genérica:** `template <typename T> class ColaCircular`.
- **Encapsulamiento:** Atributos privados (`frente`, `fin`, `cantidad`, y un `struct Nodo` interno).
- **Memoria Dinámica:** Uso de `new` para crear nodos y `delete` en el destructor para evitar fugas de memoria.
- **Estructura Circular:** El puntero `sig` del último nodo (fin) apunta al primer nodo (frente), creando un ciclo cerrado.

## 8. Propuesta de UI y Librería Seleccionada
Para la representación visual se utilizó la librería **Raylib**. Se eligió esta librería porque:
- Es de código abierto, moderna y fácil de instalar en Code::Blocks.
- Permite dibujar formas geométricas (rectángulos, textos) de manera sencilla para representar visualmente las tarjetas del búfer.
- Permite mostrar en tiempo real cómo los documentos avanzan circularmente (Frente y Fin) a medida que la impresora los procesa.

## 9. Instrucciones de Ejecución de la Librería y del Proyecto

### Opción 1: Descargar el Ejecutable (Recomendado)
1. Ve a la sección **Releases** en la barra derecha de este repositorio.
2. Descarga el archivo `SimuladorImpresora.exe`.
3. Haz doble clic en el archivo descargado y el programa se abrirá. (No requiere instalación).

### Opción 2: Compilar el Código Fuente en Code::Blocks
1. Descarga o clona este repositorio.
2. Abre el archivo `.cbp` con **Code::Blocks**.
3. **Instalación de Raylib (Obligatorio):** Descarga Raylib para MinGW (versión 64-bit) desde su página oficial (https://www.raylib.com/).
4. En Code::Blocks, ve a `Project -> Build options -> Search directories` y agrega las carpetas `include` y `lib` de Raylib.
5. En `Linker settings`, agrega las librerías: `raylib`, `opengl32`, `gdi32`, `winmm`.
6. En `Other linker options`, pega exactamente esto: `-lraylib -lopengl32 -lgdi32 -lwinmm`.
7. Compila y ejecuta (F9).

---
## Organización de Archivos Utilizados
- `cola_circular.h`: Declaración del TDA con templates.
- `operaciones_cola_circular.h`: Implementación de las operaciones con memoria dinámica.
- `validacion.h`: Manejo de entradas y menú por consola.
- `interfaz.h`: Dibujo del búfer circular usando Raylib.
- `main.cpp`: Punto de entrada que une la lógica y la interfaz.

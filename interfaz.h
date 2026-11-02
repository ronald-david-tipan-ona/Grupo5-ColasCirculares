#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <raylib.h>
#include "cola_circular.h"
#include <string>

namespace Interfaz {
    inline void iniciar() {

        InitWindow(900, 650, "Sistema de Impresion en Red - Cola Circular (Raylib)");
        SetTargetFPS(60);
    }

    inline void dibujar(const ColaCircular<Documento>& cola) {
        if (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(GetColor(0xF5F6FAFF));

            //encabezado
            DrawRectangle(0, 0, 900, 70, GetColor(0x1E272EFF));
            DrawText("SISTEMA DE IMPRESION EN RED (SPOOLER)", 25, 20, 22, RAYWHITE);
            DrawText("Estructura: Cola Circular Dinamica", 625, 25, 14, LIGHTGRAY);

            // seccion impresora
            DrawRectangle(30, 90, 840, 110, WHITE);
            DrawRectangleLines(30, 90, 840, 110, GetColor(0xD2DAE2FF));

            DrawRectangle(50, 110, 140, 70, GetColor(0x485460FF));
            DrawText("IMPRESORA", 65, 135, 14, RAYWHITE);

            Documento docFrente;
            if (cola.verFrente(docFrente)) {
                DrawText("Estado: Imprimiendo Activamente", 210, 115, 14, GetColor(0x0BE881FF));
                std::string txtId = "ID Doc: " + std::to_string(docFrente.id);
                std::string txtArchivo = "Archivo: " + docFrente.nombreArchivo;
                std::string txtPag = "Paginas: " + std::to_string(docFrente.paginas);

                DrawText(txtId.c_str(), 210, 140, 14, BLACK);
                DrawText(txtArchivo.c_str(), 360, 140, 14, BLACK);
                DrawText(txtPag.c_str(), 620, 140, 14, BLACK);
            } else {
                DrawText("Estado: Inactiva (Bufer Vacio)", 210, 138, 16, GetColor(0x808E9BFF));
            }

            //seccion del bufer
            DrawText("ESTADO DEL BUFER DE MEMORIA TEMPORAL:", 30, 230, 16, GetColor(0x1E272EFF));

            int total = cola.obtenerTamanio();
            std::string totalTxt = "Total documentos en cola: " + std::to_string(total);
            DrawText(totalTxt.c_str(), 640, 230, 14, GetColor(0x808E9BFF));

            //contenedor principal de la cola
            DrawRectangle(30, 260, 840, 340, WHITE);
            DrawRectangleLines(30, 260, 840, 340, GetColor(0xD2DAE2FF));

            if (total == 0) {
                DrawText("El bufer circular esta vacio. No hay documentos pendientes.", 220, 420, 15, GetColor(0x808E9BFF));
            } else {
                int startX = 60;
                int startY = 300;
                int boxWidth = 240;
                int boxHeight = 110;
                int marginX = 30;
                int marginY = 30;
                int maxCols = 3;

                // Dibujar nodos secuenciales de la cola circular
                for (int i = 0; i < total; ++i) {
                    Documento doc = cola.obtenerEnPosicion(i);
                    int col = i % maxCols;
                    int row = i / maxCols;

                    int posX = startX + col * (boxWidth + marginX);
                    int posY = startY + row * (boxHeight + marginY);

                    if (posY + boxHeight < 580) {
                        Color colorBox = (i == 0) ? GetColor(0xD2F8F2FF) : GetColor(0xF1F2F6FF);
                        Color colorBorder = (i == 0) ? GetColor(0x0BE881FF) : GetColor(0xCED6E0FF);

                        DrawRectangle(posX, posY, boxWidth, boxHeight, colorBox);
                        DrawRectangleLines(posX, posY, boxWidth, boxHeight, colorBorder);

                        std::string posLabel = "[" + std::to_string(i + 1) + "]";
                        if (i == 0) posLabel += " (FRENTE)";
                        if (i == total - 1) posLabel += " (FIN)";

                        DrawText(posLabel.c_str(), posX + 10, posY + 10, 12, GetColor(0x485460FF));

                        std::string idStr = "ID: " + std::to_string(doc.id);
                        std::string nameStr = "Arch: " + doc.nombreArchivo;
                        std::string pagStr = "Pags: " + std::to_string(doc.paginas);

                        DrawText(idStr.c_str(), posX + 10, posY + 35, 13, BLACK);
                        DrawText(nameStr.c_str(), posX + 10, posY + 55, 13, BLACK);
                        DrawText(pagStr.c_str(), posX + 10, posY + 75, 13, BLACK);

                        //indicador visual
                        if (total > 1) {
                            DrawCircle(posX + boxWidth - 15, posY + boxHeight / 2, 4, GetColor(0x0BE881FF));
                        }
                    }
                }
            }


            DrawText("Nota: La interfaz grafica se actualiza automaticamente al interactuar con el menu de consola.", 30, 615, 12, GetColor(0x808E9BFF));

            EndDrawing();
        }
    }

    inline void cerrar() {
        CloseWindow();
    }
}

#endif

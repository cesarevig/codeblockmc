#ifndef MENURENDERER_HPP
#define MENURENDERER_HPP

#include <string>

void display(); // Aggiungi questa riga

// Funzione per disegnare i box di inserimento testo (Nome e Seed)
void drawInputBox(int x, int y, int width, int height, std::string text, bool isActive);

// Funzione per i pulsanti classici grigi di Minecraft
void drawButton(int x, int y, int width, int height, std::string label, bool isHovered);

// Funzione che raggruppa il disegno della schermata "Crea Nuovo Mondo"
void drawCreateWorldMenu(int screenWidth, int screenHeight);

// Funzione che raggruppa il disegno della schermata "Main Menu"
void drawMainMenu(int screenWidth, int screenHeight);

// Utility per passare dalla vista 3D alla vista 2D del menu
void setupOrtho(int width, int height);
void restorePerspective();

#endif


#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include <string>
#include <GL/freeglut.h>

// Dichiara la funzione così puoi usarla altrove
void drawInputBox(int x, int y, int width, int height, std::string text, bool isActive);
void drawMenu(); // Funzione che raggruppa tutto il disegno del menu
#endif


#include <iostream>
#include <string>
#include <windows.h>      // Fondamentale su Windows prima di GL
#include <GL/freeglut.h>

void drawInputBox(int x, int y, int width, int height, std::string text, bool isActive) {
    // 1. Disegna il bordo (leggermente più grande del fondo)
    // Se attivo, il bordo è bianco/giallo, altrimenti grigio scuro
    if (isActive) glColor3f(1.0f, 1.0f, 1.0f); // Bianco
    else glColor3f(0.5f, 0.5f, 0.5f);          // Grigio

    glBegin(GL_QUADS);
        glVertex2i(x - 1, y - 1);
        glVertex2i(x + width + 1, y - 1);
        glVertex2i(x + width + 1, y + height + 1);
        glVertex2i(x - 1, y + height + 1);
    glEnd();

    // 2. Disegna il fondo nero del campo di testo
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
    glEnd();

    // 3. Disegna il testo all'interno
    glColor3f(1.0f, 1.0f, 1.0f); // Testo bianco
    glRasterPos2i(x + 10, y + 18); // Posiziona il "cursore" del testo

    // Se è attivo, aggiungi il cursore "_" alla fine
    std::string displayTexture = text + (isActive ? "_" : "");

    for (char c : displayTexture) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
}


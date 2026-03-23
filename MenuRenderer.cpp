#include <windows.h>
#include <GL/freeglut.h>
#include "MenuRenderer.hpp"
#include "GameApplication.hpp"
#include <string>

void display() {
    // Pulisce lo schermo con il grigio scuro di Minecraft
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Imposta la vista 2D (Ortho)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 600, 0); // Adatta ai pixel della tua finestra
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (currentGameState == GameState::MAIN_MENU) {
        drawButton(300, 200, 200, 30, "Crea nuovo mondo", false);
        drawButton(300, 250, 200, 30, "Esci dal gioco", false);
    }
    else if (currentGameState == GameState::CREATE_WORLD_MENU) {
        // 1. Passa alla modalità 2D (Ortho)
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 800, 600, 0); // Assumendo finestra 800x600
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // 2. Disegna i due campi che hai creato
        // Campo Nome (attivo se activeField == 1)
        drawInputBox(300, 150, 200, 30, worldName, activeField == 1);

        // Campo Seme (attivo se activeField == 2)
        drawInputBox(300, 210, 200, 30, worldSeed, activeField == 2);

        // Pulsante "Crea nuovo mondo" (Coordinate: x=300, y=300)
        drawButton(300, 300, 200, 30, "Crea nuovo mondo", false);

        // Pulsante "Annulla" (Coordinate: x=300, y=350)
        drawButton(300, 350, 200, 30, "Annulla", false);

        // 3. Torna alla modalità 3D (se necessario)
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }

    glutSwapBuffers();
}

void drawButton(int x, int y, int width, int height, std::string label, bool isHovered) {
    // Colore del bordo: bianco/giallo se il mouse è sopra, grigio scuro altrimenti
    if (isHovered) glColor3f(1.0f, 1.0f, 0.6f); // Giallino stile Minecraft
    else glColor3f(0.3f, 0.3f, 0.3f);          // Grigio scuro

    glBegin(GL_QUADS);
        glVertex2i(x - 2, y - 2);
        glVertex2i(x + width + 2, y - 2);
        glVertex2i(x + width + 2, y + height + 2);
        glVertex2i(x - 2, y + height + 2);
    glEnd();

    // Fondo del bottone (grigio medio)
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
    glEnd();

    // Testo del bottone (nero o bianco)
    glColor3f(1.0f, 1.0f, 1.0f);
    int textX = x + (width / 2) - (label.length() * 4); // Centratura approssimativa
    glRasterPos2i(textX, y + (height / 2) + 5);

    for (char c : label) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
}

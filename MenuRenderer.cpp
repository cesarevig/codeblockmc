#include <windows.h>
#include <GL/freeglut.h>
#include "MenuRenderer.hpp"
#include "GameApplication.hpp"
#include <string>
#include <GL/glut.h>

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
        // Disegniamo la scritta "Nome del mondo" 20 pixel sopra il primo campo (150 - 20 = 130)
        drawText(300, 140, "Nome del mondo");
        drawInputBox(300, 150, 200, 30, worldName, activeField == 1);

        // Campo Seme (attivo se activeField == 2)
        // Disegniamo la scritta "Seme del mondo" 20 pixel sopra il secondo campo (210 - 20 = 190)
        drawText(300, 220, "Seme del mondo");
        drawInputBox(300, 230, 200, 30, worldSeed, activeField == 2);

        // Pulsante "Crea nuovo mondo" (Coordinate: x=300, y=300)
        drawButton(300, 300, 200, 30, "Crea nuovo mondo", false);

        // Pulsante "Annulla" (Coordinate: x=300, y=350)
        drawButton(300, 350, 200, 30, "Annulla", false);

        if (showDuplicateError) {
            glColor3f(1.0f, 0.0f, 0.0f); // Rosso Minecraft (errore)
            std::string errorMsg = "Un mondo con questo nome esiste gia'!";
            int textX = 400 - (errorMsg.length() * 4); // Centra il testo
            glRasterPos2i(textX, 280); // Posizionalo tra i box e il tasto Crea

            for (char c : errorMsg) {
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
            }
        }

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

void drawText(int x, int y, std::string text) {
    // Imposta la posizione dove iniziare a scrivere
    // Nota: in OpenGL 2D le coordinate potrebbero dover essere invertite a seconda del tuo setup
    glRasterPos2i(x, y);

    // Disegna ogni carattere della stringa uno alla volta
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }
}

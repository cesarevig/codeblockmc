#include <GL/freeglut.h>       // Per i tasti del mouse e glutPostRedisplay
#include "GameApplication.hpp" // Per currentGameState e activeField

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (currentGameState == GameState::CREATE_WORLD_MENU) {

            // Box Nome (150-180)
            if (x >= 300 && x <= 500 && y >= 150 && y <= 180) activeField = 1;
            // Box Seme (210-240)
            else if (x >= 300 && x <= 500 && y >= 210 && y <= 240) activeField = 2;

            // CLICK SU "CREA NUOVO MONDO" (300-330)
            else if (x >= 300 && x <= 500 && y >= 300 && y <= 330) {
                currentGameState = GameState::IN_GAME;
                printf("Generazione mondo: %s con seed: %s\n", worldName.c_str(), worldSeed.c_str());
            }

            // CLICK SU "ANNULLA" (350-380)
            else if (x >= 300 && x <= 500 && y >= 350 && y <= 380) {
                currentGameState = GameState::MAIN_MENU;
                activeField = 0;
            }

            else activeField = 0;
        }
        glutPostRedisplay();
    }
}



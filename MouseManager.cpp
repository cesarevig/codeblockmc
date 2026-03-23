#include <GL/freeglut.h>       // Per i tasti del mouse e glutPostRedisplay
#include "GameApplication.hpp" // Per currentGameState e activeField
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "SavesCreator.hpp"

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        if (currentGameState == GameState::MAIN_MENU) {
            // Pulsante "Crea nuovo mondo" (x=300, y=200, larghezza=200, altezza=30)
            if (x >= 300 && x <= 500 && y >= 200 && y <= 230) {
                currentGameState = GameState::CREATE_WORLD_MENU;
            }
            // Pulsante "Esci dal gioco" (x=300, y=250, larghezza=200, altezza=30)
            else if (x >= 300 && x <= 500 && y >= 250 && y <= 280) {
                exit(0);
            }
        }

        else if (currentGameState == GameState::CREATE_WORLD_MENU) {

            // Box Nome (150-180)
            if (x >= 300 && x <= 500 && y >= 150 && y <= 180) activeField = 1;
            // Box Seme (210-240)
            else if (x >= 300 && x <= 500 && y >= 210 && y <= 240) activeField = 2;

            // CLICK SU "CREA NUOVO MONDO" (300-330)
            else if (x >= 300 && x <= 500 && y >= 300 && y <= 330) {
                    if (createWorldSave(worldName, worldSeed)) {
                        currentGameState = GameState::IN_GAME; // Entra in gioco solo se il salvataggio è riuscito
                    }
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



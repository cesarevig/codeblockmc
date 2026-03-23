#include <GL/freeglut.h>
#include "GameApplication.hpp"
#include <string>

void keyboard(unsigned char key, int x, int y) {
    if (activeField == 1) { // Nome
        if (key == 8 && !worldName.empty()) worldName.pop_back();
        else if (key >= 32) worldName += key;
    }
    else if (activeField == 2) { // Seme
        if (key == 8 && !worldSeed.empty()) worldSeed.pop_back();
        else if (key >= 32) worldSeed += key;
    }
    glutPostRedisplay();
}

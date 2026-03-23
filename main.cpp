/*Progetto personale di ricreazine di minecraft alpha 1.0.1 in code::blocks
* code::blocks vers. 25.03
* lib freeglut
* framerate max 60fps
* MINECRAFT alpha 1.0.1 Demo
* Written mar 2026
*/

#include "WorldGenerator.h"
#include "GameApplication.hpp"
#include "MainMenu.hpp"
#include "MenuRenderer.hpp"
#include "MouseManager.hpp"
#include "KeyboardManager.hpp"
#include "PlayerMovement.hpp"


// Librerie Standard C++ (Utility)
#include <iostream>
#include <string>
#include <functional> // Necessario per convertire il Seed con std::hash
#include <GL/freeglut.h> // <--- INDISPENSABILE per OpenGL e GLUT
#include <string>        // <--- INDISPENSABILE per std::string


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Minecraft Alpha 1.0.1 Clone");

    // Registra la funzione display che sta in MenuRenderer.cpp
    glutDisplayFunc(display);

    // Registra anche mouse e tastiera
    glutMouseFunc(mouse);
    glutKeyboardFunc(KeyboardHandler);

    glutMainLoop();

    return 0;
}

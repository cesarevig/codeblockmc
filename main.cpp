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
    /*


    // 1. Configurazione Noise
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetSeed(1337);

    // 2. Creazione dinamica del chunk (usa 'new' per evitare lo Stack Overflow)
    Chunk* mioChunk = new Chunk();

    // 3. Generazione
    std::cout << "Generazione chunk [0,0] in corso..." << std::endl;
    GenerateChunk(*mioChunk, 0, 0, noise);
    std::cout << "Generazione completata!" << std::endl;

    // 4. Test rapido: vediamo cosa c'e' al centro del chunk a livello 60
    int blocco = mioChunk->blocks[8][60][8];
    std::cout << "Blocco a Y=60 (centro): ID " << blocco << std::endl;

    // 5. Pulizia memoria
    delete mioChunk;

    std::cout << "Premi un tasto per uscire..." << std::endl;
    std::cin.get();

    void drawInputBox(int x, int y, int width, int height, std::string text, bool isActive);

    */
    return 0;
}

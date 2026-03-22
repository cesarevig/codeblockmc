/*Progetto personale di ricreazine di minecraft alpha 1.0.1 in code::blocks
* code::blocks vers. 25.03
* lib freeglut
* framerate max 60fps
* MINECRAFT alpha 1.0.1 Demo
* Written mar 2026
*/

#include "WorldGenerator.h"
#include <iostream>

int main() {
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

    exit(0);
}


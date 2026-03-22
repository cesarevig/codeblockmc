
#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include "FastNoiseLite.h" // Assicurati di avere il file .h nella cartella del progetto
#include <vector>

// Definiamo le costanti per Alpha 1.0.1
const int CHUNK_SIZE = 16;
const int CHUNK_HEIGHT = 128;
const int WATER_LEVEL = 64;

// La struttura che contiene i dati dei blocchi
struct Chunk {
    int blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
};

// Il prototipo della funzione di generazione
void GenerateChunk(Chunk& chunk, int chunkX, int chunkZ, FastNoiseLite& noise);

#endif

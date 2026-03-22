#include "FastNoiseLite.h" // Assicurati che il nome corrisponda alla tua versione
#include "WorldGenerator.h"

#include <vector>

void GenerateChunk(Chunk& chunk, int chunkX, int chunkZ, FastNoiseLite& noise) {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int z = 0; z < CHUNK_SIZE; z++) {

            float worldX = (float)(chunkX * CHUNK_SIZE + x);
            float worldZ = (float)(chunkZ * CHUNK_SIZE + z);

            // Calcolo dell'altezza del terreno
            float noiseValue = noise.GetNoise(worldX, worldZ);
            int terrainHeight = (int)((noiseValue + 1.0f) * 0.5f * 30.0f) + 60;

            for (int y = 0; y < CHUNK_HEIGHT; y++) {

                // 1. GESTIONE BEDROCK (Fondo del mondo)
                if (y == 0) {
                    chunk.blocks[x][y][z] = 7; // Bedrock fisso al livello 0
                }
                else if (y < 5 && noise.GetNoise(worldX * 2.0f, (float)y * 5.0f, worldZ * 2.0f) > 0.3f) {
                    // Crea l'effetto "macchiato" del bedrock tra i livelli 1 e 4
                    chunk.blocks[x][y][z] = 7;
                }

                // 2. GESTIONE SOPRA IL TERRENO (Aria o Acqua)
                else if (y > terrainHeight) {
                    if (y <= WATER_LEVEL) {
                        chunk.blocks[x][y][z] = 9; // Acqua
                    } else {
                        chunk.blocks[x][y][z] = 0; // Aria
                    }
                }

                // 3. GESTIONE SUPERFICIE (Erba o Sabbia vicino all'acqua)
                else if (y == terrainHeight) {
                    if (y < WATER_LEVEL + 2) {
                        chunk.blocks[x][y][z] = 12; // Sabbia (vicino o sotto l'acqua)
                    } else {
                        chunk.blocks[x][y][z] = 2;  // Erba
                    }
                }

                // 4. GESTIONE SOTTOSUOLO (Terra e Pietra)
                else {
                    if (y > terrainHeight - 4) {
                        chunk.blocks[x][y][z] = 3; // Strato di Terra
                    } else {
                        chunk.blocks[x][y][z] = 1; // Pietra profonda
                    }
                }
            }
        }
    }
}



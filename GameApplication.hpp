#ifndef GAMEAPPLICATION_HPP
#define GAMEAPPLICATION_HPP

#include <string>

// Definiamo in che "pagina" del gioco ci troviamo
enum class GameState {
    MAIN_MENU,       // Schermata iniziale
    CREATE_WORLD_MENU,  // Menu dove inserisci Nome e Seed
    IN_GAME          // Il gioco vero e proprio (i chunk)
};

// 'extern' dice che la variabile è definita altrove
extern GameState currentGameState;
extern std::string worldName;
extern std::string worldSeed;
extern int activeField;

// Una struttura per salvare i dati inseriti dall'utente
struct WorldData {
    char name[64] = "Nuovo mondo";
    char seed[64] = "";
    int finalSeed = 0;
};

#endif


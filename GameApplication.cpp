#include "GameApplication.hpp"

// Definiamo i valori iniziali delle variabili dichiarate nell'header
GameState currentGameState = GameState::MAIN_MENU;

// I valori di default richiesti: "nuovo mondo 1" e seme vuoto
std::string worldName = "nuovo mondo 1";
std::string worldSeed = "";

// Partiamo con nessun campo selezionato (0)
// o con il primo campo selezionato (1)
int activeField = 0;

bool showDuplicateError = false;


#ifndef SAVESCREATOR_HPP
#define SAVESCREATOR_HPP

#include <string>

bool worldExists(std::string name);

// Funzione principale per creare la cartella e il file world_data.txt
bool createWorldSave(std::string name, std::string seed);

#endif

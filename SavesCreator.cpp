
#include "SavesCreator.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <ctime>

namespace fs = std::filesystem;

// Funzione interna per sostituire gli spazi con '_'
std::string sanitizeName(std::string name) {
    std::replace(name.begin(), name.end(), ' ', '_');
    return name;
}

bool createWorldSave(std::string name, std::string seed) {
    std::string folderName = sanitizeName(name);
    std::string path = "saves/" + folderName;

    try {
        // 1. Crea la cartella "saves" e la sottocartella del mondo
        if (!fs::exists("saves")) {
            fs::create_directory("saves");
        }
        fs::create_directories(path);

        // 2. Ottieni l'orario attuale (formato leggibile)
        std::time_t now = std::time(nullptr);
        char timeStr[26];
        ctime_s(timeStr, sizeof(timeStr), &now);

        // 3. Crea e scrivi il file world_data.txt
        std::ofstream file(path + "/world_data.txt");
        if (file.is_open()) {
            file << "Nome del Mondo: " << name << "\n";
            file << "Seme (Seed): " << seed << "\n";
            file << "Data di Creazione: " << timeStr;
            file.close();

            std::cout << "Salvataggio creato con successo in: " << path << std::endl;
            return true;
        }
    } catch (const std::exception& e) {
        std::cerr << "Errore creazione salvataggio: " << e.what() << std::endl;
    }
    return false;
}

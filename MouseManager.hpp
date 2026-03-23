
#ifndef MOUSEMANAGER_HPP
#define MOUSEMANAGER_HPP

// La funzione callback per il mouse richiesta da FreeGLUT
void mouseClick(int button, int state, int x, int y);

// Opzionale: funzione per monitorare il movimento del mouse (per l'effetto hover)
void mousePassiveMotion(int x, int y);

#endif

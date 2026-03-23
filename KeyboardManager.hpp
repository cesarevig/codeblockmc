#ifndef KEYBOARDMANAGER_HPP
#define KEYBOARDMANAGER_HPP

// Gestisce i tasti standard (lettere, numeri, spazio)
void keyboardHandler(unsigned char key, int x, int y);

// Gestisce i tasti speciali (frecce, F1, ecc. se ti serviranno)
void specialKeysHandler(int key, int x, int y);

#endif


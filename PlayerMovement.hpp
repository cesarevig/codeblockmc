#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP

struct Player {
    float posX = 0.0f;
    float posZ = 0.0f;
    float feetY = 0.0f;    // Coordinata Y dei piedi
    float eyesY = 1.6f;    // Coordinata Y degli occhi/telecamera
    float velocityY = 0.0f;
    bool isGrounded = true;
};

// Costanti di movimento
const float WALK_SPEED = 0.05f;
const float RUN_SPEED  = 0.12f;
const float SNEAK_SPEED = 0.02f;
const float JUMP_FORCE = 0.15f;
const float GRAVITY    = 0.008f;
const float EYE_HEIGHT = 1.6f;

// La funzione riceve lo stato dei tasti come semplici booleani (true/false)
void updatePlayerMovement(Player &p, float cameraYaw,
                          bool forward, bool backward, bool left, bool right,
                          bool jump, bool sprint, bool sneak);

#endif

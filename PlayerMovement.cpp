#include "PlayerMovement.hpp"
#include <cmath>

void updatePlayerMovement(Player &p, float cameraYaw,
                          bool forward, bool backward, bool left, bool right,
                          bool jump, bool sprint, bool sneak) {

    // 1. Determina la velocità in base a Shift (sprint) o Ctrl (sneak)
    float currentSpeed = WALK_SPEED;
    if (sprint) currentSpeed = RUN_SPEED;
    else if (sneak) currentSpeed = SNEAK_SPEED;

    // 2. Calcolo movimento orizzontale (WASD)
    // Sin e Cos usano cameraYaw per muoversi nella direzione dello sguardo
    if (forward) {
        p.posX += sin(cameraYaw) * currentSpeed;
        p.posZ += cos(cameraYaw) * currentSpeed;
    }
    if (backward) {
        p.posX -= sin(cameraYaw) * currentSpeed;
        p.posZ -= cos(cameraYaw) * currentSpeed;
    }
    if (left) {
        p.posX += cos(cameraYaw) * currentSpeed;
        p.posZ -= sin(cameraYaw) * currentSpeed;
    }
    if (right) {
        p.posX -= cos(cameraYaw) * currentSpeed;
        p.posZ += sin(cameraYaw) * currentSpeed;
    }

    // 3. Gestione Salto e Gravità
    if (jump && p.isGrounded) {
        p.velocityY = JUMP_FORCE;
        p.isGrounded = false;
    }

    if (!p.isGrounded) {
        p.velocityY -= GRAVITY;
    }

    p.feetY += p.velocityY;

    // Semplice collisione col terreno (Y=0) per evitare di cadere all'infinito
    if (p.feetY <= 0.0f) {
        p.feetY = 0.0f;
        p.velocityY = 0.0f;
        p.isGrounded = true;
    }

    // 4. Aggiornamento posizione Occhi (Telecamera)
    p.eyesY = p.feetY + EYE_HEIGHT;
}

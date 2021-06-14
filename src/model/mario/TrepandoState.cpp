#include "SueloState.h"
#include "TrepandoState.h"
#include "../../utils/Constants.hpp"

TrepandoState *TrepandoState::instance = NULL;

TrepandoState::TrepandoState() {}

TrepandoState *TrepandoState::getInstance() {
    if (instance == NULL) {
        instance = new TrepandoState();
    }
    return instance;
}

void TrepandoState::setLadder(Ladder *ladder) {
    this->ladder = ladder;
}

MarioState *TrepandoState::handleInput(char controls) {
    char left = (controls & LEFT) != 0;
    char right = (controls & RIGHT) != 0;
    velX = (right - left) * MARIO_VEL_X;

    char up = (controls & UP) != 0;
    char down = (controls & DOWN) != 0;
    velY = (up - down) * MARIO_VEL_TREPAR;

    return instance;
}

MarioState *TrepandoState::update(float *, float *y) {
    if ((velY <= 0 && std::abs(ladder->getBottom() - *y) <= MARIO_VEL_TREPAR)
    || (velY >= 0 && std::abs(ladder->getTop() - *y) <= MARIO_VEL_TREPAR))
    {
        estado = DE_ESPALDAS;
        return SueloState::getInstance();
    }
    *y -= velY;
    estado = TREPANDO;
    return instance;
}
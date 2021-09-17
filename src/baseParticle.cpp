#include "baseParticle.h"

float baseParticle::getLife() const
{
    return life;
}

void baseParticle::setLife(float life)
{
    this->life = life;
}

void baseParticle::update(float delatTime)
{
    life -= delatTime * 0.5f;
    //update pos
    //update velo
}

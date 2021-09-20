#include "basicParticle.h"

BasicParticle::BasicParticle(float life, float size, glm::vec2 pos, glm::vec2 velo)
{
    this->life = life;
    this->size = size;
    this->pos = pos;
    this->velo = velo;
}

float BasicParticle::getLife() const
{
    return life;
}

glm::vec2 BasicParticle::getPos() const
{
    return pos;
}


void BasicParticle::update(float delatTime)
{
    float decrement= delatTime * 0.5f;
    //update life
    life -= decrement;
    //update size
    size -= decrement;

    //update velo
    velo = velo / delatTime;
    //update pos
    pos += velo * delatTime;
    
}

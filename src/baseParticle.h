#pragma once
#include "Particle.h"
class BasicParticle : public Particle
{
 public:
    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
     float getLife() const override;

     void setLife(float life);
    // Updates the particle for a specified time increment (dt).
     void update(float dt) override;
private:
    float life;
};


#pragma once
#include "baseParticle.h"

class baseParticleGenerator : public ParticleGenerator<baseParticle>
{

    // Called when a new particle needs to be generated. When the function returns, the particle 
    // referenced by the parameter should be reinitialied as a new, random particle.
    virtual void respawn(baseParticle& particle) const override;
};


#pragma once
#include "basicParticle.h"

class BasicParticleGenerator : public ParticleGenerator<BasicParticle>
{

public:
    BasicParticleGenerator(float life, float minSize, float maxSize, float minVelo, float maxVelo);


    // Called when a new particle needs to be generated. When the function returns, the particle 
    // referenced by the parameter should be reinitialied as a new, random particle.
    virtual void respawn(BasicParticle& particle) const override;

private:
};


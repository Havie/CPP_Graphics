#pragma once
#include "Particle.h"
#include "BasicParticle.h"

class BasicParticleGenerator : public ParticleGenerator<BasicParticle> {
public:
	void respawn(BasicParticle& particle) const override;
};
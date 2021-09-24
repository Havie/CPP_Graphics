#pragma once
#include "Particle.h"
#include "BasicParticle.h"

class BasicParticleGenerator : public ParticleGenerator<BasicParticle> {
public:
    BasicParticleGenerator(float life, float minSize, float maxSize, glm::vec2 minVelo, glm::vec2 maxVelo, float xPosVariance, float yPosVariance);

	void respawn(BasicParticle& particle) const override;

private:
    float startingLife;
    float minSize;
    float maxSize;
    glm::vec2 minVelo;
    glm::vec2 maxVelo;
    float xPosVariance; 
    float yPosVariance;

    glm::vec2 getRandomV2(glm::vec2 min, glm::vec2 max) const;
    float getRandomValue(float min, float max) const;
};
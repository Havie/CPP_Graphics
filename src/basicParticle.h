#pragma once
#include "Particle.h"
#include "ofMain.h"
class BasicParticle : public Particle
{
public:
	BasicParticle(float life, float size, glm::vec2 pos, glm::vec2 velo);
	// Gets how much life the particle has left.  
	// When a particle's life is reduced to zero, it will be removed from the particle system.
	float getLife() const override;
	float getSize();
	glm::vec2 getPos() const;
	// Updates the particle for a specified time increment (dt).
	void update(float dt) override;

	
private:
	float life;
	float size;
	glm::vec2 pos;
	glm::vec2 velo;

};


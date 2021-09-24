#include "basicParticleGenerator.h"

BasicParticleGenerator::BasicParticleGenerator(float life, float minSize, float maxSize, glm::vec2 minVelo, glm::vec2 maxVelo)
{
	this->life = life;
	this->minSize = minSize;
	this->maxSize = maxSize;
	this->minVelo = minVelo;
	this->maxVelo = maxVelo;
}

void BasicParticleGenerator::respawn(BasicParticle& particle) const
{
	//todo- randomize (pos, color, tex)
	//Some odd kind of MOVE command doing  = without NEW makes this not allocate new memory?
							// life,  size, pos,  velo
	particle = BasicParticle(life, minSize, glm::vec2(0,0), minVelo);
}

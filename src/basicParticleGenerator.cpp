#include "basicParticleGenerator.h"

BasicParticleGenerator::BasicParticleGenerator( float life, float minSize, float maxSize, float minVelo, float maxVelo)
{

}

void BasicParticleGenerator::respawn(BasicParticle& particle) const
{
	//todo- randomize (pos, color, tex)

	//Some odd kind of MOVE command makes this not allocate new memory?
	particle = BasicParticle(1.0, 2, glm::vec2(), glm::vec2(1, 1));
}

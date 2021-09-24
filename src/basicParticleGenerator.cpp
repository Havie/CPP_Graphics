#include "BasicParticleGenerator.h"

void BasicParticleGenerator::respawn(BasicParticle& particle) const
{
	float life = 1.0f;

	//randomize things
	float size = 0.5f * ((rand() % 1001) / 1000.0);
	glm::vec2 position = glm::vec2((((rand() % 1001)-500) / 1000.0), (((rand() % 1001) - 500) / 1000.0));
	glm::vec2 velocity = glm::vec2((((rand() % 1001)-500) / 1000.0), (((rand() % 1001) - 500) / 1000.0));

	particle = BasicParticle(life, size, position, velocity);
	//particle.setLife(1.0f);
	
	/*std::cout << "life: " << life;
	std::cout << "size: " << size;
	std::cout << "position: " << position;
	std::cout << "velocity " << velocity;*/

}
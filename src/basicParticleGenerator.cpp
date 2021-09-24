#include "BasicParticleGenerator.h"


BasicParticleGenerator::BasicParticleGenerator(float life, float minSize, float maxSize, glm::vec2 minVelo, glm::vec2 maxVelo, float xPosVariance, float yPosVariance)
{
	this->startingLife = life;
	this->minSize = minSize;
	this->maxSize = maxSize;
	this->minVelo = minVelo;
	this->maxVelo = maxVelo;
	this->xPosVariance = xPosVariance;
	this->yPosVariance  = yPosVariance;
}


void BasicParticleGenerator::respawn(BasicParticle& particle) const
{

	float life = 1.0f;

	//randomize things
	float size = getRandomValue(minSize, maxSize);
	glm::vec2 position = getRandomV2(glm::vec2(-xPosVariance, xPosVariance), glm::vec2(-yPosVariance, yPosVariance));
	glm::vec2 velocity =getRandomV2(minVelo, maxVelo);

	particle = BasicParticle(life, size, position, velocity);
	//particle.setLife(1.0f);
	
	/*std::cout << "life: " << life;
	std::cout << "size: " << size;
	std::cout << "position: " << position;
	std::cout << "velocity " << velocity;*/

}

glm::vec2 BasicParticleGenerator::getRandomV2(glm::vec2 min, glm::vec2 max) const
{
	return glm::vec2(getRandomValue(min.x, max.x), getRandomValue(min.y, max.y));
}


float BasicParticleGenerator::getRandomValue(float min, float max) const
{
	return (rand() % ((int) (min + max) + 1) ) - min;
}
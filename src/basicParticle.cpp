#include "BasicParticle.h"


BasicParticle::BasicParticle(float life, float size, glm::vec2 pos, glm::vec2 velocity)
{
	this->life = life;
	this->size = size;
	this->position = pos;
	this->velocity = velocity;
}

float BasicParticle::getLife() const
{
	return life;
}

glm::vec2 BasicParticle::getVelocity() const
{
	return velocity;
}

glm::vec2 BasicParticle::getPosition() const
{
	return position;
}

float BasicParticle::getSize() const
{
	return size;
}

void BasicParticle::update(float dt)
{
	//life decreases by .5 every second
	life -= dt * 0.5;

	//update position; velocity? position?
	glm::vec2 changeInVelocity = velocity * dt;
	position += changeInVelocity;
	velocity -= changeInVelocity;
}

#pragma once
#include "Particle.h"
#include "ofMain.h"

class BasicParticle : public Particle {
public:

    BasicParticle(float life = 1.0f, float size = 1.0f, glm::vec2 pos = glm::vec2(0, 0), glm::vec2 velocity = glm::vec2(0, 0));

    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
    virtual float getLife() const override;

    //set how much life a particle has at the start
    //void setLife(float life);
    
    //get velocity of the particle
    virtual glm::vec2 getVelocity() const;

    //get position of the particle
    virtual glm::vec2 getPosition() const;

    //get size of the particle
    virtual float getSize() const;

    //gets image name for current particle??

    // Updates the particle for a specified time increment (dt).
    virtual void update(float dt) override;

private:
    float life;
    glm::vec2 position;
    glm::vec2 velocity;
    float size;
    string imageName;
};
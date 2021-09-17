#pragma once

// An interface for a particle.
class Particle
{
public:
    // Virtual destructor to ensure polymorphic cleanup.
    virtual ~Particle() {};

    // Gets how much life the particle has left.  
    // When a particle's life is reduced to zero, it will be removed from the particle system.
    virtual float getLife() const = 0;

    // Updates the particle for a specified time increment (dt).
    virtual void update(float dt) = 0;
};

// An interface for a particle generator that spawns particles of some specific type.
template <typename ParticleType>
class ParticleGenerator
{
public:
    // Virtual destructor to ensure polymorphic cleanup.
    virtual ~ParticleGenerator() {};

    // Called when a new particle needs to be generated. When the function returns, the particle 
    // referenced by the parameter should be reinitialied as a new, random particle.
    virtual void respawn(ParticleType& particle) const = 0;
};

#pragma once
#include <vector>
#include "ofMain.h"
#include "Particle.h"

// A class template that provides most of the boilerplate for a simple particle system.
// Source: https://learnopengl.com/In-Practice/2D-Game/Particles
template <typename ParticleType>
class ParticleSystem
{
public:
    // Construct a particle system using a specified particle generator that will be used when particles need to spawn.
    // numParticles needs to be greater than or equal to the particleRate times the typical particle life duration.
    ParticleSystem(ParticleGenerator<ParticleType>& generator, unsigned int numParticles = 20, float particleRate = 20.0f)
        : generator { generator }, numParticles { numParticles }, particleRate { particleRate }
    {
        // Make sure the type parameter is valid:
        static_assert(std::is_base_of<Particle, ParticleType>::value, "ParticleType must extend Particle.");

        for (unsigned int i { 0 }; i < numParticles; i++)
        {
            particles.emplace_back(); // Adds new default particle.
        }
    }

    // Updates each of the particles for a specified time increment (dt) and spawns new particles as necessary.
    void update (float dt)
    {
        particleRateAccum += particleRate * dt;

        while (particleRateAccum >= 1.0)
        {
            // Add new particles
            unsigned int unusedParticle { firstUnusedParticle() };
            generator.respawn(particles[unusedParticle]);

            particleRateAccum -= 1.0;
        }

        // Update all particles
        for (unsigned int i { 0 }; i < numParticles; i++)
        {
            particles[i].update(dt);
        }
    }

    // Begin iterating over the particles (read-only).
    auto begin() const
    {
        return particles.begin();
    }

    // Begin iterating over the particles.
    auto begin()
    {
        return particles.begin();
    }

    // Limit for iterating over the particles (read-only).
    auto end() const
    {
        return particles.end();
    }

    // Limit for iterating over the particles.
    auto end()
    {
        return particles.end();
    }

private:
    const ParticleGenerator<ParticleType>& generator;

    const unsigned int numParticles;
    const float particleRate;

    std::vector<ParticleType> particles;
    float particleRateAccum = { 1.0f };
    unsigned int lastUsedParticle { 0 };

    unsigned int firstUnusedParticle()
    {
        float minLife = particles[lastUsedParticle].getLife();
        unsigned int minLifeIndex = lastUsedParticle;

        // Search from last used particle; this will usually return almost instantly.
        for (unsigned int i { lastUsedParticle + 1 }; i < numParticles; i++)
        {
            if (particles[i].getLife() <= 0.0)
            {
                lastUsedParticle = i;
                return i;
            }
            else if (particles[i].getLife() < minLife)
            {
                minLife = particles[i].getLife();
                minLifeIndex = i;
            }
        }

        // Otherwise, do a linear search
        for (unsigned int i { 0 }; i <= lastUsedParticle; i++)
        {
            if (particles[i].getLife() <= 0.0)
            {
                lastUsedParticle = i;
                return i;
            }
            else if (particles[i].getLife() < minLife)
            {
                minLife = particles[i].getLife();
                minLifeIndex = i;
            }
        }

        // Use particle with the least life if all others are alive.
        lastUsedParticle = minLifeIndex;
        return minLifeIndex;
    }
};

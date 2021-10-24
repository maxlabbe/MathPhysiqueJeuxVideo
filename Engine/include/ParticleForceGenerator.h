#ifndef PARTICLEFORCEGENERATOR_H
#define PARTICLEFORCEGENERATOR_H

#include <Particle.h>

class IParticleForceGenerator
{
public:
	virtual void updateForce(Particle* particle, float duration) = 0;
};

#endif
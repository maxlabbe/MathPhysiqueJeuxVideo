#ifndef PARTICLEFORCEGENERATOR_H
#define PARTICLEFORCEGENERATOR_H

#include<Common.h>
#include <Particle.h>

class IParticleForceGenerator
{
public:
	virtual void updateForce(Particle* particle, float duration) = 0;
};

#endif
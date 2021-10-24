#ifndef PARTICLEGENERATOR_H
#define PARTICLEGENERATOR_H

#include <Particle.h>

class IParticleGenerator
{
	virtual void updateForce(Particle* particle, float duration) = 0;
};

#endif
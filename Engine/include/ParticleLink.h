#pragma once

#include "ParticleContactGenerator.h"
#include "Particle.h"

class ParticleLink : public IParticleContactGenerator
{
public :
	Particle* particle[2];
	float currentLength() const;
	void addContact();
};


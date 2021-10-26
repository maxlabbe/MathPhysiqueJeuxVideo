#pragma once

#include "ParticleContactGenerator.h"
#include "Particle.h"

class ParticleLink : public IParticleContactGenerator
{
	Particle* particle[2];

	float currentLength() const;

public:
	void addContact();
};


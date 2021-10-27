#pragma once

#include "ParticleLink.h"
#include "ParticleContact.h"

class ParticleCable : public ParticleLink
{
public:
	ParticleCable(Particle* particle[2], float f_maxlength, float f_restituation);
	float maxlength; //Longueur max du câble
	float restitution; //Coefficient de restitution
	void addContact();
};


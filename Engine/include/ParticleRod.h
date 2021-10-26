#pragma once

#include "ParticleLink.h"
#include "ParticleContact.h"

class ParticleRod : public ParticleLink
{
public:
	ParticleRod(Particle* v_particle[2], float f_length);
	float length; //Longueur de la tige
	void addContact();
};


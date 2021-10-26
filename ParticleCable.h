#pragma once

#include "ParticleLink.h"

class ParticleCable : public ParticleLink
{
	float maxlength; //Longueur max du câble
	float restituation; //Coefficient de restitution

	void addContact();
};


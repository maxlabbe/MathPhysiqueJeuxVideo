#pragma once

#include "ParticleLink.h"

class ParticleCable : public ParticleLink
{
	float maxlength; //Longueur max du c�ble
	float restituation; //Coefficient de restitution

	void addContact();
};


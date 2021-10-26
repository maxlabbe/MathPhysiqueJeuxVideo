#pragma once

#include "ParticleLink.h"

class ParticleRod : public ParticleLink
{
	float length; //Longueur de la tige

	void addContact();
};


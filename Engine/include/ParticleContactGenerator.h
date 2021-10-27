#ifndef IPARTICLEGENERATOR_H
#define IPARTICLEGENERATOR_H

#include<vector>
#include <Particle.h>
#include<ParticleContact.h>

class IParticleContactGenerator
{
public:
	virtual void addContact(vector<ParticleContact*> contacts) = 0;
};

#endif
#include "ParticleRod.h"

ParticleRod::ParticleRod(Particle* v_particle[2], float f_length) 
{
	length = f_length;
	particle[0] = v_particle[0];
	particle[1] = v_particle[1];
}

void ParticleRod::addContact()
{

}

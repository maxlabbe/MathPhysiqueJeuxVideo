#include "ParticleCable.h"

ParticleCable::ParticleCable(Particle* v_particle[2], float f_maxlength, float f_restitution)
{
	particle[0] = v_particle[0];
	particle[1] = v_particle[1];

	maxlength = f_maxlength;
	restitution = f_restitution;
}

void ParticleCable::addContact()
{
	if (currentLength() >= maxlength)
	{
		ParticleContact contact = ParticleContact(particle, restitution, 0);
	}
}

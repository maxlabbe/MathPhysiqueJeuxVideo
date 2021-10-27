#include "ParticleCable.h"

ParticleCable::ParticleCable(Particle* v_particle[2], float f_maxlength, float f_restitution) 
	: ParticleLink(v_particle), maxlength(f_maxlength), restitution(f_restitution) {}

void ParticleCable::addContact(vector<ParticleContact*> contacts)
{
	// We add a contact only if the cable is tense
	if (currentLength() >= maxlength)
	{
		// Create and add the contact
		ParticleContact* contact = new ParticleContact(p_particle, restitution, 0);
		contacts.push_back(contact);
	}
}

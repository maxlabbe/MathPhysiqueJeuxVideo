#include "ParticleRod.h"

ParticleRod::ParticleRod(Particle* v_particle[2], float f_length)
	: ParticleLink(v_particle), length(f_length) {}

void ParticleRod::addContact(vector<ParticleContact>& contacts)
{
	// Create a contact
	ParticleContact contact = ParticleContact(p_particle, 0, 0);

	// The contact is in the opposite of the contact point normal
	contact.oppositeNormal();

	// Add the contact to the list
	contacts.push_back(contact);
}

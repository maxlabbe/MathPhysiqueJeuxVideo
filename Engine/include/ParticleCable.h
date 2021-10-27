#pragma once

#include "ParticleLink.h"

class ParticleCable : public ParticleLink
{
public:

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="particle">Particle*[2]: the particles link to the cable </param>
	/// <param name="f_maxlength"> float : the cable's max length </param>
	/// <param name="f_restituation"> flaot : the cable's restitution coef </param>
	ParticleCable(Particle* particle[2], float f_maxlength, float f_restituation);

	/// <summary>
	/// Add contact to the list of contacts to compute the cable behavior between the particles
	/// </summary>
	/// <param name="contacts">vector<ParticleContact>&: the list of contact to resolve</param>
	void addContact(vector<ParticleContact>& contacts);

private:

	// Cable's max length
	float maxlength;

	// cables's restitution coef 
	float restitution; //Coefficient de restitution
};


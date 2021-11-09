#pragma once

#include "ParticleLink.h"

class ParticleRod : public ParticleLink
{

public:

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="v_particle">Particle*[2]: the particles link to the rod </param>
	/// <param name="f_length"> float : length of the rod </param>
	ParticleRod(Particle* v_particle[2], float f_length);
	
	/// <summary>
	/// Add contact to the list of contacts to maintain the rod between the particles
	/// </summary>
	/// <param name="contacts">vector<ParticleContact>&: the list of contact to resolve</param>
	void addContact(vector<ParticleContact*> contacts);

private:

	// Length of the rod
	float length;
};


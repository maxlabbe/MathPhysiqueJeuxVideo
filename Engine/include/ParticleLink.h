#ifndef PARTICLELINK_H
#define PARTICLELINK_H

#include <ParticleContactGenerator.h>

class ParticleLink : public IParticleContactGenerator
{
public:
	/// <summary>
	/// Default Ctor
	/// </summary>
	/// <param name="particle"></param>
	ParticleLink(Particle* particle[2]);

	/// <summary>
	/// define in daughters classes
	/// </summary>
	/// <param name="contacts"> vector<ParticleContact>& : list of contact to update </param>
	void addContact(vector<ParticleContact>& contacts);

protected :

	// Particle invovled in the link
	Particle* p_particle[2];

	/// <summary>
	/// Give the distance between the particles
	/// </summary>
	/// <returns> float : the distance norm</returns>
	float currentLength() const;


};

#endif


#ifndef BUNGEEELASTIC_H
#define BUNGEEELASTIC_H

#include<ParticleForceGenerator.h>

class BungeeElastic : IParticleForceGenerator
{
public:

	/// <summary>
	/// Ctor where the elastic parameters are set to default
	/// </summary>
	/// <param name="particle"> Particle : The opposite particle connected to the elastic</param>
	BungeeElastic(const Particle& particle);

	/// <summary>
	/// Custom elastic's ctor
	/// </summary>
	/// <param name="particle"> Particle : The opposite particle connected to the elastic</param>
	/// <param name="k"> float : Elastic's elasticity constant</param>
	/// <param name="l0"> float : Elastic's rest size</param>
	BungeeElastic(const Particle& particle, float k, float l0);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(Particle* particle, float duration);

private:
	// The opposite particle connected to the elastic
	const Particle& m_particle;

	// elastic's elasticity constant
	float m_k;

	// elastic's rest size
	float m_l0;

};

#endif


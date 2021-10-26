#ifndef PARTICLESPRING_H
#define PARTICLESPRING_H

#include<ParticleForceGenerator.h>

class ParticleSpring : public IParticleForceGenerator
{
public:
	/// <summary>
	/// Ctor where the spring parameters are set to default
	/// </summary>
	/// <param name="particle"> Particle : The opposite particle connected to the spring</param>
	ParticleSpring(const Particle& particle);

	/// <summary>
	/// Custom spring's ctor
	/// </summary>
	/// <param name="particle"> Particle : The opposite particle connected to the spring</param>
	/// <param name="k"> float : Spring's elasticity constant</param>
	/// <param name="l0"> float : Spring's rest size</param>
	ParticleSpring(const Particle& particle, float k, float l0);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(Particle* particle, float duration);

private:
	// The opposite particle connected to the spring
	const Particle& m_particle;

	// Spring's elasticity constant
	float m_k;

	// Spring's rest size
	float m_l0;
};

#endif

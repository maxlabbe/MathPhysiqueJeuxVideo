#ifndef PARTICLEFORCEGENERATOR_H
#define PARTICLEFORCEGENERATOR_H

#include<Common.h>
#include <Particle.h>

/// <summary>
/// Interface of all the force generator
/// </summary>
class IParticleForceGenerator
{
public:

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	virtual void updateForce(Particle* particle, float duration) = 0;
};

#endif
#ifndef DAMPEDHARMONICMOVEMENT_H
#define DAMPEDHARMONICMOVEMENT_H

#include<ParticleForceGenerator.h>
#include<math.h>
class DampedHarmonicMovement : IParticleForceGenerator
{
public:

	/// <summary>
	/// damped harmonic movement default Ctor (harmonic movement with k = 1)
	/// </summary>
	DampedHarmonicMovement();

	/// <summary>
	/// damped harmonic movement custom Ctor
	/// </summary>
	/// <param name="k"> float : Spring's elasticity constant</param>
	/// <param name="dumping"> float : dumping </param>
	DampedHarmonicMovement(float k, float dumping);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(Particle* particle, float duration);

private:

	// Spring's elasticity constant
	float m_k;

	//Dumping
	float m_dumping;
};

#endif
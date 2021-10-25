#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H

#include<ParticleForceGenerator.h>


class GravityGenerator : IParticleForceGenerator
{
public: 
	/// <summary>
	/// Default Ctor
	/// </summary>
	GravityGenerator();

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="gravityValue"> float : the custom value of the gravity int the -y direction </param>
	GravityGenerator(float gravityValue);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(Particle* particle, float duration);

private:
	// the gravity vector
	Vector3D m_gravityVector;
};

#endif


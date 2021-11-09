#ifndef DRAGGENERATOR_H
#define DRAGGENERATOR_H

#include<ParticleForceGenerator.h>

class DragGenerator : public IParticleForceGenerator
{
public:
	/// <summary>
	/// Default ctor of the drag force
	/// </summary>
	DragGenerator();

	/// <summary>
	/// Custom generator of the drag force allowing the user to shoose the k1 and k2 constants
	/// </summary>
	/// <param name="k1"> float : the k1 constant </param>
	/// <param name="k2"> float : the k2 constant </param>
	DragGenerator(float k1, float k2);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(Particle* particle, float duration);

private:

	// first degree's constant
	float m_k1;

	// second degree's constant
	float m_k2;
};

#endif


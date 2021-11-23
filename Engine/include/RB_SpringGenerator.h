#ifndef RB_SPRINGGENERATOR_H
#define RB_SPRINGGENERATOR_H
#include <RB_ForceGenerator.h>
#include <ParticleSpring.h>

class RB_SpringGenerator : public IRB_ForceGenerator
{
public :

	/// <summary>
/// Custom spring's ctor
/// </summary>
/// <param name="particle"> Particle : The opposite particle connected to the spring</param>
/// <param name="k"> float : Spring's elasticity constant</param>
/// <param name="l0"> float : Spring's rest size</param>
	RB_SpringGenerator(const RigidBody& rigidBody, float k, float l0) : m_rigidBody(rigidBody), m_k(k), m_l0(l0) {}

	void updateForce(RigidBody* rigidBody, float duration);

private:
	// The opposite particle connected to the spring
	const RigidBody & m_rigidBody;

	// Spring's elasticity constant
	float m_k;

	// Spring's rest size
	float m_l0;
};
#endif


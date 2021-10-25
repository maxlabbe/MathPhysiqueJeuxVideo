#include <GravityGenerator.h>

// Apply the reel value of gravity as default value
GravityGenerator::GravityGenerator() : m_gravityVector(Vector3D(0, -9.81f, 0)) {}
GravityGenerator::GravityGenerator(float gravityValue) : m_gravityVector(Vector3D(0, -gravityValue, 0)) {}

void GravityGenerator::updateForce(Particle* particle, float duration)
{
	// Apply the gravity force to the particle if the mass isn't nul
	float mass = particle->getMass();
	if (mass != 0)
	{
		particle->addForce(m_gravityVector.multiplyByScalar(mass));
	}
}

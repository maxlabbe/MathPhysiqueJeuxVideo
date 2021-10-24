#include <GravityGenerator.h>

GravityGenerator::GravityGenerator() : m_gravityValues(Vector3D(0, -9.81f, 0)) {}
GravityGenerator::GravityGenerator(float gravityValue) : m_gravityValues(Vector3D(0, -gravityValue, 0)) {}

void GravityGenerator::updateForce(Particle* particle, float duration)
{
	float mass = particle->getMass();
	if (mass != 0)
	{
		particle->addForce(m_gravityValues.multiplyByScalar(mass));
	}
}

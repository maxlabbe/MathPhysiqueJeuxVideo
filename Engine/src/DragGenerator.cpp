#include <DragGenerator.h>

// We choose 5 for both the constants as default values
DragGenerator::DragGenerator() : m_k1(5.0f), m_k2(5.0f) {}
DragGenerator::DragGenerator(float k1, float k2) : m_k1(k1), m_k2(k2) {}

void DragGenerator::updateForce(Particle* particle, float duration)
{
	float velocityNorm = particle->getVelocity().norm();

	// We need a unit vector in the same direction as the velocity to compute the force
	// Drag coef = k1 * ||v|| + k2 * ||v||²
	// Add the force to the particle
	particle->addForce(particle->getVelocity().normalize() * (m_k1 * velocityNorm + m_k2 * velocityNorm * velocityNorm));
	
}

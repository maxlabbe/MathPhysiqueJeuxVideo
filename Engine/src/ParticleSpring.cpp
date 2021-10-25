#include <ParticleSpring.h>

ParticleSpring::ParticleSpring(const Particle& particle) : ParticleSpring(particle, 1.0f, 1.0f) {}
ParticleSpring::ParticleSpring(const Particle& particle, float k, float l0) : m_particle(particle), m_k(k), m_l0(l0) {}

void ParticleSpring::updateForce(Particle* particle, float duration)
{
	// l is the spring stretching so the distance beetween the two particles
	Vector3D distance = particle->getPosition() - m_particle.getPosition();

	// Now we compute the value of the force add it to the particle
	// To compute the force we calculate the force's value and apply it to the distance's unit vector
	//F = k(l0 - l)
	particle->addForce(distance.normalize() * (m_k * (m_l0 - distance.norm())));
}

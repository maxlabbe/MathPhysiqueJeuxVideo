#include "ParticleContact.h"

ParticleContact::ParticleContact(Particle* particles[2])
	: m_particles(), m_restitutionCoef(0), m_contactPointNormal(Vector3D()), m_penetration(Vector3D()), m_impulsion(Vector3D())
{
	// Add the particles in the particles array
	m_particles[0] = particles[0];
	m_particles[1] = particles[1];
}


ParticleContact::ParticleContact(Particle* particles[2], float restitutionCoef)
	: m_particles(), m_restitutionCoef(restitutionCoef), m_contactPointNormal(Vector3D()), m_penetration(Vector3D()), m_impulsion(Vector3D()) 
{
	// Add the particles in the particles array
	m_particles[0] = particles[0];
	m_particles[1] = particles[1];
}

void ParticleContact::resolve(float duration) 
{
	
}

void ParticleContact::computeApproachVelocity() const 
{

}

void ParticleContact::ResolveImpulsion(float duration) {}

void ParticleContact::resolveInterpenetration() {}

void ParticleContact::resolveVelocity(float duration) {}

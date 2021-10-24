#include "ForceRegister.h"

void ForceRegister::registerForce(Particle* particle, IParticleForceGenerator* forceGenerator)
{
	ForceRegistration forceToRegister = { particle, forceGenerator };
	m_register.push_back(forceToRegister);
}

void ForceRegister::deleteForce()
{
}

void ForceRegister::updateAllForces(float duration)
{
	for (ForceRegistration forceRegistered : m_register) {
		forceRegistered.m_forceGenerator->updateForce(forceRegistered.m_particle, duration);
	}
}

ForceRegister::ForceRegister(): m_register(Register(10))
{
}

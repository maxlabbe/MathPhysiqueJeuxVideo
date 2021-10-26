#include "ForceRegister.h"

void ForceRegister::registerForce(Particle* particle, IParticleForceGenerator* forceGenerator)
{
	ForceRegistration forceToRegister = { particle, forceGenerator };
	m_register.push_back(forceToRegister);
}

void ForceRegister::updateAllForces(float duration)
{
	float forcesNormBeforeUpdate;
	float forcesNormAfterUpdate;

	// Iterate over all the forces registered
	for (auto it = m_register.begin(); it != m_register.end(); ) {
		forcesNormBeforeUpdate = it->m_particle->getAccumForces().squaredNorm();
		it->m_forceGenerator->updateForce(it->m_particle, duration);
		forcesNormAfterUpdate = it->m_particle->getAccumForces().squaredNorm();

		// If the force didn't have any effects an the particule, the force is erased from the registered forces
		if (abs(forcesNormBeforeUpdate-forcesNormAfterUpdate) == 0.0) {
			it = m_register.erase(it);
		}
		else {
			it++;
		}
	}
}

ForceRegister::ForceRegister(): m_register(Register(10))
{
}

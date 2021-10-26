#include "ForceRegister.h"

void ForceRegister::registerForce(Particle* particle, IParticleForceGenerator* forceGenerator)
{
	ForceRegistration forceToRegister = { particle, forceGenerator };
	m_register.push_back(forceToRegister);
}

void ForceRegister::updateAllForces(float duration)
{
	Vector3D forcesBeforeUpdate;
	Vector3D forcesAfterUpdate;

	// Iterate over all the forces registered
	for (auto it = m_register.begin(); it != m_register.end(); ) {
		forcesBeforeUpdate = it->m_particle->getAccumForces();
		it->m_forceGenerator->updateForce(it->m_particle, duration);
		forcesAfterUpdate = it->m_particle->getAccumForces();

		// If the force didn't have any effects an the particule, the force is erased from the registered forces
		/*if ((forcesBeforeUpdate.getX() == forcesAfterUpdate.getX()) && (forcesBeforeUpdate.getY() == forcesAfterUpdate.getY()) && (forcesBeforeUpdate.getZ() == forcesAfterUpdate.getZ())) {
			it = m_register.erase(it);
		}
		else {
			
		}*/
		it++;
	}
}

ForceRegister::ForceRegister(): m_register(Register(0))
{
}

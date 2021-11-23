#include "ForceRegisterRigidBody.h"

void ForceRegisterRigidBody::registerForce(RigidBody* rigidBody, Vector3D applicationPoint, IRB_ForceGenerator* forceGenerator)
{
	ForceRegistration forceToRegister = { rigidBody, forceGenerator, applicationPoint };
	m_register.push_back(forceToRegister);
}

void ForceRegisterRigidBody::updateAllForces(float duration)
{
	//Vector3D forcesBeforeUpdate;
	//Vector3D forcesAfterUpdate;

	// Iterate over all the forces registered
	for (auto it = m_register.begin(); it != m_register.end(); ) {
		//forcesBeforeUpdate = it->m_particle->getAccumForces();
		it->m_forceGenerator->updateForce(it->m_rigidBody, it->m_point, duration);
		//forcesAfterUpdate = it->m_particle->getAccumForces();

		/* Part not implemented */
		// If the force didn't have any effects an the rigid body, the force is erased from the registered forces
		/*if ((forcesBeforeUpdate.getX() == forcesAfterUpdate.getX()) && (forcesBeforeUpdate.getY() == forcesAfterUpdate.getY()) && (forcesBeforeUpdate.getZ() == forcesAfterUpdate.getZ())) {
			it = m_register.erase(it);
		}
		else {

		}*/
		it++;
	}
}

ForceRegisterRigidBody::ForceRegisterRigidBody() : m_register(Register(0))
{
}

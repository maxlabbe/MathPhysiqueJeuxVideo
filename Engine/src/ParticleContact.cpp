#include "ParticleContact.h"

ParticleContact::ParticleContact(Particle* particles[2])
	: m_particles(), m_restitutionCoef(0), m_contactPointNormal(Vector3D()), m_penetration(0)
{
	// Add the particles in the particles array
	m_particles[0] = particles[0];
	m_particles[1] = particles[1];

	m_contactPointNormal = m_particles[0]->getPosition() - m_particles[1]->getPosition();
}


ParticleContact::ParticleContact(Particle* particles[2], float restitutionCoef, float penetration)
	: m_particles(), m_restitutionCoef(restitutionCoef), m_contactPointNormal(Vector3D()), m_penetration(penetration)
{
	// Add the particles in the particles array
	m_particles[0] = particles[0];
	m_particles[1] = particles[1];

	m_contactPointNormal = m_particles[0]->getPosition() - m_particles[1]->getPosition();
	m_contactPointNormal = m_contactPointNormal.normalize();
}

void ParticleContact::resolve(float duration) 
{
	//Resolve the interpenetretion
	resolveInterpenetration();

	//We will need the velocity and the acceleration to know if the particle is at rest
	float velocity = m_particles[0]->getVelocity().norm();
	float acceleration = m_particles[0]->getAcceleration().norm();

	//If the velocity is in the same direction as the normal thei are supposed to be colinear v = kn
	float xCoef = m_particles[0]->getVelocity().getX() / m_contactPointNormal.getX();
	float yCoef = m_particles[0]->getVelocity().getY() / m_contactPointNormal.getY();
	float zCoef = m_particles[0]->getVelocity().getZ() / m_contactPointNormal.getZ();
	
	// If there are not colinear
	if (xCoef != yCoef || xCoef != zCoef || yCoef != zCoef)
	{
		// Calculate the relative velocity and acceleration in the n's direction
		velocity = m_particles[0]->getVelocity() * m_contactPointNormal;
		acceleration = m_particles[0]->getAcceleration() * m_contactPointNormal;

		// If the velocity is due to the acceleration then there is a collision -> apply impulsion
		if (acceleration * duration < velocity)
		{
			resolveVelocity(duration);
		}
	}

	// we are in the same direction of the normal
	else
	{
		// If the velocity is due by the forces applied on the object we comput the impulsion
		if (m_particles[0]->getAccumForces().multiplyByScalar(duration).norm() < m_particles[0]->getVelocity().norm())
		{
			resolveVelocity(duration);
		}
	}
}

float ParticleContact::computeApproachVelocity() const 
{
	// Vs = (va - vb)
	return (m_particles[0]->getVelocity() - m_particles[1]->getVelocity()).scalarProduct(m_contactPointNormal);
}

void ParticleContact::resolveInterpenetration() 
{
	// The movement for the first particle is
	// deltaP0 = m1/m1+m0 * d . normal
	float movementCoef = (m_particles[1]->getMass() / (m_particles[1]->getMass() + m_particles[0]->getMass())) * m_penetration;
	m_particles[0]->setPosition(m_contactPointNormal.multiplyByScalar(movementCoef));
	
	// The movement for the second particle is
	// deltaP0 = m0/m1+m0 * d . normal
	movementCoef = (m_particles[0]->getMass() / (m_particles[1]->getMass() + m_particles[0]->getMass())) * m_penetration;
	m_particles[0]->setPosition(m_contactPointNormal.multiplyByScalar(movementCoef));

}

void ParticleContact::resolveVelocity(float duration) 
{
	//Vs' = -C * Vs
	// deltaVs = Vs' - Vs
	// => -C*Vs - Vs => Vs * (-C - 1)
	// => delatsVs = -Vs(C+1)
	float approcheVelocityDelta = -1 * computeApproachVelocity() * (m_restitutionCoef + 1);

	// Compute impulsion
	for (int particleIndex = 0; particleIndex < 2; particleIndex++)
	{
		// g = m*deltaVs
		float impulsionValue = m_particles[particleIndex]->getMass() * approcheVelocityDelta;

		//Put it in the normal direction
		Vector3D impulsion = impulsionValue * m_contactPointNormal;

		// v'(t) = v(t) + (g*normal)/m
		m_particles[particleIndex]->setVelocity(m_particles[particleIndex]->getVelocity() + impulsion * m_particles[particleIndex]->getInverseMass());
	}
}
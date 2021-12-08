#include "Common.h"
#include <MathTools/Vector3D.h>
#include "Particle.h"

void Particle::integrate(const float time)
{
	m_acceleration = m_accumForces * m_inverseMass;

	// Update the comput position
	UpdatePosition(time);

	// Update the comput velocity
	UpdateVelocity(time);

	//clearForce();
}

void Particle::addForce(Vector3D force)
{
	m_accumForces = m_accumForces + force;
}

void Particle::clearForce()
{
	m_accumForces.set(0, 0, 0);
}

void Particle::UpdatePosition(const float& time)
{
	// p' = new position
	// p = current position
	// v = current position
	// p' = p + v.time
	Vector3D newPosition = m_position + (m_velocity * time);
	m_position.set(newPosition.getX(), newPosition.getY(), newPosition.getZ());
}

void Particle::UpdateVelocity(const float& time)
{
	// v' = new velocity
	// v = current velocity
	// a = acceleration
	// D = dumping
	// v' = v + a.time
	Vector3D newVelocity = m_velocity + (m_acceleration * time);
	m_velocity.set(newVelocity.getX(), newVelocity.getY(), newVelocity.getZ());
}

Particle::Particle(float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, Vector3D forces, float radius)
{
	m_mass = mass;
	m_inverseMass = 1 / mass;
	m_position = Vector3D(position);
	m_velocity = Vector3D(velocity);
	m_acceleration = Vector3D(acceleration);
	m_accumForces = forces;
	m_radius = radius;
}




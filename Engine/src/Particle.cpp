#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"

void Particle::integrate(const float time)
{
	// Update the comput position
	UpdatePosition(time);

	// Update the comput velocity
	UpdateVelocity(time);
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
	// v' = v.d^time + a.time
	Vector3D newVelocity = ( m_velocity * powf(m_dumping, time) ) + (m_acceleration * time);
	m_velocity.set(newVelocity.getX(), newVelocity.getY(), newVelocity.getZ());
}

Particle::Particle(float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, float dumping)
{
	m_mass = mass;
	m_inverseMass = 1 / mass;
	m_position = Vector3D(position);
	m_velocity = Vector3D(velocity);
	m_acceleration = Vector3D(acceleration);
	m_dumping = dumping;
}




#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"

// Public methods

void Particle::integrate(const float time)
{
	UpdatePosition(time);
	UpdateVelocity(time);
}

// Private methods

void Particle::UpdatePosition(const float& time)
{
	Vector3D newPosition = position + (velocity * time);
	position.set(newPosition.getX(), newPosition.getY(), newPosition.getZ());
}

void Particle::UpdateVelocity(const float& time)
{
	Vector3D newVelocity = ( velocity * powf(dumping, time) ) + (acceleration * time);
	velocity.set(newVelocity.getX(), newVelocity.getY(), newVelocity.getZ());
}

// Constructors

Particle::Particle(float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, float dumping)
{
	this->mass = mass;
	this->inverseMass = 1 / mass;
	this->position = Vector3D(position);
	this->velocity = Vector3D(velocity);
	this->acceleration = Vector3D(acceleration);
	this->dumping = dumping;
}




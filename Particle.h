#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3D.h"

class Particle {

public :

	// Getters 

	float getMass() const { return mass; }
	float getInverseMass() const { return inverseMass; }
	Vector3D getPosition() const { return position; }
	Vector3D* getPositionPtr() { return &position; }

	// Public methods

	void integrate(float time);

	// Constructors 

	Particle (float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, float dumping);

private:

	// Attributes 

	float mass; // kg
	float inverseMass;
	Vector3D position; 
	Vector3D velocity;
	Vector3D acceleration;
	float dumping;

	// Private methods

	void UpdatePosition(const float& time);
	void UpdateVelocity(const float& time);

};

#endif
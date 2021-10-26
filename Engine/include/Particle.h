#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3D.h"

class Particle {

public :

	/// <summary>
	/// Give the particle's masse
	/// </summary>
	/// <returns> float : the particle's masse value </returns>
	float getMass() const { return m_mass; }

	/// <summary>
	/// Give the inverse value of the particle's masse
	/// </summary>
	/// <returns> float : the inverse value of the particle's masse </returns>
	float getInverseMass() const { return m_inverseMass; }

	/// <summary>
	/// Give the particle's position
	/// </summary>
	/// <returns> Vector3D : the particle's position </returns>
	Vector3D getPosition() const { return m_position; }

	/// <summary>
	/// Set the particle position to the one given in parameters
	/// </summary>
	/// <param name="position"> Vector3D : the wanted position </param>
	void setPosition(Vector3D position) { m_position = position; }

	/// <summary>
	/// Give the particle's position pointer
	/// </summary>
	/// <returns> Vector3D : the particle's position's pointer </returns>
	Vector3D* getPositionPtr() { return &m_position; }

	/// <summary>
	/// Give the particle velocity
	/// </summary>
	/// <returns>Vector3D : the particle's velocity </returns>
	Vector3D getVelocity() const { return m_velocity;  }

	/// <summary>
	/// Set the particel velocity to the one given in parameters
	/// </summary>
	/// <param name="velocity"> Vector3D : the wanted velocity </param>
	void setVelocity(Vector3D velocity) {m_velocity = velocity; }

	/// <summary>
	/// Give the particle's acceleration
	/// </summary>
	/// <returns>Vector3D : The particle's acceleration</returns>
	Vector3D getAcceleration() const { return m_acceleration; }

	/// <summary>
	/// Give the forces applicated to the particle
	/// </summary>
	/// <returns>Vector3D : the particle's forces </returns>
	Vector3D getAccumForces() const { return m_accumForces; }

	/// <summary>
	/// simulate the particle's physic by updating her position her velocity each call
	/// </summary>
	/// <param name="time"> float : the current time when the function is call</param>
	void integrate(float time);

	/// <summary>
	/// Add the vector value of a force that is applied on the particle to the forces already applyed on the particle
	/// </summary>
	/// <param name="force"> Vector3D: the force to add</param>
	void addForce(Vector3D force);

	/// <summary>
	/// Clear all the forces applied on the particle
	/// </summary>
	void clearForce();

	/// <summary>
	/// Ctor
	/// Create a personalize particle
	/// </summary>
	/// <param name="masse"> float : the particle's masse</param>
	/// <param name="position"> Vector3 : the particle's initial position </param>
	/// <param name="velocity"> Vector3 : the particle's initial velocity </param>
	/// <param name="acceleration">Vector3 : the particle's initial acceleration </param>
	/// <param name="forces"> Vector3D : the forces applied on the particle on the particle </param>
	Particle (float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, Vector3D forces);

private:

	// the particle's mass value in kg
	float m_mass;

	// the invert mass's value
	float m_inverseMass;

	// the particles position vector
	Vector3D m_position;

	// the particles velocity vector
	Vector3D m_velocity;

	// the particles acceleration vector
	Vector3D m_acceleration;

	// Implementation of all the forces applicate on the particle
	Vector3D m_accumForces;

	/// <summary>
	/// compute the particle's position depending on the time
	/// </summary>
	/// <param name="time"> float : the time when the function is call </param>
	/// <returns> Vector3 : the new particle's position </returns>
	void UpdatePosition(const float& time);

	/// <summary>
	/// compute the particle's velocity depending on the time
	/// </summary>
	/// <param name="time"> float : the time when the function is call </param>
	/// <returns> Vector3 : the new particle's velocity</returns>
	void UpdateVelocity(const float& time);

};

#endif
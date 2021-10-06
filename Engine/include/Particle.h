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
	/// <returns> float : the particle's position </returns>
	Vector3D getPosition() const { return m_position; }

	/// <summary>
	/// Give the particle's position pointer
	/// </summary>
	/// <returns> float : the particle's position's pointer </returns>
	Vector3D* getPositionPtr() { return &m_position; }

	/// <summary>
	/// simulate the particle's physic by updating her position her velocity each call
	/// </summary>
	/// <param name="time"> float : the current time when the function is call</param>
	void integrate(float time);

	/// <summary>
	/// Ctor
	/// Create a personalize particle
	/// </summary>
	/// <param name="masse"> float : the particle's masse</param>
	/// <param name="position"> Vector3 : the particle's initial position </param>
	/// <param name="velocity"> Vector3 : the particle's initial velocity </param>
	/// <param name="acceleration">Vector3 : the particle's initial acceleration </param>
	/// <param name="dumping"> float : the dumping that simulate frictions on the particle </param>
	Particle (float mass, Vector3D position, Vector3D velocity, Vector3D acceleration, float dumping);

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

	// the dumping value that simulate frictions
	float m_dumping;

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
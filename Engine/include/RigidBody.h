#pragma once

#include <list>
#include "Particle.h"
#include "MathTools/Vector3D.h"
#include "MathTools/Matrix3.h"
//#include "MathTools/Matrix4.h"
#include "MathTools/Quaternion.h"


class RigidBody
{
private:

	//List of the summits
	list<Vector3D> listSummit;

	// The rigid body's mass
	float m_mass;

	// The value of the inverse of the mass
	float m_inverseMass;

	// The rigid body's position
	Vector3D m_position;

	// The rigid body's linear velocity
	Vector3D m_linearVelocity;

	// The rigid body's angular velocity
	Vector3D m_angularVelocity;

	// The rigid body's orientation
	Quaternion m_orientation;

	// The rigid body's rotation
	Vector3D m_rotation;

	// The inversed matrix of inertia of the rigid body
	Matrix3 m_inverseInertiaTensor;

	// The sum of the forces applied to the rigid body during a fixed time (each frame for our game)
	Vector3D m_accumForce;

	// The sum of the torques applied to the rigid body during a fixed time (each frame for our game)
	Vector3D m_accumTorque;

	// The linear acceleration of the rigid body
	Vector3D m_linearAcceleration;

	// The angular acceleration of the rigid body
	Vector3D m_angularAcceleration;

	// The angular damping of the rigid body, that curbs the angular velocity
	float m_angularDamping;

public:

	/// <summary>
	/// Ctor
	/// Create a personnalized rigid body
	/// </summary>
	/// <param name="mass">rigid body's mass</param>
	/// <param name="position">rigid body's position</param>
	/// <param name="linearVelocity">rigid body's linear velocity</param>
	/// <param name="angularVelocity">rigid body's angular velocity</param>
	/// <param name="rotation">rigid body's rotation</param>
	/// <param name="orientation">rigid body's orientation</param>
	/// <param name="angularDamping">rigid body's angular damping</param>
	RigidBody(float mass, Vector3D position, Vector3D linearVelocity, Vector3D angularVelocity, Vector3D rotation, Quaternion orientation, float angularDamping);

	/// <summary>
	/// Sets the list of summits composing the rigid body
	/// </summary>
	/// <param name="summits"></param>
	void SetListSommet(list<Vector3D> summits) { listSummit = summits; }

	/// <summary>
	/// Returns the list of summits of the rigid body
	/// </summary>
	/// <returns>List of the position of each summit</returns>
	list<Vector3D> GetListSommet() { return listSummit; }

	/// <summary>
	/// Applies the force to a precise point of the rigid body
	/// </summary>
	/// <param name="force">the force applied to the rigid body</param>
	/// <param name="point">the position at which the force is applied</param>
	void addForceAtPoint(Vector3D force, Vector3D point);

	/// <summary>
	/// Applies the force from within the rigid body's referential
	/// </summary>
	/// <param name="force">the force applied (often due to a spring)</param>
	/// <param name="point">the position at which the force is applied</param>
	void addForceAtBodyPoint(Vector3D force, Vector3D point);

	/// <summary>
	/// Adds the force to the force accumulator of the rigid body
	/// </summary>
	/// <param name="force">the force to add</param>
	void forceAccumulator(Vector3D force);

	/// <summary>
	/// Adds the torque to the torque accumulator of the rigid body
	/// </summary>
	/// <param name="torque">the torque to add</param>
	void torqueAccumulator(Vector3D torque);

	/// <summary>
	/// Clears all accumulators of the rigid body
	/// </summary>
	void clearAccumulators();

	/// <summary>
	/// simulate the rigid body's physics by updating its movement attributes each call
	/// </summary>
	/// <param name="time"> float : the current time when the function is call</param>
	void updateValues(const float time);
};

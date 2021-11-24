#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <list>
#include "Particle.h"
#include "MathTools/Vector3D.h"
#include "MathTools/Matrix3.h"
#include "MathTools/Matrix4.h"
#include "MathTools/Quaternion.h"


class RigidBody
{
private:

	//List of the summits
	list<Vector3D> m_listSummit;

	float m_height;
	float m_width;
	float m_depth;

	// The rigid body's mass
	float m_mass;

	// The value of the inverse of the mass
	float m_inverseMass;

	// The rigid body's position
	Vector3D m_massCenter;

	// The rigid body's linear velocity
	Vector3D m_linearVelocity;

	// The rigid body's angular velocity, ie rotation
	Vector3D m_angularVelocity;

	// The rigid body's orientation
	Quaternion m_orientation;

	// The rigid body's first orientation
	Quaternion m_initialOrientation;

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

	//The linear damping of the rigid body, that curbs the linear velocity
	float m_linearDumping;

	// The angular damping of the rigid body, that curbs the angular velocity
	float m_angularDamping;

	// The matrix that allowed to convert vector from local to world and world to local
	Matrix4 m_transformMatrix;

public:

	/// Getter
	Vector3D GetMassCenter() { return m_massCenter; }
	float GetMass() { return m_mass; }

	float GetHeight() { return m_height; }

	float GetVolume();

	/// <param name="angularDamping">rigid body's angular damping</param>

	/// <summary>
	/// Create a personnalized rigid body
	/// </summary>
	/// <param name="height"> rigid body's height </param>
	/// <param name="width"> rigid body's width </param>
	/// <param name="depth"> rigid body's depth </param>
	/// <param name="mass">rigid body's mass</param>
	/// <param name="massCenter">rigid body's mass center's position</param>
	/// <param name="linearVelocity">rigid body's linear velocity</param>
	/// <param name="angularVelocity">rigid body's angular velocity</param>
	/// <param name="initialOrientation">rigid body's initial orientation</param>
	/// <param name="inertiaTensor">rigid body's inertia tensor</param>
	/// <param name="linearDumping">rigid body's linear damping</param>
	/// <param name="angularDamping">rigid body's angular damping</param>
	RigidBody(float height, float width, float depth, float mass, Vector3D massCenter, Vector3D linearVelocity, Vector3D angularVelocity, Quaternion initialOrientation, Matrix3 inertiaTensor, float linearDumping, float angularDamping);

	/// <summary>
	/// Sets the list of summits composing the rigid body
	/// </summary>
	/// <param name="summits"></param>
	void SetListSommet(list<Vector3D> summits) { m_listSummit = summits; }

	/// <summary>
	/// Returns the list of summits of the rigid body
	/// </summary>
	/// <returns>List of the position of each summit</returns>
	list<Vector3D> GetListSommet() { return m_listSummit; }

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

	/// <summary>
	/// Change the vector to his value from a local perspective to a world perspective
	/// </summary>
	/// <param name="vector"> Vector3D : The vector to change</param>
	/// <param name="transfoMatrix"> Matrix4 : The orientation matrix that allow us to compute the change</param>
	Vector3D LocalToWorld(Vector3D vector, Matrix3 transfoMatrix);

	/// <summary>
	/// Change the vector to his value from a world perspective to a local perspective
	/// </summary>
	/// <param name="vector"> Vector3D : The vector to change</param>
	/// <param name="transfoMatrix"> Matrix4 : The orientation matrix that allow us to compute the change</param>
	Vector3D WorldToLocal(Vector3D vector, Matrix4 transfoMatrix);
};

#endif

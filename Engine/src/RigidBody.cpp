#include "RigidBody.h"

RigidBody::RigidBody(float mass, Vector3D position, Vector3D linearVelocity, Vector3D angularVelocity, Vector3D rotation, Quaternion orientation, float angularDamping)
{
	m_mass = mass;
	m_inverseMass = 1 / mass;
	m_position = Vector3D(position);
	m_linearVelocity = Vector3D(linearVelocity);
	m_angularVelocity = Vector3D(angularVelocity);
	m_orientation = Quaternion(orientation);
	m_angularDamping = angularDamping;
}

void RigidBody::addForceAtPoint(Vector3D force, Vector3D point)
{
	// Modify the coordinates based on the mass center
	Vector3D contactPoint = m_position.subtract(point);

	forceAccumulator(force);

	Vector3D torque = force.crossProduct(contactPoint);
	torqueAccumulator(torque);
}

void RigidBody::addForceAtBodyPoint(Vector3D force, Vector3D point)
{
	//TODO apparemment surtout utilis� pour les ressorts
}

void RigidBody::forceAccumulator(Vector3D force)
{
	m_accumForce.add(force);
}

void RigidBody::torqueAccumulator(Vector3D torque)
{
	m_accumTorque.add(torque);
}

void RigidBody::clearAccumulators()
{
	m_accumForce.set(0, 0, 0);
	m_accumTorque.set(0, 0, 0);
}

void RigidBody::updateValues(const float time)
{
	m_linearAcceleration = m_accumForce * m_inverseMass;

	m_angularAcceleration = m_inverseInertiaTensor.multiplyByVector(m_accumTorque);

	// v' = new linear velocity
	// v = current linear velocity
	// a = linear acceleration
	// D = linear damping
	// v' = v + a.time
	Vector3D newLinearVelocity = m_linearVelocity + (m_linearAcceleration * time);
	m_linearVelocity.set(newLinearVelocity.getX(), newLinearVelocity.getY(), newLinearVelocity.getZ());

	// v' = new angular velocity
	// v = current angular velocity
	// a = angular acceleration
	// D = angular damping
	// v' = v + a.time
	Vector3D newAngularVelocity = (m_angularVelocity * powf(m_angularDamping, time)) + (m_angularAcceleration * time);
	m_angularVelocity.set(newAngularVelocity.getX(), newAngularVelocity.getY(), newAngularVelocity.getZ());
	
	//TODO add drag

	Vector3D newPosition = m_position + (m_linearVelocity * time);
	m_position.set(newPosition.getX(), newPosition.getY(), newPosition.getZ());

	Quaternion newOrientation = m_orientation.

	//TODO calculer les derived data

	clearAccumulators();
}
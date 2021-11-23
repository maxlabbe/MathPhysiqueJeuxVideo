#include "RigidBody.h"

RigidBody::RigidBody(list<Vector3D> listSummit, float mass, Vector3D massCenter, Vector3D linearVelocity, Vector3D angularVelocity, Quaternion initialOrientation, Matrix3 inertiaTensor, float linearDumping, float angularDamping)
	:m_listSummit(listSummit), m_mass(mass), m_inverseMass(1 / mass), m_massCenter(massCenter),
	m_linearVelocity(linearVelocity), m_angularVelocity(angularVelocity),
	m_orientation(initialOrientation),	m_initialOrientation(initialOrientation),
	m_inverseInertiaTensor(inertiaTensor.inverse()), m_accumForce(Vector3D(0,0,0)), m_accumTorque(Vector3D(0,0,0)), m_linearAcceleration(Vector3D(0,0,0)), m_angularAcceleration(Vector3D(0, 0, 0)),
	m_linearDumping(linearDumping), m_angularDamping(angularDamping), m_transformMatrix(Matrix4(m_orientation.ToMatrix3(), m_massCenter))
{
	for (auto vertex : m_listSummit)
	{
		vertex.LocalToWorld(m_transformMatrix);
	}
}

void RigidBody::addForceAtPoint(Vector3D force, Vector3D point)
{
	// Modify the coordinates based on the mass center
	point.WorldToLocal(m_transformMatrix);
	forceAccumulator(force);

	Vector3D torque = force.crossProduct(point);
	torqueAccumulator(torque);
}

void RigidBody::addForceAtBodyPoint(Vector3D force, Vector3D point)
{
	//Conver the local point to his worl coordinates
	point.LocalToWorld(m_transformMatrix);

	//Apply the force at this point
	addForceAtBodyPoint(force, point);
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
	Vector3D newLinearVelocity = m_linearVelocity * powf(m_linearDumping, time) + (m_linearAcceleration * time);
	m_linearVelocity.set(newLinearVelocity.getX(), newLinearVelocity.getY(), newLinearVelocity.getZ());

	// v' = new angular velocity
	// v = current angular velocity
	// a = angular acceleration
	// D = angular damping
	// v' = v + a.time
	Vector3D newAngularVelocity = (m_angularVelocity * powf(m_angularDamping, time)) + (m_angularAcceleration * time);
	m_angularVelocity.set(newAngularVelocity.getX(), newAngularVelocity.getY(), newAngularVelocity.getZ());

	Vector3D newPosition = m_massCenter + (m_linearVelocity * time);
	m_massCenter.set(newPosition.getX(), newPosition.getY(), newPosition.getZ());

	// We ant the angular velocity as a quaternion
	Quaternion angularVelocity(0, m_angularVelocity);

	// q'(t) = q(0) + 1/2 * angular_velocity * q(t) * t
	m_orientation = m_initialOrientation + 0.5 * angularVelocity.MultiplyByQuaternion(m_orientation) * time;

	//update all tools;
	Matrix3 inverseInertiaTensorInWorld(m_orientation.ToMatrix3().multiplyByMatrix(m_inverseInertiaTensor).multiplyByMatrix(m_orientation.ToMatrix3().inverse()));
	m_transformMatrix.setMatrix(Matrix4(m_orientation.ToMatrix3(), m_massCenter));

	// Update all object positions
	for (auto vertex : m_listSummit)
	{
		vertex = m_transformMatrix.multiplyByVector(vertex);
	}

	clearAccumulators();
}
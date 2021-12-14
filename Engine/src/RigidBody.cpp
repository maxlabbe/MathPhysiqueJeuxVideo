#include "RigidBody.h"

RigidBody::RigidBody(list<Vector3D> vertices, float mass, Vector3D massCenter, Vector3D linearVelocity, Vector3D angularVelocity, Quaternion initialOrientation, Matrix3 inertiaTensor, float linearDumping, float angularDamping)
	: m_mass(mass), m_inverseMass(1 / mass), m_massCenter(massCenter),
	m_linearVelocity(linearVelocity), m_angularVelocity(angularVelocity),
	m_orientation(initialOrientation), m_initialOrientation(initialOrientation),
	m_inverseInertiaTensor(inertiaTensor.inverse()), m_accumForce(Vector3D(0, 0, 0)), m_accumTorque(Vector3D(0, 0, 0)), m_linearAcceleration(Vector3D(0, 0, 0)), m_angularAcceleration(Vector3D(0, 0, 0)),
	m_linearDumping(linearDumping), m_angularDamping(angularDamping),
	m_listVertices(vertices)
{
	m_transformMatrix = Matrix4(m_orientation.ToMatrix3(), m_massCenter);
}

float RigidBody::GetVolume()
{
	return 0;
}

float RigidBody::GetMaxDimension()
{
	float dist = 0;
	for (Vector3D vertice : m_listVertices)
	{
		if (dist < m_massCenter.subtract(vertice).norm())
		{
			dist = m_massCenter.subtract(vertice).norm();
		}
	}

	return dist;
}

void RigidBody::addForceAtPoint(Vector3D force, Vector3D point)
{
	// Modify the coordinates based on the mass center
	point = WorldToLocal(point, m_transformMatrix);
	forceAccumulator(force);

	Vector3D torque = force.crossProduct(point);
	torqueAccumulator(torque);
}

void RigidBody::addForceAtBodyPoint(Vector3D force, Vector3D point)
{
	//Conver the local point to his world coordinates
	point = LocalToWorld(point, m_transformMatrix);

	//Apply the force at this point
	addForceAtBodyPoint(force, point);
}

void RigidBody::forceAccumulator(Vector3D force)
{
	m_accumForce = m_accumForce.add(force);
}

void RigidBody::torqueAccumulator(Vector3D torque)
{
	m_accumTorque = m_accumTorque.add(torque);
}

void RigidBody::clearAccumulators()
{
	m_accumForce.set(0, 0, 0);
	m_accumTorque.set(0, 0, 0);
}

void RigidBody::updateValues(const float time)
{
	m_linearAcceleration = m_accumForce * m_inverseMass;

	m_angularAcceleration = m_inverseInertiaTensor.multiplyMatrix3ByVector(m_accumTorque);


	// We ant the angular velocity as a quaternion
	Quaternion angularVelocity(0, m_angularVelocity);


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

	// q'(t) = q(0) + 1/2 * angular_velocity * q(t) * t
	m_orientation = m_orientation + 0.5 * angularVelocity.MultiplyByQuaternion(m_orientation) * time;

	Vector3D newPosition = m_massCenter + (m_linearVelocity * time);
	m_massCenter.set(newPosition.getX(), newPosition.getY(), newPosition.getZ());

	//update all tools;
	Matrix3 inverseInertiaTensorInWorld(m_orientation.ToMatrix3().multiplyByMatrix(m_inverseInertiaTensor).multiplyByMatrix(m_orientation.ToMatrix3().inverse()));
	m_inverseInertiaTensor = inverseInertiaTensorInWorld;
	m_transformMatrix.setMatrix(Matrix4(m_orientation.ToMatrix3(), m_massCenter));

	clearAccumulators();
}





Vector3D RigidBody::LocalToWorld(Vector3D vector, Matrix4 transfoMatrix)
{
	return transfoMatrix.multiplyMatrix4ByVector(vector);
}

Vector3D RigidBody::WorldToLocal(Vector3D vector, Matrix4 transfoMatrix)
{
	return transfoMatrix.inverse().multiplyMatrix4ByVector(vector);
}

list<Vector3D> RigidBody::GetWorldVertices()
{
	list<Vector3D> worldVertices;
	for (auto it = m_listVertices.begin(); it != m_listVertices.end(); it++)
	{
		Vector3D worldVertex = LocalToWorld(*it, m_transformMatrix);
		worldVertices.push_back(worldVertex);
	}
	return worldVertices;
}
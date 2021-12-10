#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include "Common.h"
#include "MathTools/Vector3D.h"
#include "RigidBody.h"

class BoundingSphere
{
public:

	// Getters
	Vector3D getCenter() const { return m_center; }

	float getRadius() const { return m_radius; }

	RigidBody* getRigidBody() const { return m_rigidBody; }

	/// <summary>
	/// Ctor
	/// Create a personnalize bounding sphere from a rigid body
	/// </summary>
	/// <param name="rigidBody"> RigidBody*: the pointer of the rigid body to which the bouding sphere belong </param>
	BoundingSphere(RigidBody* rigidBody);

protected:

	// center
	Vector3D m_center;

	// radius
	float m_radius;

	// rigid body
	RigidBody* m_rigidBody;
};

#endif

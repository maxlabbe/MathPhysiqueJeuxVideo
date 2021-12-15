#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include "Common.h"
#include "MathTools/Vector3D.h"
#include <Plane.h>

class BoundingSphere
{
public:

	// Getters
	Vector3D getCenter() const { return m_rigidBody->GetMassCenter(); }

	float getRadius() const { return m_radius; }

	RigidBody* getRigidBody() const { return m_rigidBody; }

	/// <summary>
	/// Ctor
	/// Create a personnalize bounding sphere from a rigid body
	/// </summary>
	/// <param name="rigidBody"> RigidBody*: the pointer of the rigid body to which the bouding sphere belong </param>
	BoundingSphere(RigidBody* rigidBody);

	/// <summary>
	/// Check if the two bounding spheres collide
	/// </summary>
	/// <param name="sphere"> BoundingSphere*: the other bounding sphere </param>
	/// <returns> Return true if the two bounding spheres collide, false if they don't </returns>
	bool collides(BoundingSphere* sphere);

	/// <summary>
	/// Check if the bounding sphere collides with a plane
	/// </summary>
	/// <param name="plane"> Plane*: the plane </param>
	/// <returns> Return true if the bounding sphere and the plane collide, false if they don't </returns>
	bool collides(Plane* plane);

protected:

	// radius
	float m_radius;

	// rigid body
	RigidBody* m_rigidBody;
};

#endif

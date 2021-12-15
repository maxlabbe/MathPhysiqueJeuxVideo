#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(RigidBody* rigidBody): m_radius(rigidBody->GetMaxDimension()), m_rigidBody(rigidBody) {}

bool BoundingSphere::collides(BoundingSphere* sphere)
{
	Vector3D center = m_rigidBody->GetMassCenter();
	float x = center.getX() - sphere->getCenter().getX();
	float y = center.getY() - sphere->getCenter().getY();
	float z = center.getZ() - sphere->getCenter().getZ();

	return sqrt(x * x + y * y + z * z) <= m_radius + sphere->getRadius();
}

bool BoundingSphere::collides(Plane* plane)
{
	return plane->GetDistance(m_rigidBody->GetMassCenter()) <= m_radius;
}

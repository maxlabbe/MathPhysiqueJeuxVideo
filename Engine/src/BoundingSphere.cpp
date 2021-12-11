#include "BoundingSphere.h"

BoundingSphere::BoundingSphere(RigidBody* rigidBody): m_center(rigidBody->GetMassCenter()), m_radius(rigidBody->GetMaxDimension()), m_rigidBody(rigidBody) {}

bool BoundingSphere::collides(BoundingSphere* sphere)
{
	float x = m_center.getX() - sphere->getCenter().getX();
	float y = m_center.getY() - sphere->getCenter().getY();
	float z = m_center.getZ() - sphere->getCenter().getZ();

	return sqrt(x * x + y * y + z * z) <= m_radius + sphere->getRadius();
}

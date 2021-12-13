#include "Box.h"

Box::Box(RigidBody* body, Matrix4 offset, Vector3D halfSizes) : Primitive(body, offset), m_halfSizes(halfSizes){}

float Box::GetVolume()
{
	return m_halfSizes.getX() * m_halfSizes.getY() * m_halfSizes.getY() * 8;
}

float Box::GetMaxDimension()
{
	return fmax(fmax(m_halfSizes.getX() * 2, m_halfSizes.getY()) * 2, m_halfSizes.getZ() * 2);
}
#include "Primitive.h"

Primitive::Primitive(RigidBody* body, Matrix4 offset) : m_body(body), m_offset(offset) {}

Vector3D Primitive::LocalToWorld(Vector3D point)
{
	return m_offset.multiplyMatrix4ByVector(point);
}

Vector3D Primitive::WorldToLocal(Vector3D point)
{
	return m_offset.inverse().multiplyMatrix4ByVector(point);
}


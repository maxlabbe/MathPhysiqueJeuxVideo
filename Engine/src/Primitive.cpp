#include "Primitive.h"

Primitive::Primitive(RigidBody* body, Matrix4 offset) : m_body(body), m_offset(offset) {}

Vector3D Primitive::LocalToWorld()
{
	return m_body->LocalToWorld(m_body->GetMassCenter(), m_offset);
}

Vector3D Primitive::WorldToLocal()
{
	return m_body->WorldToLocal(m_body->GetMassCenter(), m_offset);
}


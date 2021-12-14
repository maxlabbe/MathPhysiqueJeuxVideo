#include"Plane.h"

Plane::Plane(Vector3D normal, Vector3D position, Vector3D height, Vector3D width, float offset, Matrix4 transformMatrix)
	: Primitive(nullptr, transformMatrix), m_normal(normal), m_position(position), m_height(height), m_width(width), m_offset(offset){}

float Plane::GetDistance(Vector3D point)
{
	return m_normal.scalarProduct(point) + m_offset;
}

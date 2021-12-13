#pragma once
#include <Primitive.h>
class Box : public Primitive
{
public :
	Box(RigidBody* body, Matrix4 offset, Vector3D halfSizes);

	Vector3D GetHalfSizes() { return m_halfSizes; };

	float GetVolume();

	float GetMaxDimension();

private:
	Vector3D m_halfSizes;
};


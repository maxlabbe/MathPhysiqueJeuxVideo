#pragma once
#include <Primitive.h>
class Box : public Primitive
{
public :
	/// <summary>
	/// Ctor
	/// </summary>
	/// <param name="body">the rigid body to which the box is connected</param>
	/// <param name="offset">offset of the box compare to the rigidbody</param>
	/// <param name="halfSizes">the halfsizes of the box</param>
	Box(RigidBody* body, Matrix4 offset, Vector3D halfSizes);

	//Getters
	Vector3D GetHalfSizes() { return m_halfSizes; };
	float GetVolume();
	float GetMaxDimension();

private:
	// The halfsizes of the box
	Vector3D m_halfSizes;
};


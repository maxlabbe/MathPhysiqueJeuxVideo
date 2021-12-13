#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include <MathTools/Matrix4.h>
#include <RigidBody.h>
class Primitive
{
public :
	/// <summary>
	/// Ctor
	/// </summary>
	/// <param name="body">RigidBody* : rigidbody to which the primitive is connected</param>
	/// <param name="offset"> Matrix4 : the matrix that compute the position the primitive from the object perspective</param>
	Primitive(RigidBody* body, Matrix4 offset);

	RigidBody* GetRigidBody() { return m_body; };
	void MovePrimitive();

private:
	// body to which the primitive is connected
	RigidBody* m_body;

	// offset Matrix of the object
	Matrix4 m_offset;
};
#endif


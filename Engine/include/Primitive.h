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

	//Getter
	RigidBody* GetRigidBody() { return m_body; };

	/// <summary>
	/// Transform a vector from local to world
	/// </summary>
	/// <param name="point">the vector to transform</param>
	/// <returns>The vector's value in the world</returns>
	Vector3D LocalToWorld(Vector3D point);

	/// <summary>
	/// Transform a vector from world to local
	/// </summary>
	/// <param name="point">the vector to transform</param>
	/// <returns>The vector's value in local</returns>
	Vector3D WorldToLocal(Vector3D point);

protected:
	// body to which the primitive is connected
	RigidBody* m_body;

	// offset Matrix of the object
	Matrix4 m_offset;
};
#endif


#include <MathTools/Quaternion.h>

Quaternion::Quaternion(float w, float x, float y, float z) 
{
	m_quaternion = { w, x, y, z };
}

Quaternion::Quaternion(float w, Vector3D vector)
{
	Quaternion(w, vector.getX(), vector.getY(), vector.getZ());
}

Quaternion::Quaternion(array<float,4> quaternion)
{
	m_quaternion = quaternion;
}

Quaternion Quaternion::MultiplyByQuaternion(Quaternion q)
{
	Vector3D q1xyz(Get(1), Get(2), Get(3));
	Vector3D q2xyz(q.Get(1), q.Get(2), q.Get(3));
	Vector3D q1q2xyz = q1xyz.crossProduct(q2xyz);
	q1q2xyz = q1q2xyz + Get(0) * q2xyz + q.Get(0) * q1xyz;
	float q1q2w = Get(0) * q.Get(0) - q1xyz * q2xyz;
	return Quaternion(q1q2w, q1q2xyz.getX(), q1q2xyz.getY(), q1q2xyz.getZ());
}

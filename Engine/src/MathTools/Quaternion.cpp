#include <MathTools/Quaternion.h>

Quaternion::Quaternion(float w, float x, float y, float z) 
{
	m_quaternion = { w, x, y, z };
}

Quaternion::Quaternion(float w, Vector3D vector) : Quaternion(w, vector.getX(), vector.getY(), vector.getZ()) {}

Quaternion::Quaternion(array<float,4> quaternion)
{
	m_quaternion = quaternion;
}

Quaternion Quaternion::Identity()
{
	return Quaternion(1, 0, 0, 0);
}

float Quaternion::Norm() const
{
	float norm = 0.0f;
	for (int i = 0; i < m_quaternion.size(); i++)
	{
		norm += (m_quaternion[i] * m_quaternion[i]);
	}
	norm = sqrt(norm);
	return norm;
}

Quaternion Quaternion::MultiplyByQuaternion(Quaternion q) const
{
	Vector3D q1xyz(Get(1), Get(2), Get(3));
	Vector3D q2xyz(q.Get(1), q.Get(2), q.Get(3));
	Vector3D q1q2xyz = q1xyz.crossProduct(q2xyz);
	q1q2xyz = q1q2xyz + Get(0) * q2xyz + q.Get(0) * q1xyz;

	float q1q2w = Get(0) * q.Get(0) - q1xyz * q2xyz;

	return Quaternion(q1q2w, q1q2xyz.getX(), q1q2xyz.getY(), q1q2xyz.getZ());
}

Quaternion Quaternion::MultiplyByScalar(float s) const
{
	return Quaternion(s * Get(0), s * Get(1), s * Get(2), s * Get(3));
}

Quaternion Quaternion::Normalize() const
{
	float norm = Norm();
	if (norm != 0)
	{
		*this / norm;
	}
	return Quaternion(0, 0, 0, 0);
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(Get(0), -Get(1), -Get(2), -Get(3));
}

Quaternion Quaternion::Inverse() const
{
	return Conjugate() / Norm();
}

Matrix3 Quaternion::ToMatrix3() const
{
	array<array<float, 3>, 3> matrix = array<array<float, 3>, 3>();

	matrix[0] = { 1 - 2 * (Get(2) * Get(2) + Get(3) * Get(3)),	2 * (Get(1) * Get(2) + Get(3) * Get(0))	    , 2 * (Get(1) * Get(3) - Get(2) * Get(0)) };
	matrix[1] = { 2 * (Get(1) * Get(2) - Get(3) * Get(0))	 ,	1 - 2 * (Get(1) * Get(1) + Get(3) * Get(3)) , 2 * (Get(2) * Get(3) + Get(1) * Get(0)) };
	matrix[2] = { 2 * (Get(1) * Get(3) + Get(2) * Get(0))	 ,	2 * (Get(2) * Get(3) - Get(1) * Get(0))		, 1 - 2 * (Get(1) * Get(1) + Get(2) * Get(2)) };

	return Matrix3(matrix);
}

Quaternion operator*(const float& c, const Quaternion& q)
{
	return q.MultiplyByScalar(c);
}

Quaternion operator*(const Quaternion& q, const float& c)
{
	return q.MultiplyByScalar(c);
}

Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	return q1.MultiplyByQuaternion(q2);
}

Quaternion operator/(const Quaternion& q, const float& c)
{
	return Quaternion(q.Get(0) / c,  q.Get(1) / c,  q.Get(2) / c,  q.Get(3) / c);
}

Quaternion operator+(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.Get(0) + q2.Get(0), q1.Get(1) + q2.Get(1), q1.Get(2) + q2.Get(2), q1.Get(3) + q2.Get(3));
}

Quaternion operator-(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.Get(0) - q2.Get(0), q1.Get(1) - q2.Get(1), q1.Get(2) - q2.Get(2), q1.Get(3) - q2.Get(3));
}

std::ostream& operator<<(std::ostream& strm, const Quaternion& q)
{
	return strm << q.Get(0) << " + " << q.Get(1) << "i + " << q.Get(2) << "j + " << q.Get(3) << "k";
}

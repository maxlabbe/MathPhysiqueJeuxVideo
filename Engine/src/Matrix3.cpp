#include "Common.h"

#include "Matrix3.h"

Vector3D Matrix3::productVector(Vector3D vector)
{
	Vector3D result = Vector3D();
	float x = m_matrix[0][0] * vector.getX()+ m_matrix[0][1] * vector.getY() + m_matrix[0][2] * vector.getZ();
	float y = m_matrix[1][0] * vector.getX()+ m_matrix[1][1] * vector.getY() + m_matrix[1][2] * vector.getZ();
	float z = m_matrix[2][0] * vector.getX()+ m_matrix[2][1] * vector.getY() + m_matrix[2][2] * vector.getZ();
	vector.set(x, y, z);
	return result;
}

Matrix3 Matrix3::productMatrix(Matrix3 matrix)
{
	return Matrix3();
}

Matrix3 Matrix3::inverse()
{
	return Matrix3();
}

Matrix3 Matrix3::transpose()
{
	return Matrix3();
}

float Matrix3::determinant()
{
	return m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1]
		- m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2] + m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]
		+ m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0];
}

Matrix3::Matrix3()
{
}

Matrix3::Matrix3(array<array<float, 3>, 3> matrix)
{
}

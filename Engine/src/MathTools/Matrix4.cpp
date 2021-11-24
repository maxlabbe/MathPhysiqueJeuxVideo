#include "Common.h"

#include <MathTools/Matrix4.h>

Matrix4 Matrix4::multiplyByScalar(const float& c)
{
	array<array<float, 4>, 4> result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = c * m_matrix[i][j];
		}
	}

	return Matrix4(result);
}

Vector3D Matrix4::multiplyMatrix4ByVector(Vector3D vector)
{
	// Vector that will be returned
	Vector3D result = Vector3D();

	// Calculate the vector's components
	float x = m_matrix[0][0] * vector.getX() + m_matrix[0][1] * vector.getY() + m_matrix[0][2] * vector.getZ() + m_matrix[0][3];
	float y = m_matrix[1][0] * vector.getX() + m_matrix[1][1] * vector.getY() + m_matrix[1][2] * vector.getZ() + m_matrix[1][3];
	float z = m_matrix[2][0] * vector.getX() + m_matrix[2][1] * vector.getY() + m_matrix[2][2] * vector.getZ() + m_matrix[2][3];

	// Set the vector's component
	vector.set(x, y, z);

	return result;
}

Matrix4 Matrix4::multiplyByMatrix(Matrix4 matrix)
{
	// Get the array of the second matrix
	array<array<float, 4>, 4> secondMatrix = matrix.getMatrix();

	// Initialize variables
	array<array<float, 4>, 4> result;

	// Caculate each component of the result matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				result[i][j] += m_matrix[i][k] * secondMatrix[k][j];
			}
		}
	}

	return Matrix4(result);
}

Matrix4 Matrix4::inverse()
{
	float det = this->determinant();
	if (det == 0)
	{
		// Exception
	}
	else
	{
		array<array<float, 4>, 4> result;

		result[0] =
		{
			m_matrix[1][1] * m_matrix[2][2] - m_matrix[1][2] * m_matrix[2][1],
			m_matrix[0][2] * m_matrix[2][1] - m_matrix[0][1] * m_matrix[2][2],
			m_matrix[0][1] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1],
			m_matrix[0][3] * m_matrix[1][2] * m_matrix[2][1] + m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][3] + m_matrix[0][1] * m_matrix[1][3] * m_matrix[2][2] - m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][3] - m_matrix[0][2] * m_matrix[1][3] * m_matrix[2][1] - m_matrix[0][3] * m_matrix[1][1] * m_matrix[2][2]
		};

		result[1] =
		{
			m_matrix[1][2] * m_matrix[2][0] - m_matrix[1][0] * m_matrix[2][2],
			m_matrix[0][0] * m_matrix[2][2] - m_matrix[0][2] * m_matrix[2][0],
			m_matrix[0][2] * m_matrix[1][0] - m_matrix[0][0] * m_matrix[1][2],
			m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][3] + m_matrix[0][2] * m_matrix[1][3] * m_matrix[2][0] + m_matrix[0][3] * m_matrix[1][0] * m_matrix[2][2] - m_matrix[0][3] * m_matrix[1][2] * m_matrix[2][0] - m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][3] - m_matrix[0][0] * m_matrix[1][3] * m_matrix[2][2]
		};

		result[2] =
		{
			m_matrix[1][0] * m_matrix[2][1] - m_matrix[1][1] * m_matrix[2][0],
			m_matrix[0][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[2][1],
			m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0],
			m_matrix[0][3] * m_matrix[1][1] * m_matrix[2][0] + m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][3] + m_matrix[0][0] * m_matrix[1][3] * m_matrix[2][1] - m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][3] - m_matrix[0][1] * m_matrix[1][3] * m_matrix[2][0] - m_matrix[0][3] * m_matrix[1][0] * m_matrix[2][1]
		};

		result[3] = { 0, 0, 0, det };

		return Matrix4(result).multiplyByScalar(1.0 / det);
	}
}

/* Matrix transpose not used
Matrix4 Matrix4::transpose()
{
	array<array<float, 3>, 3> result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = m_matrix[j][i];
		}
	}

	return Matrix4(result);
}
*/

float Matrix4::determinant()
{
	return - (m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1]
		- m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2] + m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]
		+ m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0]);
}

Matrix4::Matrix4()
{
	m_matrix[0] = { 1, 0, 0, 0 };
	m_matrix[1] = { 0, 1, 0, 0 };
	m_matrix[2] = { 0, 0, 1, 0 };
	m_matrix[3] = { 0, 0, 0, 1 };
}

Matrix4::Matrix4(array<array<float, 4>, 4> matrix) : m_matrix(matrix)
{
}

Matrix4::Matrix4(array<array<float, 4>, 3> matrix)
{
	array<array<float, 4>, 4> result;

	result[0] = matrix[0];
	result[1] = matrix[1];
	result[2] = matrix[2];
	result[3] = { 0, 0, 0, 1 };

	m_matrix = result;
}

Matrix4::Matrix4(Matrix3 matrix, Vector3D vector)
{
	array<array<float, 4>, 4> result;
	array<array<float, 3>, 3> secondMatrix = matrix.getMatrix();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = m_matrix[i][j];
		}
	}

	result[0][3] = vector.getX();
	result[1][3] = vector.getY();
	result[2][3] = vector.getZ();

	result[3] = { 0, 0, 0, 1 };

	m_matrix = result;
}

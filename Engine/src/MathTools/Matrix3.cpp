#include "Common.h"

#include <MathTools/Matrix3.h>

Matrix3 Matrix3::multiplyByScalar(const float& c)
{
	array<array<float, 3>, 3> result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = c * m_matrix[i][j];
		}
	}

	return Matrix3(result);
}

Vector3D Matrix3::multiplyMatrix3ByVector(Vector3D vector)
{
	// Vector that will be returned
	Vector3D result = Vector3D();

	// Calculate the vector's components
	float x = m_matrix[0][0] * vector.getX()+ m_matrix[0][1] * vector.getY() + m_matrix[0][2] * vector.getZ();
	float y = m_matrix[1][0] * vector.getX()+ m_matrix[1][1] * vector.getY() + m_matrix[1][2] * vector.getZ();
	float z = m_matrix[2][0] * vector.getX()+ m_matrix[2][1] * vector.getY() + m_matrix[2][2] * vector.getZ();
	
	// Set the vector's component
	result.set(x, y, z);

	return result;
}

Matrix3 Matrix3::multiplyByMatrix(Matrix3 matrix)
{
	// Get the array of the second matrix
	array<array<float, 3>, 3> secondMatrix = matrix.getMatrix();


	// Initialize variables
	array<array<float, 3>, 3> result;

	// Caculate each component of the result matrix
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				result[i][j] += m_matrix[i][k] * secondMatrix[k][j];
			}
		}
	}

	return Matrix3(result);
}

Matrix3 Matrix3::inverse()
{
	float det = this->determinant();
	if (det == 0)
	{
		// Exception
	}
	else
	{
		array<array<float, 3>, 3> result;

		result[0] =
		{
			m_matrix[1][1] * m_matrix[2][2] - m_matrix[1][2] * m_matrix[2][1],
			m_matrix[0][2] * m_matrix[2][1] - m_matrix[0][1] * m_matrix[2][2],
			m_matrix[0][1] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1]
		};

		result[1] =
		{
			m_matrix[1][2] * m_matrix[2][0] - m_matrix[1][0] * m_matrix[2][2],
			m_matrix[0][0] * m_matrix[2][2] - m_matrix[0][2] * m_matrix[2][0],
			m_matrix[0][2] * m_matrix[1][0] - m_matrix[0][0] * m_matrix[1][2]
		};

		result[2] =
		{
			m_matrix[1][0] * m_matrix[2][1] - m_matrix[1][1] * m_matrix[2][0],
			m_matrix[0][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[2][1],
			m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0]
		};

		return Matrix3(result).multiplyByScalar(1.0/det);
	}
}

Matrix3 Matrix3::transpose()
{
	array<array<float, 3>, 3> result;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = m_matrix[j][i];
		}
	}

	return Matrix3(result);
}

float Matrix3::determinant()
{
	return m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1]
		- m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2] + m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]
		+ m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0];
}

Matrix3::Matrix3()
{
	m_matrix[0] = { 1, 0, 0 };
	m_matrix[1] = { 0, 1, 0 };
	m_matrix[2] = { 0, 0, 1 };
}

Matrix3::Matrix3(array<array<float, 3>, 3> matrix) : m_matrix(matrix)
{
}

#include <OrientationMatrix.h>

OrientationMatrix::OrientationMatrix()
	: OrientationMatrix(0, 0, 0, 0, 0, 0) {}

OrientationMatrix::OrientationMatrix(float p1, float q1, float r1, float p2, float q2, float r2)
{
	m_matrix[0][0] = p1 * p2;
	m_matrix[0][1] = q1 * p2;
	m_matrix[0][2] = r1 * p2;

	m_matrix[1][0] = p1 * q2;
	m_matrix[1][1] = q1 * q2;
	m_matrix[1][2] = r1 * q2;

	m_matrix[2][0] = p1 * r2;
	m_matrix[2][1] = q1 * r2;
	m_matrix[2][2] = r1 * r2;
}

OrientationMatrix::~OrientationMatrix() {}

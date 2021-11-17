#ifndef MATRIX4_H
#define MATRIX4_H

#include "Common.h"
#include "Vector3D.h"
#include "Matrix3.h"

#include <array>

class Matrix4
{
public:

	// Getter
	array<array<float, 4>, 4> getMatrix() const { return m_matrix; }

	// Setter
	void setMatrix(array<array<float, 4>, 4> matrix) { m_matrix = matrix; }

	Matrix4 multiplyByScalar(const float& c);
	Vector3D multiplyByVector(Vector3D vector);
	Matrix4 multiplyByMatrix(Matrix4 matrix);
	Matrix4 inverse();
	//Matrix4 transpose();
	float determinant();

	Matrix4();
	Matrix4(array<array<float, 4>, 4> matrix);
	Matrix4(array<array<float, 4>, 3> matrix);
	Matrix4(Matrix3 matrix, Vector3D vector);

protected:

	// matrix
	array<array<float, 4>, 4> m_matrix;
};

#endif

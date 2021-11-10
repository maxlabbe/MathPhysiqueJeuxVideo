#ifndef MATRIX3_H
#define MATRIX3_H

#include "Common.h"
#include "Vector3D.h"

#include <array>

class Matrix3
{
public:

	// Getter
	array<array<float, 3>, 3> getMatrix() const { return m_matrix; }

	// Setter
	void setMatrix(array<array<float, 3>, 3> matrix) { m_matrix = matrix; }

	Vector3D productVector(Vector3D vector);
	Matrix3 productMatrix(Matrix3 matrix);
	Matrix3 inverse();
	Matrix3 transpose();
	float determinant();

	Matrix3();
	Matrix3(array<array<float, 3>, 3> matrix);

private:
	
	// matrix
	array<array<float, 3>, 3> m_matrix;
};

#endif

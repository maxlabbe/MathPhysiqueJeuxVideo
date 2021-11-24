#ifndef MATRIX3_H
#define MATRIX3_H

#include "Common.h"
#include "MathTools/Vector3D.h"

#include <array>

class Matrix3
{
public:

	// Getter
	array<array<float, 3>, 3> getMatrix() const { return m_matrix; }

	// Setter
	void setMatrix(array<array<float, 3>, 3> matrix) { m_matrix = matrix; }

	/// <summary>
	/// multiply the matrix by a scalar
	/// </summary>
	/// <param name="c"> float : the scalar that multiply the matrix </param>
	/// <returns> Matrix3 : the new scaled matrix </returns>
	Matrix3 multiplyByScalar(const float& c);
	
	/// <summary>
	/// multiply the matrix by a given vector
	/// </summary>
	/// <param name="vector"> Vector3D : the vector that multiply the matrix </param>
	/// <returns> Vector3D : the new vector </returns>
	Vector3D multiplyMatrix3ByVector(Vector3D vector);
	
	/// <summary>
	/// multiply the matrix by an other matrix
	/// </summary>
	/// <param name="matrix"> float : the other matrix that multiply the matrix </param>
	/// <returns> Matrix3 : the new matrix </returns>
	Matrix3 multiplyByMatrix(Matrix3 matrix);
	
	/// <summary>
	/// compute the inverse of the matrix
	/// </summary>
	/// <returns> Matrix3 : the inversed matrix </returns>
	Matrix3 inverse();
	
	/// <summary>
	/// compute the transpose of the matrix
	/// </summary>
	/// <returns> Matrix3 : the transposed matrix </returns>
	Matrix3 transpose();
	
	/// <summary>
	/// compute the determinant of the matrix
	/// </summary>
	/// <returns> float : the determinant of the matrix </returns>
	float determinant();

	/// <summary>
	/// Ctor
	/// Create the identity matrix
	/// </summary>
	Matrix3();
	
	/// <summary>
	/// Ctor
	/// Create a personnalize matrix
	/// </summary>
	/// <param name="matrix"> the array of the matrix </param>
	Matrix3(array<array<float, 3>, 3> matrix);

protected:
	
	// matrix
	array<array<float, 3>, 3> m_matrix;
};

#endif

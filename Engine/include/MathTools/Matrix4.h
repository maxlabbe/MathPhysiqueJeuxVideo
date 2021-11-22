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

	/// <summary>
	/// multiply the matrix by a scalar
	/// </summary>
	/// <param name="c"> float : the scalar that multiply the matrix </param>
	/// <returns> Matrix4 : the new scaled matrix </returns>
	Matrix4 multiplyByScalar(const float& c);
	
	/// <summary>
	/// multiply the matrix by a given vector
	/// </summary>
	/// <param name="vector"> Vector3D : the vector that multiply the matrix </param>
	/// <returns> Vector3D : the new vector </returns>
	Vector3D multiplyByVector(Vector3D vector);
	
	/// <summary>
	/// multiply the matrix by an other matrix
	/// </summary>
	/// <param name="matrix"> Matrix4 : the other matrix that multiply the matrix </param>
	/// <returns> Matrix4 : the new matrix </returns>
	Matrix4 multiplyByMatrix(Matrix4 matrix);
	
	/// <summary>
	/// compute the inverse of the matrix
	/// </summary>
	/// <returns> Matrix4 : the inversed matrix </returns>
	Matrix4 inverse();
	
	/// the transposed matrix is not needed for Matrix4
	//Matrix4 transpose();
	
	/// <summary>
	/// compute the determinant of the matrix
	/// </summary>
	/// <returns> float : the determinant of the matrix </returns>
	float determinant();

	/// <summary>
	/// Ctor
	/// Create the identity matrix
	/// </summary>
	Matrix4();
	
	/// <summary>
	/// Ctor
	/// Create a personnalize matrix
	/// </summary>
	/// <param name="matrix"> the array of the matrix </param>
	Matrix4(array<array<float, 4>, 4> matrix);
	
	/// <summary>
	/// Ctor
	/// Create a personnalize matrix from an array 3x4
	/// </summary>
	/// <param name="matrix"> the array for the matrix </param>
	Matrix4(array<array<float, 4>, 3> matrix);
	
	/// <summary>
	/// Ctor
	/// Create a personnalize matrix from a Matrix3 and a Vector3D
	/// </summary>
	/// <param name="matrix"> the Matrix3 </param>
	/// <param name="vector"> the Vector3D </param>
	Matrix4(Matrix3 matrix, Vector3D vector);

protected:

	// matrix
	array<array<float, 4>, 4> m_matrix;
};

#endif

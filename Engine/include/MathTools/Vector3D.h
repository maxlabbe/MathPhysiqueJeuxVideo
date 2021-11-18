#ifndef VECTOR3D_H
#define VECTOR3D_H

#include"Common.h"
#include <MathTools/Matrix3.h>

class Vector3D {

public:

	// Getters

	float getX() const { return m_x; }
	float getY() const { return m_y; }
	float getZ() const { return m_z; }

	void set(float x, float y, float z);

	/// <summary>
	/// Give the vector's squarre norm
	/// </summary>
	/// <returns> float : the vector's squarre norm </returns>
	float norm() const;

	/// <summary>
	/// Give the vector's norm
	/// </summary>
	/// <returns>float : the vector's norm</returns>
	float squaredNorm() const;

	/// <summary>
	/// Give the normalized vector
	/// </summary>
	/// <returns> Vector3 : the normalized vector </returns>
	Vector3D normalize() const;

	/// <summary>
	/// multiply the vector by a given scalar
	/// </summary>
	/// <param name="scalar"> float : the scalar that multiply the vector </param>
	/// <returns> Vector3 : the new scaled vector </returns>
	Vector3D multiplyByScalar(const float&) const;

	/// <summary>
	/// The operator +
	/// </summary>
	/// <param name="vector"> Vector3 : the vector you want to add </param>
	/// <returns> Vector3 : the addition's result vector </returns>
	Vector3D add(const Vector3D&) const;

	/// <summary>
	/// The operator -
	/// </summary>
	/// <param name="vector">Vector3 : the vector you want to substract </param>
	/// <returns> Vector3 : the substraction's result vector </returns>
	Vector3D subtract(const Vector3D&) const;

	/// <summary>
	/// Give the product between each component of the vector and these of the given one
	/// </summary>
	/// <param name="vector"> Vector3 : the given vector </param>
	/// <returns> Vector3 : the product's result </returns>
	Vector3D elementWiseProduct(const Vector3D&) const;

	/// <summary>
	/// Give the scalar product beteen the vector and a given one
	/// </summary>
	/// <param name="vector"> Vector3 : the given vector </param>
	/// <returns> float : the scalar product's result </returns>
	float scalarProduct(const Vector3D&) const;

	/// <summary>
	/// Give the product between the vector and a given one
	/// </summary>
	/// <param name="vector"> Vector3 : the given vector </param>
	/// <returns> Vector3 : the vector product's result </returns>
	Vector3D crossProduct(const Vector3D&) const;

	//
	void LocalToWorld(Matrix3 transfoMatrix);

	void WorldToLocal();

	// Operator overloads
	// * = multiply a vector by a scalar or scalar product of two vectors
	// / = divide by a vector by a scalar
	// + = add two vectors
	// - = substract two vectors

	friend Vector3D operator*(const float&, const Vector3D&);
	friend Vector3D operator*(const Vector3D&, const float&);
	friend float operator*(const Vector3D&, const Vector3D&);
	friend Vector3D operator/(const Vector3D&, const float&);
	friend Vector3D operator+(const Vector3D&, const Vector3D&);
	friend Vector3D operator-(const Vector3D&, const Vector3D&);
	friend std::ostream& operator<<(std::ostream&, const Vector3D&);

	/// <summary>
	/// Ctor
	/// x, y, z = 0
	/// </summary>
	Vector3D();

	/// <summary>
	/// Ctor
	/// Create a personnalize vector
	/// </summary>
	/// <param name="x"> the x value </param>
	/// <param name="y"> the y value </param>
	/// <param name="z"> the z value </param>
	Vector3D(float x, float y, float z);

private:

	// x coordonate
	float m_x;

	// y coordonate
	float m_y;

	// z coordonate
	float m_z;

};

#endif

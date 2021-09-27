#ifndef VECTOR3D_H
#define VECTOR3D_H

#include"Common.h"

class Vector3D {

public:

	// Getters

	float getX() const { return x; }
	float getY() const { return y; }
	float getZ() const { return z; }

	// Setter

	void set(float x, float y, float z);

	// Public methods

	float norm() const;
	float squaredNorm() const;
	Vector3D normalize() const;
	Vector3D multiplyByScalar(const float&) const;
	Vector3D add(const Vector3D&) const;
	Vector3D subtract(const Vector3D&) const;
	Vector3D elementWiseProduct(const Vector3D&) const;
	float scalarProduct(const Vector3D&) const;
	Vector3D crossProduct(const Vector3D&) const;

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

	// Constructors

	Vector3D();
	Vector3D(float x, float y, float z);

private:

	float x;
	float y;
	float z;

};

#endif

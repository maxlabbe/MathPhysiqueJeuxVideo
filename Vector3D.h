#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {

public:

	// Getters

	float getX() const;
	float getY() const;
	float getZ() const;

	// Public methods

	float norm() const;
	float squaredNorm() const;
	Vector3D normalize() const;
	Vector3D elementWiseProduct(const Vector3D&) const;
	float scalarProduct(const Vector3D&) const;
	Vector3D crossProduct(const Vector3D&) const;

	// Operator overloads

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

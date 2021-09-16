#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {

private:

	double x;
	double y;
	double z;

public:

	// Getters

	double getX() const;
	double getY() const;
	double getZ() const;

	// Public methods

	double norm() const;
	double squaredNorm() const;
	Vector3D normalize() const;
	Vector3D elementWiseProduct(const Vector3D&) const;
	double scalarProduct(const Vector3D&) const;
	Vector3D crossProduct(const Vector3D&) const;

	// Operator overloads

	friend Vector3D operator*(const double&, const Vector3D&);
	friend Vector3D operator*(const Vector3D&, const double&);
	friend double operator*(const Vector3D&, const Vector3D&);
	friend Vector3D operator/(const Vector3D&, const double&);
	friend Vector3D operator+(const Vector3D&, const Vector3D&);
	friend Vector3D operator-(const Vector3D&, const Vector3D&);
	friend std::ostream& operator<<(std::ostream&, const Vector3D&);

	// Constructors

	Vector3D();
	Vector3D(double x, double y, double z);

};

#endif

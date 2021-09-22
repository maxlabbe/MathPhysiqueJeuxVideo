#include <math.h>
#include <iostream>

#include "Vector3D.h"

// Getters 

float Vector3D::getX() const { return x; }
float Vector3D::getY() const { return y; }
float Vector3D::getZ() const { return z; }

// Public methods

float Vector3D::norm() const {
	return sqrt(this->squaredNorm());
}

float Vector3D::squaredNorm() const {
	return x * x + y * y + z * z;
}

Vector3D Vector3D::normalize() const {
	float norm = this->norm();
	return *this / norm;
}

Vector3D Vector3D::elementWiseProduct(const Vector3D& v) const {
	return Vector3D(x * v.getX(), y * v.getY(), z * v.getZ());
}

float Vector3D::scalarProduct(const Vector3D& v) const {
	return x * v.getX() + y * v.getY() + z * v.getZ();
}

Vector3D Vector3D::crossProduct(const Vector3D& v) const {
	return Vector3D(
		y * v.getZ() - z * v.getY(),
		z * v.getX() - x * v.getZ(),
		x * v.getY() - y * v.getX()
	);
}

// Operator overloads

Vector3D operator*(const float& c, const Vector3D& v) {
	return Vector3D(c * v.getX(), c * v.getY(), c * v.getZ());
}

Vector3D operator*(const Vector3D& v, const float& c) {
	return Vector3D(c * v.getX(), c * v.getY(), c * v.getZ());
}

float operator*(const Vector3D& v1, const Vector3D& v2) {
	return v1.scalarProduct(v2);
}

Vector3D operator/(const Vector3D& v, const float& c) {
	return Vector3D(v.getX() / c, v.getY() / c, v.getZ() / c);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
	return Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
	return Vector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

std::ostream& operator<<(std::ostream& strm, const Vector3D& v) {
	return strm << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}

// Constructors

Vector3D::Vector3D() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
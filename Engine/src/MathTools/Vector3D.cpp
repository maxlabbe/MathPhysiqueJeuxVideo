#include "Common.h"

#include <MathTools/Vector3D.h>

void Vector3D::set(float x, float y, float z)
{
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}

float Vector3D::norm() const 
{
	// norm = squarre root (x² + y² + z²)
	return sqrt(this->squaredNorm());
}

float Vector3D::squaredNorm() const 
{
	// norm² = x² + y² + z²
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

Vector3D Vector3D::normalize() const 
{
	// Normalize a vector is equal to multiply it by his norme inverse
	float norm = this->norm();
	if (norm != 0)
	{
		return *this / norm;
	}

	return Vector3D();
	
}

Vector3D Vector3D::multiplyByScalar(const float& c) const
{
	// multiplying a vector by a scalar N is equal to multiply each components of the vector by N
	return Vector3D(c * m_x, c * m_y, c * m_z);
}

Vector3D Vector3D::add(const Vector3D& v) const
{
	// add two vector is equal to add each vectors's components
	return Vector3D(m_x + v.getX(), m_y + v.getY(), m_z + v.getZ());
}

Vector3D Vector3D::subtract(const Vector3D& v) const
{
	// substract two vector is equal to substract each vectors's components
	return Vector3D(m_x - v.getX(), m_y - v.getY(), m_z - v.getZ());
}

Vector3D Vector3D::elementWiseProduct(const Vector3D& v) const 
{
	// The product by component is the product between each vectors's components
	return Vector3D(m_x * v.getX(), m_y * v.getY(), m_z * v.getZ());
}

float Vector3D::scalarProduct(const Vector3D& v) const 
{
	// V1(x,y,z) V2(a,b,c)
	// scalar product = x.a + y.b + z.c)
	return m_x * v.getX() + m_y * v.getY() + m_z * v.getZ();
}

Vector3D Vector3D::crossProduct(const Vector3D& v) const 
{
	// V1(x,y,z) V2(a,b,c)
	// vector product(y*c - z*b, z*a - x*c, x*b - y*a)
	return Vector3D(m_y * v.getZ() - m_z * v.getY(), m_z * v.getX() - m_x * v.getZ(), m_x * v.getY() - m_y * v.getX());
}

void Vector3D::LocalToWorld(Matrix3 transfoMatrix)
{
	*this = transfoMatrix.multiplyByVector(*this);
}

void Vector3D::WorldToLocal(Matrix3 transfoMatrix)
{
	*this = transfoMatrix.inverse().multiplyByVector(*this);
}

Vector3D operator*(const float& c, const Vector3D& v) 
{
	return Vector3D(c * v.getX(), c * v.getY(), c * v.getZ());
}

Vector3D operator*(const Vector3D& v, const float& c) 
{
	return Vector3D(c * v.getX(), c * v.getY(), c * v.getZ());
}

float operator*(const Vector3D& v1, const Vector3D& v2) 
{
	return v1.scalarProduct(v2);
}

Vector3D operator/(const Vector3D& v, const float& c) 
{
	return Vector3D(v.getX() / c, v.getY() / c, v.getZ() / c);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) 
{
	return Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2) 
{
	return Vector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

std::ostream& operator<<(std::ostream& strm, const Vector3D& v) 
{
	return strm << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}

Vector3D::Vector3D() : m_x(0), m_y(0), m_z(0)
{
}

Vector3D::Vector3D(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
{
}
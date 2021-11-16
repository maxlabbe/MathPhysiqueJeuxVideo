#ifndef QUATERNION_H
#define QUATERNION_H

#include <Common.h>
#include <MathTools/Vector3D.h>
#include <MathTools/Matrix3.h>
#include <array>

class Quaternion
{
public :

	/* Constructeurs */
	Quaternion(float w, float x, float y, float z);
	Quaternion(float w, Vector3D vector);
	Quaternion(array<float, 4> quaternion);

	static Quaternion Identity();

	float Norm() const;

	Quaternion MultiplyByQuaternion(Quaternion q) const;
	Quaternion Normalize() const;
	Quaternion Conjugate() const;
	Quaternion Inverse() const;
	Matrix3 ToMatrix3() const;

	friend Quaternion operator*(const float&, const Quaternion&);
	friend Quaternion operator*(const Quaternion&, const float&);
	friend Quaternion operator*(const Quaternion&, const Quaternion&);
	friend Quaternion operator/(const Quaternion&, const float&);
	friend Quaternion operator+(const Quaternion&, const Quaternion&);
	friend Quaternion operator-(const Quaternion&, const Quaternion&);
	friend std::ostream& operator<<(std::ostream&, const Quaternion&);

	// Getter
	float Get(int index) const { return m_quaternion[index]; }

private :

	array<float, 4> m_quaternion;
};

#endif
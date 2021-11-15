#ifndef QUATERNION_H
#define QUATERNION_H

#include <Common.h>
#include <MathTools/Vector3D.h>
#include <array>

class Quaternion
{
public :

	/* Constructeurs */
	Quaternion(float w, float x, float y, float z);
	Quaternion(float w, Vector3D vector);
	Quaternion(array<float, 4> quaternion);

	Quaternion MultiplyByQuaternion(Quaternion q);

	// Getter
	float Get(int index) { return m_quaternion[index]; }

private :

	array<float, 4> m_quaternion;
};

#endif
#pragma once
#include <MathTools/Vector3D.h>
#include <RigidBody.h>
class Contact
{
public:
	Contact(Vector3D contactPoint, Vector3D normal, float interpenetration);

	Vector3D GetContactPoint() { return m_contactPoint; };
	Vector3D GetNormal() { return m_normal; };
	float GetInterpenetration() { return m_interpenetration; };

	void DisplayContact();

private:
	Vector3D m_contactPoint;
	Vector3D m_normal;
	float m_interpenetration;
};


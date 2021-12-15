#pragma once
#include <MathTools/Vector3D.h>
#include <RigidBody.h>
class Contact
{
public:
	/// <summary>
	/// Ctor
	/// </summary>
	/// <param name="contactPoint">the contcat point</param>
	/// <param name="normal">the normal at the contact point</param>
	/// <param name="interpenetration">the interpenetration of the object in the other</param>
	Contact(Vector3D contactPoint, Vector3D normal, float interpenetration);

	//Getters
	Vector3D GetContactPoint() { return m_contactPoint; };
	Vector3D GetNormal() { return m_normal; };
	float GetInterpenetration() { return m_interpenetration; };

	/// <summary>
	/// Display the information of the contact
	/// </summary>
	void DisplayContact();

private:
	//Contact point
	Vector3D m_contactPoint;
	
	// Normal at the contact point
	Vector3D m_normal;

	// interpenetration between the objects
	float m_interpenetration;
};


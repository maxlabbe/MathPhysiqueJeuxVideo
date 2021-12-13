#include "Contact.h"

Contact::Contact(Vector3D contactPoint, Vector3D normal, float interpenetration) :
	m_contactPoint(contactPoint), m_normal(normal), m_interpenetration(interpenetration){}

void Contact::DisplayContact()
{
	cout << "contact point : " << m_contactPoint << endl;
	cout << "normal : " << m_normal << endl;
	cout << "interpenetration : " << m_interpenetration << endl;
}

#include "RB_BungeeGenerator.h"

void RB_BungeeGenerator::updateForce(RigidBody* rigidBody, Vector3D* apllicationPoint, float duration)
{
	// l is the spring stretching so the distance beetween the two application points
	Vector3D distance = *apllicationPoint - m_applicationPoint;

	// The elastic do something only when it's tense
	//That mean the distance beetween the application points are bigger than the elastic's rest size
	if (distance.norm() > m_l0)
	{
		// Now we compute the value of the force add it to the particle
		// To compute the force we calculate the force's value and apply it to the distance's unit vector
		//F = k(l0 - l)
		rigidBody->addForceAtPoint(distance.normalize() * (m_k * (m_l0 - distance.norm())), *apllicationPoint);
	}
}

#include "RB_BungeeGenerator.h"

void RB_BungeeGenerator::updateForce(RigidBody* rigidBody, Vector3D* apllicationPoint, float duration)
{
	// l is the spring stretching so the distance beetween the two particles
	Vector3D distance = *apllicationPoint - m_applicationPoint;

	if (distance.norm() > m_l0)
	{
		rigidBody->addForceAtPoint(distance.normalize() * (m_k * (m_l0 - distance.norm())), *apllicationPoint);
	}
}

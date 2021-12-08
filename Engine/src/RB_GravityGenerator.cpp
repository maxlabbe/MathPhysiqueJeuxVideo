#include <RB_GravityGenerator.h>

// Apply the reel value of gravity as default value
RB_GravityGenerator::RB_GravityGenerator() : m_gravityVector(Vector3D(0, -9.81f, 0)) {}
RB_GravityGenerator::RB_GravityGenerator(float gravityValue) : m_gravityVector(Vector3D(0, -gravityValue, 0)) {}

void RB_GravityGenerator::updateForce(RigidBody* rigidBody, float duration, Vector3D* appicationPoint)
{
	// Apply the gravity force to the rigid body if the mass isn't nul
	float mass = rigidBody->GetMass();
	if (mass != 0)
	{
		rigidBody->addForceAtPoint(m_gravityVector.multiplyByScalar(mass), rigidBody->GetMassCenter());
	}
}

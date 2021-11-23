#ifndef RB_SPRINGGENERATOR_H
#define RB_SPRINGGENERATOR_H
#include <RB_ForceGenerator.h>
#include <ParticleSpring.h>

class RB_SpringGenerator : public IRB_ForceGenerator
{
public :

	RB_SpringGenerator(const RigidBody& rigidBody, const Vector3D& applicationPoint, float k, float l0) : m_rigidBody(rigidBody), m_applicationPoint(applicationPoint), m_k(k), m_l0(l0) {}

	void updateForce(RigidBody* rigidBody, Vector3D* apllicationPoint, float duration);

private:

	const Vector3D m_applicationPoint;

	// The opposite rigidbody connected to the spring
	const RigidBody & m_rigidBody;

	// Spring's elasticity constant
	float m_k;

	// Spring's rest size
	float m_l0;
};
#endif


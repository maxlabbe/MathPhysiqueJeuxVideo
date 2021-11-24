#ifndef RB_BUNGEEGENERATOR_H
#define RB_BUNGEEGENERATOR_H
#include <RB_ForceGenerator.h>

class RB_BungeeGenerator : public IRB_ForceGenerator
{
public:

	/// <summary>
	/// Custom elastic's ctor
	/// </summary>
	/// <param name="rigidBody"> RigidBody : The opposite rigid body connected to the elastic</param>
	/// <param name="applicationPoint"> Vector3D*: point of the opposite rigid body connected to the elastic </param>
	/// <param name="k"> float : Elastic's elasticity constant</param>
	/// <param name="l0"> float : Elastic's rest size</param>
	RB_BungeeGenerator(const RigidBody& rigidBody, const Vector3D& applicationPoint, float k, float l0) : m_rigidBody(rigidBody), m_applicationPoint(applicationPoint), m_k(k), m_l0(l0) {}

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="rigidBody"> RigidBody*: the rigid body on wich the force is applied </param>
	/// <param name="duration"> float: Duration on which the force is applied </param>
	/// <param name="applicationPoint"> Vector3D*: point of the rigid body where the force is applied </param>
	void updateForce(RigidBody* rigidBody, Vector3D* apllicationPoint, float duration);

private:

	// The application point where the elastic is connected on the opposite rigid body
	const Vector3D m_applicationPoint;

	// The opposite rigidbody connected to the spring
	const RigidBody& m_rigidBody;

	// Spring's elasticity constant
	float m_k;

	// Spring's rest size
	float m_l0;
};
#endif


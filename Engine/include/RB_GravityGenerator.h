#ifndef RB_GRAVITYGENERATOR_H
#define RB_GRAVITYGENERATOR_H

#include<RB_ForceGenerator.h>


class RB_GravityGenerator : public IRB_ForceGenerator
{
public:
	/// <summary>
	/// Default Ctor
	/// </summary>
	RB_GravityGenerator();

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="gravityValue"> float : the custom value of the gravity int the -y direction </param>
	RB_GravityGenerator(float gravityValue);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="rigidBody"> RigidBody*: the rigid body on wich the force is applied </param>
	/// <param name="duration"> float: Duration on which the force is applied </param>
	/// <param name="applicationPoint"> Vector3D*: point of the rigid body where the force is applied, by defaut on the mass center </param>
	void updateForce(RigidBody* rigidBody, float duration, Vector3D* applicationPoint = nullptr);

private:
	// the gravity vector
	Vector3D m_gravityVector;
};

#endif


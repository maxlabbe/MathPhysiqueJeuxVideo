#ifndef RB_BUOYANCY_H
#define RB_BUOYANCY_H

#include<RB_ForceGenerator.h>

class RB_Buoyancy : IRB_ForceGenerator
{
public:

	/// <summary>
	/// Buoyancy default Ctor
	/// </summary>
	RB_Buoyancy();

	/// <summary>
	/// Buoyancy custom Ctor
	/// </summary>
	/// <param name="maxDepth"> float : Depth where the object is submerged in the liquid </param>
	/// <param name="liquidHeight"> float : The liquid's height</param>
	/// <param name="density"> float : The liquid's density </param>
	RB_Buoyancy(float maxDepth, float liquidHeight, float density);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="rigidBody"> RigidBody*: the rigid body on wich the force is applied </param>
	/// <param name="duration"> float: Duration on which the force is applied </param>
	/// <param name="applicationPoint"> Vector3D*: point of the rigid body where the force is applied, by defaut on the mass center </param>
	void updateForce(RigidBody* rigidBody, float duration, Vector3D* applicationPoint = nullptr);

private:

	// Depth where the object is submerged in the liquid
	float m_maxDepth;

	// The liquid's height
	float m_liquidHeight;

	// The liquid's density
	float m_density;
};

#endif


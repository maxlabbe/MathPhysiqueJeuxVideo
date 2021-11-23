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
	/// <param name="objectVolume"> float : The object's volume </param>
	/// <param name="liquidHeight"> float : The liquid's height</param>
	/// <param name="density"> float : The liquid's density </param>
	RB_Buoyancy(float maxDepth, float liquidHeight, float density);

	/// <summary>
	/// Compute the force and add it to the forces applied on the particle
	/// </summary>
	/// <param name="particle"> Particle: the particle on wich th force is applied </param>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateForce(RigidBody* rigidBody, float duration, Vector3D* applicationPoint = nullptr);

private:

	// Depth where the object is submerged in the liquid
	float m_maxDepth;

	// The object's volume
	float m_objectVolume;

	// The liquid's height
	float m_liquidHeight;

	// The liquid's density
	float m_density;
};

#endif


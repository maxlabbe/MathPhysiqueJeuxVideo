#include <RB_Buoyancy.h>

// The default Ctor is for 10m of water
RB_Buoyancy::RB_Buoyancy() : RB_Buoyancy(2.0f, 10.0f, 1000.0f) {}

RB_Buoyancy::RB_Buoyancy(float maxDepth, float liquidHeight, float density)
	: m_maxDepth(maxDepth), m_liquidHeight(liquidHeight), m_density(density) {}

void RB_Buoyancy::updateForce(RigidBody* rigidBody, float duration, Vector3D* applicationPoint)
{
	float rigidBodyHeight = 0; //= rigidBody->GetHeight();
	float rigidBodyVolume = rigidBody->GetVolume();

	// If the rigid body is completely submerged
	// F = objectVolume * liquidDensity
	if (rigidBodyHeight <= m_maxDepth - m_liquidHeight)
	{
		rigidBody->addForceAtPoint(Vector3D(0, rigidBodyVolume * m_density, 0), rigidBody->GetMassCenter());
	}

	// If the rigid body is part submerged
	// F = object submerged depth * objectVolume * liquidDensity
	else if (rigidBodyHeight >= m_maxDepth - m_liquidHeight && rigidBodyHeight <= m_maxDepth + m_liquidHeight)
	{
		float submergedPartDepth = rigidBodyHeight - m_liquidHeight - m_maxDepth;

		rigidBody->addForceAtPoint(Vector3D(0, submergedPartDepth * rigidBodyVolume * m_density, 0), rigidBody->GetMassCenter());
	}

	// If the object is not submerged we do nothing
	else{}
}
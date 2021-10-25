#include <Buoyancy.h>

// The default Ctor is for 10m of water for an object of 1m³
Buoyancy::Buoyancy() : Buoyancy(2.0f, 1.0f, 10.0f, 1000.0f) {}

Buoyancy::Buoyancy(float maxDepth, float objectVolume, float liquidHeight, float density)
	: m_maxDepth(maxDepth), m_objectVolume(objectVolume), m_liquidHeight(liquidHeight), m_density(density) {}

void Buoyancy::updateForce(Particle* particle, float duration)
{
	// The particle's depth is it's y coordinate
	float particleDepth = particle->getPosition().getY();

	// If the particle is completely submerged
	// F = objectVolume * liquidDensity
	if (particleDepth <= m_maxDepth - m_liquidHeight)
	{
		particle->addForce(Vector3D(0, m_objectVolume * m_density, 0));
	}

	// If the particle is part submerged
	// F = object submerged depth * objectVolume * liquidDensity
	else if (particleDepth >= m_maxDepth - m_liquidHeight && particleDepth <= m_maxDepth + m_liquidHeight)
	{
		float submergedPartDepth = particleDepth - m_liquidHeight - m_maxDepth;

		particle->addForce(Vector3D(0, submergedPartDepth * m_objectVolume * m_density, 0));
	}

	// If the object is not submerged we do nothing
	else{}
}
#include <DragGenerator.h>

DragGenerator::DragGenerator() : m_k1(5.0f), m_k2(5.0f) {}
DragGenerator::DragGenerator(float k1, float k2) : m_k1(k1), m_k2(k2) {}

void DragGenerator::updateForce(Particle* particle, float duration)
{
	Vector3D velocity = particle->getVelocity();
	float x = velocity.getX();
	float y = velocity.getY();
	float z = velocity.getZ();

	if (x != 0)
	{
		x = x / abs(x);
	}

	if (y != 0)
	{
		y = y / abs(y);
	}

	if (z != 0)
	{
		z = z / abs(z);
	}

	Vector3D velocityUnitVector = Vector3D(x, y, z);
	float velocityNorm = velocity.norm();
	float dragValue = m_k1 * velocityNorm + m_k2 * velocityNorm * velocityNorm;

	particle->addForce(velocityUnitVector * dragValue);
	
}

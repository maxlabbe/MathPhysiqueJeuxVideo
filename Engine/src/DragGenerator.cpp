#include <DragGenerator.h>

// We choose 5 for both the constants as default values
DragGenerator::DragGenerator() : m_k1(5.0f), m_k2(5.0f) {}
DragGenerator::DragGenerator(float k1, float k2) : m_k1(k1), m_k2(k2) {}

void DragGenerator::updateForce(Particle* particle, float duration)
{
	// We need a unit vector in the same direction as the velocity
	// unit vector u, velocity vector v
	// u(x, y, z) = v(x/|x|, y/|y|, z/|z|) 
	Vector3D velocity = particle->getVelocity();
	float x = velocity.getX();
	float y = velocity.getY();
	float z = velocity.getZ();

	// if x, y or z equal 0 we can't divide it
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

	// drag coef = k1 * ||v|| + k2 * ||v||²
	float velocityNorm = velocity.norm();
	float dragValue = m_k1 * velocityNorm + m_k2 * velocityNorm * velocityNorm;

	//add the force to the particle
	particle->addForce(velocityUnitVector * dragValue);
	
}

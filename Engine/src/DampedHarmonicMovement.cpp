#include <DampedHarmonicMovement.h>

DampedHarmonicMovement::DampedHarmonicMovement() : DampedHarmonicMovement(1.0f, 0) {}
DampedHarmonicMovement::DampedHarmonicMovement(float k, float dumping)
	: m_k(k), m_dumping(dumping) {}

void DampedHarmonicMovement::updateForce(Particle* particle, float duration)
{
	// F = sqrt(k/m)/2pi
	// angular frequency(w) = 2pi * F
	float angularFrequency = sqrtf(m_k * particle->getInverseMass());

	float dampingCoef = m_dumping / (2 * particle->getMass() * angularFrequency);

	Vector3D k1 = particle->getPosition();
	Vector3D k2;
	Vector3D posFunction;
	Vector3D velocityFunction;

	if (dampingCoef >= 0 && dampingCoef < 1)
	{
		float realAngularFrequency = angularFrequency * sqrtf(1 - pow(dampingCoef, 2));
		Vector3D k2 = (dampingCoef * angularFrequency * particle->getPosition() + particle->getVelocity()) / realAngularFrequency;
		posFunction = (k1 * cosf(realAngularFrequency * duration) + k2 * sinf(realAngularFrequency * duration)) * expf(-1 * dampingCoef * angularFrequency * duration);
		velocityFunction = expf(-1 * dampingCoef * angularFrequency * duration) * 
			(realAngularFrequency * (k2 * cosf(realAngularFrequency * duration) - k1 * sin(realAngularFrequency * duration)) + 
			dampingCoef * angularFrequency * (k1 * cosf(realAngularFrequency * duration) + k2 * sinf(realAngularFrequency * duration)));
	}

	else if (dampingCoef == 1)
	{
		Vector3D k2 = angularFrequency * particle->getPosition() + particle->getVelocity();
		posFunction = (k1 + k2 * duration) * expf(-1 * angularFrequency * duration);
		velocityFunction = expf(-1 * angularFrequency * duration) * (k2 * (1 + duration) + k1);
	}

	Vector3D accelertionValue = -1 * pow(angularFrequency, 2) * posFunction - 2 * dampingCoef * angularFrequency * velocityFunction;
	particle->addForce(particle->getMass() * accelertionValue);
}

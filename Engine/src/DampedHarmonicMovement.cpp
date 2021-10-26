#include <DampedHarmonicMovement.h>

DampedHarmonicMovement::DampedHarmonicMovement() : DampedHarmonicMovement(1.0f, 0) {}
DampedHarmonicMovement::DampedHarmonicMovement(float k, float dumping)
	: m_k(k), m_dumping(dumping) {}

void DampedHarmonicMovement::updateAcceleration(Particle* particle, float duration)
{
	// F = sqrt(k/m)/2pi
	// angular frequency(w) = 2pi * F
	float angularFrequency = sqrtf(m_k * particle->getInverseMass());

	// dumping coef = dumping value / 2mw
	float dumpingCoef = m_dumping / (2 * particle->getMass() * angularFrequency);

	// x(t) has two constant k1 and k2
	//k1 = x(0)
	//k2 depend on the situation
	Vector3D k1 = particle->getPosition();
	Vector3D k2;

	//x(t)
	Vector3D posFunction;

	// x'(t)
	Vector3D velocityFunction;

	// 0 =< dumping < 1
	if (dumpingCoef >= 0 && dumpingCoef < 1)
	{
		// reel angular frequency(wd) = w * sqrt(1-dumpingCoef²)
		float reelAngularFrequency = angularFrequency * sqrtf(1 - pow(dumpingCoef, 2));

		// k2 = (dumpingCoef * w * x(0) + x'(0)) / wd
		Vector3D k2 = (dumpingCoef * angularFrequency * particle->getPosition() + particle->getVelocity()) / reelAngularFrequency;

		// x(t) = (k1*cos(wd*t) + k2*sin(wdt)) * exp(-dumpingCoef*w*t)
		posFunction = (k1 * cosf(reelAngularFrequency * duration) + k2 * sinf(reelAngularFrequency * duration)) * expf(-1 * dumpingCoef * angularFrequency * duration);

		//x'(t) => U'V-UV', U = k1*cos(...) + k2*sin(...), V = exp(-dumpingCoef*w*t)
		velocityFunction = expf(-1 * dumpingCoef * angularFrequency * duration) * 
			(reelAngularFrequency * (k2 * cosf(reelAngularFrequency * duration) - k1 * sin(reelAngularFrequency * duration)) + 
			dumpingCoef * angularFrequency * (k1 * cosf(reelAngularFrequency * duration) + k2 * sinf(reelAngularFrequency * duration)));
	}

	else if (dumpingCoef == 1)
	{
		// k2 = w*x(0)+ x'(0)
		Vector3D k2 = angularFrequency * particle->getPosition() + particle->getVelocity();

		// x(t) = (k1 + k2*t) * exp(-w*t)
		posFunction = (k1 + k2 * duration) * expf(-1 * angularFrequency * duration);

		//x'(t) = U'V-UV', U = k1 + k2*t, V = exp(-w*t)
		velocityFunction = expf(-1 * angularFrequency * duration) * (k2 * (1 + duration) + k1);
	}

	//x''(t) = -w²*x(t) - 2*dumpingCoef*w*x'(t)
	Vector3D accelertionValue = -1 * pow(angularFrequency, 2) * posFunction - 2 * dumpingCoef * angularFrequency * velocityFunction;

	//F = m*a(t)
	particle->setAcceleration(accelertionValue);
}

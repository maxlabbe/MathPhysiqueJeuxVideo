#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H

#include<ParticleForceGenerator.h>

class DragGenerator : IParticleForceGenerator
{
public:
	DragGenerator();
	DragGenerator(float k1, float k2);

	void updateForce(Particle* particle, float duration);

private:
	float m_k1;
	float m_k2;
};

#endif


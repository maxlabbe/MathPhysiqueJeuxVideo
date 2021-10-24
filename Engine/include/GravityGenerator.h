#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H

#include<ParticleForceGenerator.h>


class GravityGenerator : IParticleForceGenerator
{
public: 
	GravityGenerator();
	GravityGenerator(float gravityValue);
	void updateForce(Particle* particle, float duration);

private:
	Vector3D m_gravityValues;
};

#endif


#pragma once
#ifndef GRAVITYGENERATOR_H
#define GRAVITYGENERATOR_H

#include<ParticleForceGenerator.h>

class GravityGenerator : IParticleForceGenerator
{
public: 
	void updateForce(Particle* particle, float duration);
};

#endif


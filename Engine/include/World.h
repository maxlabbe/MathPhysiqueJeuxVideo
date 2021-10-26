#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include"Particle.h"
#include"Plane.h"
#include"DisplayablePlane.h"
#include"DisplayableParticle.h"
#include"ForceRegister.h"
#include <GravityGenerator.h>
#include <DragGenerator.h>
#include <ParticleSpring.h>
#include<AnchoredSpring.h>
#include <DampedHarmonicMovement.h>

class World
{
public:


	World(Plane& plane);

	/// <summary>
	/// Adds a particle to the blob
	/// </summary>
	/// <param name="particle">Particle* : particle to add to the blob</param>
	void AddParticle(Particle* particle);

	/// <summary>
	/// Updates the world by computing all forces and integrating all particles
	/// </summary>
	/// <param name="duration">float : duration</param>
	void updateWorld(float duration);

	// Getters

	Plane GetPlane() { return m_plane; }
	vector<Displayable*>* GetDisplayables() { return m_displayables; }

private:

	vector<Particle*> m_blob;
	Plane m_plane;

	vector<Displayable*>* m_displayables;
	ForceRegister m_forceRegister;

};


#endif


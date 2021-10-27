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
#include <ColisionDetector.h>
#include <ParticleContactResolver.h>

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

	/// <summary>
	/// 
	/// </summary>
	/// <param name="gravity"></param>
	/// <param name="dragK1"></param>
	/// <param name="dragK2"></param>
	/// <param name="springK"></param>
	/// <param name="springL"></param>
	void createBlob(float gravity = 9.81f, float dragK1 = 0.1f, float dragK2 = 0.2f, float springK = 1.0f, float springL = 1.0f);

	void detecteAndResolveColisions(float duration);

	void moveMainParticle(Vector3D velocity);

	// Getters

	Plane GetPlane() { return m_plane; }
	vector<Displayable*>* GetDisplayables() { return m_displayables; }
	Vector3D getMainParticlePosition() { return m_mainParticle->getPosition(); }

private:

	Particle* m_mainParticle;
	vector<Particle*> m_blob;
	Plane m_plane;

	vector<Displayable*>* m_displayables;
	ForceRegister m_forceRegister;
	ColisionDetector m_detector;

};


#endif


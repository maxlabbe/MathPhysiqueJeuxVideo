#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include"Particle.h"
#include"Plane.h"
#include"DisplayablePlane.h"
#include"DisplayableParticle.h"
#include<stdlib.h>

class World
{
public:


	World(Plane& plane);

	void AddParticle(Particle& particle);

	// Getters

	Plane GetPlane() { return m_plane; }
	vector<Displayable*>* GetDisplayables() { return m_displayables; }

private:

	vector<Particle> m_blob;
	Plane m_plane;

	vector<Displayable*>* m_displayables;

};


#endif


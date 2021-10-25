#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include"Particle.h"
#include"Plane.h"

class World
{
public:

	World(Plane& plane);
	void AddParticle(Particle& particle);

	// Getters

	Plane GetPlane() { return m_plane; }

private:

	vector<Particle> m_blob;
	Plane m_plane;

};


#endif


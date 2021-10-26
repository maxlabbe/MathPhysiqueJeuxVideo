#include"World.h"

World::World(Plane& plane) : m_plane(plane) 
{
	DisplayablePlane* dPlane = new DisplayablePlane(plane);
	m_displayables = new vector<Displayable*>;
	m_displayables->push_back(dPlane);

	for (int i = 0; i < 16; i++)
	{
		Particle p(1, Vector3D(rand() % 6 - 3, rand() %  3, rand() % 6 - 3), Vector3D(), Vector3D(), Vector3D());
		DisplayableParticle* dp = new DisplayableParticle(p, 0.5, true);
		AddParticle(p);
		m_displayables->push_back(dp);
	}
}

void World::AddParticle(Particle& particle) 
{
	m_blob.push_back(particle);
}
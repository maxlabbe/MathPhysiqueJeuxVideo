#include"World.h"

World::World(Plane& plane) : m_plane(plane) {}

void World::AddParticle(Particle& particle) 
{
	m_blob.push_back(particle);
}
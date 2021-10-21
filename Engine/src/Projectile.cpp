#include"Projectile.h"

Projectile::Projectile(Vector3D initPos, Vector3D initVelocity, float gravity,float lifespan) :
	m_particle(1.0f, initPos, initVelocity, Vector3D(0.0f, -gravity, 0.0f), 1.01)
{
	m_gravity = gravity;
	m_lifespan = lifespan;
	m_lifeTime = 0.0f;
	DisplayableParticle* particle = new DisplayableParticle(m_particle, 0.01f, false);
	m_trace = new vector<Displayable*>;
	m_trace->push_back(particle);
}

void Projectile::update(float time)
{
	if (m_lifeTime < m_lifespan)
	{
		// Compute physic in seconds
		m_particle.integrate(time / 1000);

		
		// Create a displayable object for the trajectory
		DisplayableParticle* particle_trace = new DisplayableParticle(m_particle, 0.01f, true);
		// Add it to the trah=jectory vector
		m_trace->push_back(particle_trace);
		

		m_lifeTime += time;
	}
}
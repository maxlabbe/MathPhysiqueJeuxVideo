#ifndef PROJECTILE_H
#define PROJECTILE_H


#include"Common.h"
#include"Particle.h"
#include"DisplayableParticle.h"

class Projectile
{
public :

	Projectile(Vector3D initPos, Vector3D initVelocity, float gravity, float lifespan = 4000.0f);

	vector<Displayable*> getTrace() { return m_trace; }

	void update(float time);

private :

	Particle m_particle;
	float m_gravity;
	float m_lifespan; //ms
	vector<Displayable*> m_trace;
	float m_lifeTime; //ms
	

};

#endif

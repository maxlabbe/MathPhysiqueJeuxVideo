#ifndef PROJECTILE_H
#define PROJECTILE_H


#include"Common.h"
#include"Particle.h"
#include"DisplayableParticle.h"

class Projectile
{
public :

	/// <summary>
	/// Projectile ctor
	/// </summary>
	/// <param name="initPos"> Vector3D : initial position of the projectile </param>
	/// <param name="initVelocity"> Vector3D : initial velocity of the projectile </param>
	/// <param name="gravity"> float : gravity apply to the projectile </param>
	/// <param name="lifespan"> float : life time of the projectile </param>
	Projectile(Vector3D initPos, Vector3D initVelocity, float gravity, float lifespan = 4000.0f);

	/// <summary>
	/// Return a displayable trajectory of the projectile 
	/// </summary>
	/// <returns> vector<Displayables*> : the trajectory </returns>
	vector<Displayable*> getTrace() { return m_trace; }

	/// <summary>
	/// Update the physic of the projectile when call
	/// </summary>
	/// <param name="time"> float : time which the physic depend on </param>
	void update(float time);

private :

	// The particle associated to the projectile (contain physic)
	Particle m_particle;

	// The gravity apply to the projectile
	float m_gravity;

	// The life time of the projectile
	float m_lifespan; //ms

	// The displayable trajectory of the projectile 
	vector<Displayable*> m_trace;

	// The life of the particle at t moment
	float m_lifeTime; //ms
};

#endif

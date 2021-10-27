#ifndef PARTICLECONTACT_H
#define PARTICLECONTACT_H
#include<Particle.h>

class ParticleContact
{
public:
	/// <summary>
	/// default Ctor
	/// </summary>
	/// /// <param name="particles"> Particle*[] : the particles involve in the collision </param>
	ParticleContact(Particle* particles[2]);

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="particles"> Particle*[] : the particles involved in the collision </param>
	/// <param name="restitutionCoef"> float : The restitution coef of the collision </param>
	ParticleContact(Particle* particles[2], float restitutionCoef, float penetration);

	/// <summary>
	/// Resolve the collision by adding an impulsion to the particles
	/// </summary>
	/// <param name="duration"> float : the time </param>
	void resolve(float duration);

	/// <summary>
	/// Compute the total velocity of the particles
	/// </summary>
	float computeApproachVelocity() const;

	/// <summary>
	/// Deconnect the particles if there is interpenetration
	/// </summary>
	void resolveInterpenetration();

	/// <summary>
	/// Compute the velocity due to the collision and apply the impulsion
	/// </summary>
	/// <param name="duration"></param>
	void resolveVelocity(float duration);

	/// <summary>
	/// Modifies the value of m_contactPointNormal to its opposite
	/// </summary>
	void oppositeNormal() { m_contactPointNormal = m_contactPointNormal * (-1);}

private:
	// The particles involve in the collision
	Particle* m_particles[2];

	// the restitution coef that simulate the losses
	float m_restitutionCoef;

	// The normal vector of the contact point
	Vector3D m_contactPointNormal;

	// The distance of penetration between the two particles
	float m_penetration;
};

#endif


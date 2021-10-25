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
	ParticleContact(Particle* particles[2], float restitutionCoef);

	/// <summary>
	/// Resolve the collision by adding an imoulsion to the particles
	/// </summary>
	/// <param name="duration"> float : the time </param>
	void resolve(float duration);

	/// <summary>
	/// Compute the total velocity of the particles
	/// </summary>
	void computeApproachVelocity() const;

	/// <summary>
	/// Compute the impulsion whih is the result of the collision
	/// </summary>
	/// <param name="duration"> float : the time </param>
	void ResolveImpulsion(float duration);

	/// <summary>
	/// Deconnect the particles if there is interpenetration
	/// </summary>
	void resolveInterpenetration();

	/// <summary>
	/// Compute the velocity due to the collision and apply the impulsion
	/// </summary>
	/// <param name="duration"></param>
	void resolveVelocity(float duration);
private:
	Particle* m_particles[2];
	float m_restitutionCoef;
	Vector3D m_contactPointNormal;
	Vector3D m_penetration;
	Vector3D m_impulsion;
};

#endif


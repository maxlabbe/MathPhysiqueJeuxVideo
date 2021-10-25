#ifndef FORCEREGISTER_H
#define FORCEREGISTER_H

#include <vector>

#include "Particle.h"
#include "ParticleForceGenerator.h"

class ForceRegister {

public:

	/// <summary>
	/// Register the force associated with a particle
	/// </summary>
	/// <param name="particle"> Particle*: a pointer to the particle </param>
	/// <param name="forceGenerator"> IParticleForceGenerator*: a pointer to the force generator </param>
	void registerForce(Particle* particle, IParticleForceGenerator* forceGenerator);

	/// <summary>
	/// Add the vector value of a force that is applied on the particle to the forces already applyed on the particle
	/// </summary>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateAllForces(float duration);

	/// <summary>
	/// Ctor
	/// Create a force register
	/// </summary>
	ForceRegister();

private:

	// the structure associating a force to its particle
	typedef struct ForceRegistrationStruct {
		Particle* m_particle;
		IParticleForceGenerator* m_forceGenerator;
	} ForceRegistration;

	// the type Register
	typedef vector<ForceRegistration> Register;

	// the table containing all the forces
	Register m_register;

};

#endif
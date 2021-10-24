#ifndef FORCEREGISTER_H
#define FORCEREGISTER_H

#include <vector>

#include "Particle.h"
#include "ParticleForceGenerator.h"

class ForceRegister {

public:

	void registerForce(Particle* particle, IParticleForceGenerator* forceGenerator);

	void deleteForce();

	void updateAllForces(float duration);

	/// <summary>
	/// Ctor
	/// Create a force register
	/// </summary>
	ForceRegister();

private:

	// the structure linking a force to its particle
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
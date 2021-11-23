#ifndef FORCEREGISTERRIGIDBODY_H
#define FORCEREGISTERRIGIDBODY_H

#include <vector>

#include "RigidBody.h"
#include "RB_ForceGenerator.h"

class ForceRegisterRigidBody {

public:

	/// <summary>
	/// Register the force associated with a rigid body
	/// </summary>
	/// <param name="rigidBody"> Particle*: a pointer to the rigid body </param>
	/// <param name="forceGenerator"> IRigidBodyForceGenerator*: a pointer to the force generator </param>
	void registerForce(RigidBody* rigidBody, Vector3D applicationPoint, IRB_ForceGenerator* forceGenerator);

	/// <summary>
	/// Add the vector value of a force that is applied on the rigid body to the forces already applyed on the rigid body
	/// </summary>
	/// <param name="duration"> Duration on which the force is applied </param>
	void updateAllForces(float duration);

	/// <summary>
	/// Ctor
	/// Create a force register
	/// </summary>
	ForceRegisterRigidBody();

private:

	// the structure associating a force to its particle
	typedef struct ForceRegistrationStruct {
		RigidBody* m_rigidBody;
		IRB_ForceGenerator* m_forceGenerator;
		Vector3D* m_point;
	} ForceRegistration;

	// the type Register
	typedef vector<ForceRegistration> Register;

	// the table containing all the forces
	Register m_register;

};

#endif
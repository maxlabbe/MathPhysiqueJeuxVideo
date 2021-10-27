#ifndef COLISIONDETECTOR_H 
#define COLISIONDETECTOR_H

#include<vector>
#include<Particle.h>
#include<ParticleLink.h>
#include<ParticleContact.h>
#include<math.h>

class ColisionDetector
{
public:
	/// <summary>
	/// Default ctor
	/// </summary>
	ColisionDetector();

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="particles"> vector<Particle*> : all the particles in the scene </param>
	/// <param name="specialContacts"> vector<Particle*> : all the special link between particles that generate contacts </param>
	ColisionDetector(vector<Particle*> particles, vector<ParticleLink> specialContacts);

	/// <summary>
	/// Detect the collision in the scene
	/// </summary>
	vector<ParticleContact*> detectCollisions();

private:
	// All the particles in the scene
	vector<Particle*> m_particles;

	// All the contact 
	vector<ParticleLink> m_specialContacts;
	vector<ParticleContact*> m_detectedContacts;
};

#endif




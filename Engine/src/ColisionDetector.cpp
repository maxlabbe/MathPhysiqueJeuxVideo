#include <ColisionDetector.h>

ColisionDetector::ColisionDetector() 
	: ColisionDetector(vector<Particle*>(), vector<ParticleLink>()) {}

ColisionDetector::ColisionDetector(vector<Particle*> particles, vector<ParticleLink> specialContacts)
	: m_particles(particles), m_specialContacts(specialContacts), m_detectedContacts(vector<ParticleContact*>()) {}

vector<ParticleContact*> ColisionDetector::detectCollisions()
{
	srand(time(0));

	// We need to compare each particle with the other to know if there is a colision
	for (int particleIndex = 0; particleIndex < m_particles.size(); particleIndex++)
	{
		for (int otherParticleIndex = particleIndex + 1; otherParticleIndex < m_particles.size(); otherParticleIndex++)
		{

			// The tangDistance is the distance where the particules are tangeant to each other
			float tangDistance = m_particles[particleIndex]->getRadius() + m_particles[otherParticleIndex]->getRadius();

			// actual distance between the particles
			float distance = (m_particles[particleIndex]->getPosition() - m_particles[otherParticleIndex]->getPosition()).norm();

			// If the distance is less than the tangeant distance => colision
			if (distance <= tangDistance)
			{
				// Store the particles in an array for the Ctor
				Particle* particles[2] = { m_particles[particleIndex], m_particles[otherParticleIndex] };

				// Compute the interpenetration
				float interpenetration = tangDistance - distance;

				// Generate random restitution coef because we didn't set one
				// We can give a material to each particle and the ground with different coefs
				int randomNum = rand() % 100;
				float restitutionCoef = (float)randomNum / 100;

				// Add the contact to the list of detected contacts
				m_detectedContacts.push_back(new ParticleContact(particles, restitutionCoef, interpenetration));
			}
		}
	}

	//Now that the reel colision are detected we have to detecte the link colisions
	for (int linkIndex = 0; linkIndex < m_specialContacts.size(); linkIndex++)
	{
		m_specialContacts[linkIndex].addContact(m_detectedContacts);
	}

	return m_detectedContacts;
}
#include <ParticleContactResolver.h>

ParticleContactResolver::ParticleContactResolver() : ParticleContactResolver(0) {}

ParticleContactResolver::ParticleContactResolver(int iterations) : m_iterations(iterations), m_usedIterations(0) {}

void ParticleContactResolver::resolveContact(vector<ParticleContact*> contacts, float duration)
{
	// The index of the collision with the smallest velocity
	int smallestContactVelocityIndex;

	// We don't want to iterate over and over so we have a max value of iteration
	while (m_usedIterations < m_iterations)
	{
		smallestContactVelocityIndex = 0;

		//Looking for the collision with the smallest velocity
		for (int contactIndex = 1; contactIndex < contacts.size(); contactIndex++)
		{
			if (contacts[smallestContactVelocityIndex]->computeApproachVelocity() > contacts[contactIndex]->computeApproachVelocity())
			{
				smallestContactVelocityIndex = contactIndex;
			}
		}

		// Resolve the contact
		contacts[smallestContactVelocityIndex]->resolve(duration);

		//erase the collision from the vector
		contacts.erase(contacts.begin() + smallestContactVelocityIndex);

		//Ecrease the number of iteration because we made juste one iteration
		m_usedIterations++;
	}
	
}
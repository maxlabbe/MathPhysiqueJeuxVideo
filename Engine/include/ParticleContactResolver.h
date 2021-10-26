#ifndef PARTICLECONTACRESOLVER_H
#define PARTICLECONTACRESOLVER_H

#include<ParticleContact.h>
#include<vector>

class ParticleContactResolver
{
	friend class ParticleContact;
public:
	/// <summary>
	/// Default Ctor : number of iterations put to 0
	/// </summary>
	ParticleContactResolver();

	/// <summary>
	/// Custom Ctor
	/// </summary>
	/// <param name="iterations">int : number of wanted iterations </param>
	ParticleContactResolver(int iterations);

	/// <summary>
	/// Set the number of iterations to the wanted number of iterations
	/// </summary>
	/// <param name="Iterations">int: the wanted number of iterations </param>
	void setIterations(int iterations) { m_iterations = iterations; }

	/// <summary>
	/// Resolve all the contact given in parameters
	/// </summary>
	void resolveContact(vector<ParticleContact*> contacts, float duration);

private:
	int m_iterations;
	int m_usedIterations;
};

#endif

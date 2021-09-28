#ifndef DISPLAYABLE_PARTICLE_H
#define DISPLAYABLE_PARTICLE_H

#include"Displayable.h"
#include"Particle.h"
#include"Sphere.h"

class DisplayableParticle : public Displayable 
{
public :

	/// <summary>
	/// Displayable particle constructor
	/// </summary>
	/// <param name="p"> Particle : the particle to display</param>
	/// <param name="radius"> float : the particle radius </param>
	/// <param name="isStatic"> bool : particle movement flag </param>
	/// <param name="color"> Vector3D* : the particle's color </param>
	DisplayableParticle(Particle& p, float radius, bool isStatic = false, Vector3D* color = new Vector3D(0.8f,0.8f,0.8f));

	/// <summary>
	/// Give the number of index to draw the particle
	/// </summary>
	/// <returns> unisgned int : the number of index </returns>
	unsigned int getIndexCount();

protected :

	/// <summary>
	/// Give the vertices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the vertices </returns>
	GLfloat* getVertices();

	/// <summary>
	/// Give the indices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the indices </returns>
	GLuint* getIndices();

	/// <summary>
	/// Give the size of the vertices in the memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the verticies </returns>
	GLsizeiptr getSizeOfVertices();

	/// <summary>
	/// Give the size of the indicies in memory 
	/// </summary>
	/// <returns> GLsizeiptr : the size of the indicies </returns>
	GLsizeiptr getSizeOfIndices();

private :

	// The particle to display
	Particle m_particle;

	// The sphere to draw to display the particle
	Sphere m_sphere;

	// The particle's movement flag
	bool m_isStatic;
};

#endif

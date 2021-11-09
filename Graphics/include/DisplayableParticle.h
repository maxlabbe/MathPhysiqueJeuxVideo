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
	DisplayableParticle(Particle& p, bool isStatic = false, Vector3D* color = new Vector3D(0.8f,0.8f,0.8f));

	/// <summary>
	/// Give the number of index to draw the particle
	/// </summary>
	/// <returns> unisgned int : the number of index </returns>
	unsigned int GetIndexCount();

protected :

	/// <summary>
	/// Give the vertices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the vertices </returns>
	GLfloat* GetVertices();

	/// <summary>
	/// Give the indices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the indices </returns>
	GLuint* GetIndices();

	/// <summary>
	/// Give the size of the vertices in the memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the verticies </returns>
	GLsizeiptr GetSizeOfVertices();

	/// <summary>
	/// Give the size of the indicies in memory 
	/// </summary>
	/// <returns> GLsizeiptr : the size of the indicies </returns>
	GLsizeiptr GetSizeOfIndices();

	void Delete();

private :

	// The particle to display
	Particle m_particle;

	// The sphere to draw to display the particle
	Sphere m_sphere;
};

#endif

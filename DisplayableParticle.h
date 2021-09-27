#ifndef DISPLAYABLE_PARTICLE_H
#define DISPLAYABLE_PARTICLE_H

#include"Displayable.h"
#include"Particle.h"
#include"Sphere.h"

class DisplayableParticle : public Displayable 
{
public :

	DisplayableParticle(Particle&, float radius, bool isStatic = false, Vector3D* color = new Vector3D(0.8f,0.8f,0.8f));
	unsigned int getIndexCount();

protected :

	GLfloat* getVertices();
	GLuint* getIndices();
	GLsizeiptr getSizeOfVertices();
	GLsizeiptr getSizeOfIndices();

private :

	Particle particle;
	Sphere sphere;
	bool isStatic;
};

#endif

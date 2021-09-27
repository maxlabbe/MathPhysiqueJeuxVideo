#include"DisplayableParticle.h"

DisplayableParticle::DisplayableParticle(Particle& p, float radius, bool isStatic, Vector3D* color) : particle(p)
{
	this->sphere = Sphere(radius, p.getPositionPtr(), color);
	this->mode = GL_TRIANGLES;
	this->isStatic = isStatic;
}

unsigned int DisplayableParticle::getIndexCount()
{
	return sphere.getIndexCount();
}

GLfloat* DisplayableParticle::getVertices()
{
	if(!isStatic) sphere.updateGLVerticesColor();
	return sphere.getGLVerticesColor();
}

GLuint* DisplayableParticle::getIndices()
{
	return sphere.getGLIndices();
}

GLsizeiptr DisplayableParticle::getSizeOfVertices()
{
	return sizeof(GLfloat) * sphere.getVertexCount() * 6;
}

GLsizeiptr DisplayableParticle::getSizeOfIndices()
{
	return sizeof(GLuint) * sphere.getIndexCount();
}
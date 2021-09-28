#include"DisplayableParticle.h"

DisplayableParticle::DisplayableParticle(Particle& p, float radius, bool isStatic, Vector3D* color) : m_particle(p)
{
	m_sphere = Sphere(radius, p.getPositionPtr(), color);
	mode = GL_TRIANGLES;
	m_isStatic = isStatic;
}

unsigned int DisplayableParticle::getIndexCount()
{
	return m_sphere.getIndexCount();
}

GLfloat* DisplayableParticle::getVertices()
{
	if(!m_isStatic) m_sphere.updateGLVerticesColor();
	return m_sphere.getGLVerticesColor();
}

GLuint* DisplayableParticle::getIndices()
{
	return m_sphere.getGLIndices();
}

GLsizeiptr DisplayableParticle::getSizeOfVertices()
{
	return sizeof(GLfloat) * m_sphere.getVertexCount() * 6;
}

GLsizeiptr DisplayableParticle::getSizeOfIndices()
{
	return sizeof(GLuint) * m_sphere.getIndexCount();
}
#include"DisplayableParticle.h"

DisplayableParticle::DisplayableParticle(Particle& p, bool isStatic, Vector3D* color) : m_particle(p), m_sphere(p.getRadius(), p.getPositionPtr(), color)
{
	
	p_mode = GL_TRIANGLES;
	p_isStatic = isStatic;
}

unsigned int DisplayableParticle::GetIndexCount()
{
	return m_sphere.getIndexCount();
}

GLfloat* DisplayableParticle::GetVertices()
{
	if(!p_isStatic) m_sphere.updateGLVerticesColor();
	return m_sphere.getGLVerticesColor();
}

GLuint* DisplayableParticle::GetIndices()
{
	return m_sphere.getGLIndices();
}

GLsizeiptr DisplayableParticle::GetSizeOfVertices()
{
	return sizeof(GLfloat) * m_sphere.getVertexCount() * 6;
}

GLsizeiptr DisplayableParticle::GetSizeOfIndices()
{
	return sizeof(GLuint) * m_sphere.getIndexCount();
}

void DisplayableParticle::Delete()
{
	Displayable::Delete();
	m_sphere.~Sphere();
}
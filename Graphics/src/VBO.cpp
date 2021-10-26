#include"VBO.h"

void VBO::LinkToVertices(GLfloat* vertices, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	m_isAllocated = true;
}

void VBO::Bind()
{
	if (!m_isID)
	{
		glGenBuffers(1, &m_ID);
		m_isID = true;
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	if (m_isID)
	{
		glDeleteBuffers(1, &m_ID);
		m_isID = false;
	}
}
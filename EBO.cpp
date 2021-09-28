#include"EBO.h"

void EBO::linkToIndices(GLuint* indices, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

// Binds the EBO
void EBO::Bind()
{	
	if (!m_isID)
	{
		glGenBuffers(1, &m_ID);
		m_isID = true;
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

// Unbinds the EBO
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the EBO
void EBO::Delete()
{
	if (m_isID)
	{
		glDeleteBuffers(1, &m_ID);
	}
}
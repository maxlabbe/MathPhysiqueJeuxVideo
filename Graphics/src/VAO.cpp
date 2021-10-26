#include"VAO.h"

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	m_isAttributesLinked = true;
	VBO.Unbind();
}

void VAO::Bind()
{
	if (!m_isID)
	{
		glGenVertexArrays(1, &m_ID);
		m_isID = true;
	}
	glBindVertexArray(m_ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	if (m_isID)
	{
		glDeleteVertexArrays(1, &m_ID);
		m_isAttributesLinked = false;
	}
}
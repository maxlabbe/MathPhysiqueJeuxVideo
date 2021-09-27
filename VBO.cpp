#include"VBO.h"

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	linkToVertices(vertices, size);
}

void VBO::linkToVertices(GLfloat* vertices, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind()
{
	if (!isID)
	{
		glGenBuffers(1, &ID);
		isID = true;
	}
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::Delete()
{
	if (isID)
	{
		glDeleteBuffers(1, &ID);
	}
}
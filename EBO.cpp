#include"EBO.h"

// Constructor that generates a Elements Buffer Object and links it to indices
EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	linkToIndices(indices, size);
}

// Link to Indices
void EBO::linkToIndices(GLuint* indices, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

// Binds the EBO
void EBO::Bind()
{	
	if (!isID)
	{
		glGenBuffers(1, &ID);
		isID = true;
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Unbinds the EBO
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the EBO
void EBO::Delete()
{
	if (isID)
	{
		glDeleteBuffers(1, &ID);
	}
}
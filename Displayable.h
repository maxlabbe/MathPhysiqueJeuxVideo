#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "VAO.h"
#include "EBO.h"

class Displayable
{
public : 

	void display();
	virtual unsigned int getIndexCount() = 0;
	void Delete();

protected:

	// Getters 

	virtual GLfloat* getVertices() = 0;
	virtual GLuint* getIndices() = 0;
	virtual GLsizeiptr getSizeOfVertices() = 0;
	virtual GLsizeiptr getSizeOfIndices() = 0;

	// Attributes

	VAO VAO;
	VBO VBO;
	EBO EBO;
	GLenum mode;
};

#endif

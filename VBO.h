#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VBO
{
public:
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(GLfloat* vertices, GLsizeiptr size);
	// Default constructor
	VBO() {}

	void linkToVertices(GLfloat* vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();

private:
	// Reference ID of the Vertex Buffer Object
	GLuint ID = 0;
	bool isID = false;
};

#endif

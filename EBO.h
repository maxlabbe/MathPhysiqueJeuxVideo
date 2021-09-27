#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{
public:
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);
	// Default constructor
	EBO() {}

	void linkToIndices(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();

private :

	// ID reference of Elements Buffer Object
	GLuint ID = 0;
	bool isID = false;
};

#endif

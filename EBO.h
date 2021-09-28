#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

/// <summary>
/// Element Buffer Object.
/// Handle a buffer of indices.
/// </summary>
class EBO
{
public:

	/// <summary>
	/// Default constructor
	/// </summary>
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

#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

/// <summary>
/// Vertex Array Object.
/// Basically an array of VBO (Vertex Buffer Object).
/// </summary>
class VAO
{
public :
	
	/// <summary>
	/// Default VAO constructor.
	/// </summary>
	VAO() {}

	// Links a VBO Attribute such as a position or color to the VAO
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	// Binds the VAO
	void Bind();
	// Unbinds the VAO
	void Unbind();
	// Deletes the VAO
	void Delete();

private :

	// ID reference for the Vertex Array Object
	GLuint ID = 0;
	bool isID = false;

};
#endif

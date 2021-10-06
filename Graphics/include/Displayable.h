#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "VAO.h"
#include "EBO.h"

/// <summary>
/// Abstract class. 
/// Represents a GL displayable object and is able to display it.
/// A displayable object is defined as a set of vertices and a set of indices
/// that gives the links between the vertices.
/// </summary>
class Displayable
{
public : 

	/// <summary>
	/// Displays the object using glDrawElements function in the current context.
	/// </summary>
	void display();

	/// <summary>
	/// Returns the number of indices.
	/// </summary>
	/// <returns>
	/// unsigned int : number of indices of the object.
	/// </returns>
	virtual unsigned int getIndexCount() = 0;

	/// <summary>
	/// Deletes all the buffer objects, VAO, VBO and EBO.
	/// </summary>
	void Delete();

protected:

	// Getters 

	virtual GLfloat* getVertices() = 0;
	virtual GLuint* getIndices() = 0;
	virtual GLsizeiptr getSizeOfVertices() = 0;
	virtual GLsizeiptr getSizeOfIndices() = 0;

	// Attributes

	// Vertex Array Object : handle vertices and color attributes from the VBO
	VAO p_VAO;
	// Vertex Buffer Object : buffer with values for vertices and color 
	VBO p_VBO;
	// Element Buffer Object : buffer with the indices og the object
	EBO p_EBO;
	// Mode of drawing the objects : can be GL_TRIANGLES, GL_LINES...
	GLenum p_mode;
};

#endif

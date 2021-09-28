#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VBO
{
public:
	/// <summary>
	/// Vertex Buffer Object Construct
	/// </summary>
	VBO() {}

	/// <summary>
	/// Puts the vertices into the buffer object
	/// </summary>
	/// <param name="vertices">Glfloat* : list of vertices</param>
	/// <param name="size">GLsizeptr : memory size of the list of vertices (bytes)</param>
	void linkToVertices(GLfloat* vertices, GLsizeiptr size);

	/// <summary>
	/// Binds the vertex buffer. Makes it the current buffer of data.
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the vertex buffer. Binds an empty buffer.
	/// </summary>
	void Unbind();

	/// <summary>
	/// Deletes the buffer and its content.
	/// </summary>
	void Delete();

private:
	// Reference ID of the Vertex Buffer Object
	GLuint m_ID = 0;

	// Indicates is the buffer ID has been generated
	bool m_isID = false;
};

#endif

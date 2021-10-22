#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

/// <summary>
/// Vertex Array Object.
/// Handles different type of data like vertices and color in one buffer
/// divided like an array.
/// </summary>
class VAO
{
public :
	
	/// <summary>
	/// Default VAO constructor.
	/// </summary>
	VAO() {}

	/// <summary>
	/// Links attributes to the buffer, like vertices and color.
	/// </summary>
	/// <param name="VBO">VBO : Vertex Buffer Object</param>
	/// <param name="layout">GLuint : index of the attribute (ex : 0 for vertices, 1 for color)</param>
	/// <param name="numComponents">GLuint : number of components (ex : a vertex has 3 GLfloat) </param>
	/// <param name="type">GLenum : specifies the data type of each component in the array (ex : GL_FLOAT, GL_INT...)</param>
	/// <param name="stride">GLsizeiptr : byte offset between consecutive vertex attributes</param>
	/// <param name="offset">void* : offset until the first component</param>
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

	/// <summary>
	/// Binds the vertex array.
	/// Makes it the current vertex array.
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the vertex array. Binds an empty vertex array.
	/// </summary>
	void Unbind();

	/// <summary>
	/// Deletes the vertex array and its content.
	/// </summary>
	void Delete();

private :

	// ID reference for the Vertex Array Object
	GLuint m_ID = 0;
	
	// Indicates if the buffer ID has been generated
	bool m_isID = false;

};
#endif

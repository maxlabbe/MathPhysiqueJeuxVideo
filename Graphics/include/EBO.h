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

	/// <summary>
	/// Links the buffer to indices
	/// </summary>
	/// <param name="indices">GLuint* : list of indices</param>
	/// <param name="size">GLsizeiptr : memory size of the list of indices (bytes)</param>
	void linkToIndices(GLuint* indices, GLsizeiptr size);

	/// <summary>
	/// Binds the element buffer. Makes it the current buffer of data.
	/// </summary>
	void Bind();

	/// <summary>
	/// Unbinds the element buffer. Binds an empty buffer.
	/// </summary>
	void Unbind();

	/// <summary>
	/// Deletes the buffer and its content.
	/// </summary>
	void Delete();

	// Getters 

	bool IsAllocated() { return m_isAllocated; }


private :

	// Reference ID of the Element Buffer Object
	GLuint m_ID = 0;

	// Indicates if the buffer ID has been generated
	bool m_isID = false;

	// Indicates if the buffer is already allocated
	bool m_isAllocated = false;
};

#endif

#ifndef DISPLAYABLE_LINE_H
#define DISPLAYABLE_LINE_H

#include <MathTools/Vector3D.h>
#include "Displayable.h"

class DisplayableLine : public Displayable
{
public :

	/// <summary>
	/// Displayables lines constructor
	/// </summary>
	/// <param name="start"> Vector3D : first line's point coordonates </param>
	/// <param name="end"> Vector3D : last line's point coordonates </param>
	/// <param name="color"> Vector3D : line's color's coordonates (0-1) </param>
	/// <param name="isStatic"> bool : is the line will have to move or not </param>
	DisplayableLine(Vector3D start, Vector3D end, Vector3D color, bool isStatic = false);

	/// <summary>
	/// Return the number of index of the line
	/// </summary>
	/// <returns> unsigned int : the number of index </returns>
	unsigned int GetIndexCount();

protected:

	/// <summary>
	/// Return the line's vertices
	/// </summary>
	/// <returns> GLfloat* : the line vertices</returns>
	GLfloat* GetVertices();

	/// <summary>
	/// Return the line's indices
	/// </summary>
	/// <returns> GLunit : the indices </returns>
	GLuint* GetIndices();

	/// <summary>
	/// Return the size of the verticies in memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the vertices </returns>
	GLsizeiptr GetSizeOfVertices();

	/// <summary>
	/// return the indices's size in memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the indices </returns>
	GLsizeiptr GetSizeOfIndices();

private :

	// Coordonates of the start point of the line
	Vector3D m_start;

	// Coordonates of the end point of the line
	Vector3D m_end;

	// Coordonates of the color of the line between 0 and 1
	Vector3D m_color;

	// Verticies of the line
	GLfloat m_vertices[12];

	// indices of the line
	GLuint m_indices[2];

};

#endif

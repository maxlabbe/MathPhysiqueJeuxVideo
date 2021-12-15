#ifndef DISPLAYABLEPLANE_H
#define DISPLAYABLEPLANE_H

#include"Plane.h"
#include"Displayable.h"

class DisplayablePlane : public Displayable
{
public :

	/// <summary>
	/// DisplayablePlane constructor
	/// </summary>
	/// <param name="plane">Plane : plane to display</param>
	/// <param name="color">Vector3D : color of the plane (rgb percentage)</param>
	DisplayablePlane(Plane& plane, Vector3D color = Vector3D(0.8, 0.4, 0));

	/// <summary>
	/// Give the number of index to draw the particle
	/// </summary>
	/// <returns> unisgned int : the number of index </returns>
	unsigned int GetIndexCount() { return 6; }

protected:

	/// <summary>
	/// Give the vertices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the vertices </returns>
	GLfloat* GetVertices() { return m_vertices; }

	/// <summary>
	/// Give the indices to draw the particle
	/// </summary>
	/// <returns> GLfloat* : the indices </returns>
	GLuint* GetIndices() { return m_indices;  }

	/// <summary>
	/// Give the size of the vertices in the memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the verticies </returns>
	GLsizeiptr GetSizeOfVertices() { return sizeof(GLfloat) * 24; }

	/// <summary>
	/// Give the size of the indicies in memory 
	/// </summary>
	/// <returns> GLsizeiptr : the size of the indicies </returns>
	GLsizeiptr GetSizeOfIndices() { return sizeof(GLuint) * 6; }

	void Delete() {}

private:

	Plane m_plane;
	Vector3D m_color;
	GLfloat m_vertices[24];
	GLuint m_indices[6];

};

#endif

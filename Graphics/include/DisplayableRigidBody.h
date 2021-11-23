#ifndef DISPLAYABLE_RIGIDBODY_H
#define DISPLAYABLE_RIGIDBODY_H

#include <RigidBody.h>
#include <Displayable.h>
#include <vector>

class DisplayableRigidBody : public Displayable
{
public:

	DisplayableRigidBody(RigidBody rigidbody, vector<int> edges);

protected :

	/// <summary>
	/// Give the vertices to draw the rigidbody
	/// </summary>
	/// <returns> GLfloat* : the vertices </returns>
	GLfloat* GetVertices();

	/// <summary>
	/// Give the indices to draw the rigidbody
	/// </summary>
	/// <returns> GLfloat* : the indices </returns>
	GLuint* GetIndices();

	/// <summary>
	/// Give the size of the vertices in the memory
	/// </summary>
	/// <returns> GLsizeiptr : the size of the verticies </returns>
	GLsizeiptr GetSizeOfVertices();

	/// <summary>
	/// Give the size of the indicies in memory 
	/// </summary>
	/// <returns> GLsizeiptr : the size of the indicies </returns>
	GLsizeiptr GetSizeOfIndices();

	void Delete() {}

private:

	// Rigidbody to display
	RigidBody m_rigidbody;

	// Indices of the edges of the rigidbody
	vector<int> m_edges;

	// Vertices of the rigidbody
	GLfloat* m_vertices;

	// Indices of the line of the rigidbody
	GLuint* m_indices;

	// Index count
	int m_indexCount;

};

/* Rectangle */
/* 
Vector3D length l, center c

{c.x - l.x / 2, c.y - l.y / 2, c.z - l.z / 2},
{c.x + l.x / 2, c.y - l.y / 2, c.z - l.z / 2},
{c.x + l.x / 2, c.y + l.y / 2, c.z - l.z / 2},
{c.x - l.x / 2, c.y + l.y / 2, c.z - l.z / 2},
{c.x - l.x / 2, c.y - l.y / 2, c.z + l.z / 2},
{c.x + l.x / 2, c.y - l.y / 2, c.z + l.z / 2},
{c.x + l.x / 2, c.y + l.y / 2, c.z + l.z / 2},
{c.x + l.x / 2, c.y + l.y / 2, c.z + l.z / 2},

Edges 

{
	0, 1,
	0, 4,
	0, 3,
	1, 5,
	1, 2,
	2, 6,
	2, 3,
	3, 7,
	4, 5,
	4, 7,
	5, 6,
	6, 8
}

*/

#endif

#include "DisplayableRigidBody.h"

DisplayableRigidBody::DisplayableRigidBody(RigidBody* rigidbody, vector<int> edges) : m_rigidbody(rigidbody), m_edges(edges)
{
	p_mode = GL_LINES;
	p_isStatic = false;
	// 3 Vertex + 3 color RGB
	m_vertices = new GLfloat[rigidbody->GetListSommet().size() * 6];
	// Indices
	m_indices = new GLuint[edges.size()];
	for (int i = 0 ; i < edges.size() ; i++)
	{
		m_indices[i] = edges[i];
	}
	m_indexCount = edges.size();
}


GLfloat* DisplayableRigidBody::GetVertices()
{
	list<Vector3D> vertexList = m_rigidbody->GetListSommet();
	int i = 0;
	for (list<Vector3D>::iterator vertexIt = vertexList.begin(); vertexIt != vertexList.end(); ++vertexIt) {
		// Vertex
		m_vertices[i++] = vertexIt->getX();
		m_vertices[i++] = vertexIt->getY();
		m_vertices[i++] = vertexIt->getZ();
		// Color RGB (white) (Redundant, we should do it only once)
		m_vertices[i++] = 0.9;
		m_vertices[i++] = 0.9;
		m_vertices[i++] = 0.9;
	}
	return m_vertices;
}

GLuint* DisplayableRigidBody::GetIndices()
{
	return m_indices;
}

GLsizeiptr DisplayableRigidBody::GetSizeOfVertices()
{
	return sizeof(GLfloat) * m_rigidbody->GetListSommet().size() * 6;
}

GLsizeiptr DisplayableRigidBody::GetSizeOfIndices()
{
	return sizeof(GLuint) * m_indexCount;
}
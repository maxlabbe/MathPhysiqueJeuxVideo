#include"DisplayableLine.h"

DisplayableLine::DisplayableLine(Vector3D start, Vector3D end, Vector3D color, bool isStatic)
{
	m_start = start;
	m_end = end;
	m_color = color;
	p_mode = GL_LINES;
	p_isStatic = isStatic;

	m_vertices[0] = start.getX(); m_vertices[1] = start.getY(); m_vertices[2] = start.getZ();
	m_vertices[3] = color.getX(); m_vertices[4] = color.getY(); m_vertices[5] = color.getZ();
	m_vertices[6] = end.getX(); m_vertices[7] = end.getY(); m_vertices[8] = end.getZ();
	m_vertices[9] = color.getX(); m_vertices[10] = color.getY(); m_vertices[11] = color.getZ();

	m_indices[0] = 0; m_indices[1] = 1;

}

unsigned int DisplayableLine::GetIndexCount()
{
	// There is only 2 index
	return 2;
}

GLfloat* DisplayableLine::GetVertices()
{
	return m_vertices;
}

GLuint* DisplayableLine::GetIndices()
{
	return m_indices;
}

GLsizeiptr DisplayableLine::GetSizeOfVertices()
{
	// there is 12 vertices
	return sizeof(GLfloat) * 12;
}

GLsizeiptr DisplayableLine::GetSizeOfIndices()
{
	// there is 2 index
	return sizeof(GLuint) * 2;
}
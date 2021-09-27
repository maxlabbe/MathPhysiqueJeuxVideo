#include"DisplayableLine.h"

DisplayableLine::DisplayableLine(Vector3D start, Vector3D end, Vector3D color)
{
	this->start = start;
	this->end = end;
	this->color = color;
	this->mode = GL_LINES;
	vertices[0] = start.getX(); vertices[1] = start.getY(); vertices[2] = start.getZ();
	vertices[3] = color.getX(); vertices[4] = color.getY(); vertices[5] = color.getZ();
	vertices[6] = end.getX(); vertices[7] = end.getY(); vertices[8] = end.getZ();
	vertices[9] = color.getX(); vertices[10] = color.getY(); vertices[11] = color.getZ();
	indices[0] = 0; indices[1] = 1;

}

unsigned int DisplayableLine::getIndexCount()
{
	return 2;
}

GLfloat* DisplayableLine::getVertices()
{
	return vertices;
}

GLuint* DisplayableLine::getIndices()
{
	return indices;
}

GLsizeiptr DisplayableLine::getSizeOfVertices()
{
	return sizeof(GLfloat) * 12;
}

GLsizeiptr DisplayableLine::getSizeOfIndices()
{
	return sizeof(GLuint) * 2;
}
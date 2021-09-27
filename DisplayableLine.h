#ifndef DISPLAYABLE_LINE_H
#define DISPLAYABLE_LINE_H

#include "Vector3D.h"
#include "Displayable.h"

class DisplayableLine : public Displayable
{
public :

	DisplayableLine(Vector3D start, Vector3D end, Vector3D color);
	unsigned int getIndexCount();

protected:

	GLfloat* getVertices();
	GLuint* getIndices();
	GLsizeiptr getSizeOfVertices();
	GLsizeiptr getSizeOfIndices();

private :

	Vector3D start;
	Vector3D end;
	Vector3D color;
	GLfloat vertices[12];
	GLuint indices[2];

};

#endif

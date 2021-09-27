#include"Displayable.h"

void Displayable::display()
{
	VAO.Bind();

	VBO.linkToVertices(getVertices(), getSizeOfVertices());
	EBO.linkToIndices(getIndices(), getSizeOfIndices());
	
	// Links VBO attributes such as coordinates and colors to VAO
	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Draw
	glDrawElements(mode, getIndexCount(), GL_UNSIGNED_INT, 0);
	// Unbind all to prevent accidentally modifying them
	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void Displayable::Delete()
{
	VAO.Delete();
	VBO.Delete();
	EBO.Delete();
}

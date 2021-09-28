#include"Displayable.h"

void Displayable::display()
{
	// Binds the Vertex Array = makes it the current to GL
	VAO.Bind();

	// Links the vertex buffer to the vertices (and binds it)
	VBO.linkToVertices(getVertices(), getSizeOfVertices());
	// Links the element buffer to the indices (and binds it)
	EBO.linkToIndices(getIndices(), getSizeOfIndices());
	
	// Links VBO attributes to the VAO, 
	// first the vertices coordinates (3 values),
	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	// then the colors of the vertices (3 values)
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// Draw the object using the currents binded buffers
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

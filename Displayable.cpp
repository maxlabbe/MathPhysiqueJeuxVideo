#include"Displayable.h"

void Displayable::display()
{
	// Binds the Vertex Array = makes it the current to GL
	p_VAO.Bind();

	// Links the vertex buffer to the vertices (and binds it)
	p_VBO.linkToVertices(getVertices(), getSizeOfVertices());
	// Links the element buffer to the indices (and binds it)
	p_EBO.linkToIndices(getIndices(), getSizeOfIndices());
	
	// Links VBO attributes to the VAO, 
	// first the vertices coordinates (3 values),
	p_VAO.LinkAttrib(p_VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	// then the colors of the vertices (3 values)
	p_VAO.LinkAttrib(p_VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	// Draw the object using the currents binded buffers
	glDrawElements(p_mode, getIndexCount(), GL_UNSIGNED_INT, 0);

	// Unbind all to prevent accidentally modifying them
	p_VAO.Unbind();
	p_VBO.Unbind();
	p_EBO.Unbind();
}

void Displayable::Delete()
{
	p_VAO.Delete();
	p_VBO.Delete();
	p_EBO.Delete();
}

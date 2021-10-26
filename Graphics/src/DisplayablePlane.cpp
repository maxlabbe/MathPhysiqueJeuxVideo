#include"DisplayablePlane.h"

DisplayablePlane::DisplayablePlane(Plane& plane, Vector3D color) : m_plane(plane), m_color(color)
{
	p_mode = GL_TRIANGLES;
	p_isStatic = true;
	
	m_indices[0] = 0; m_indices[1] = 1; m_indices[2] = 2;
	m_indices[3] = 0; m_indices[4] = 3; m_indices[5] = 2;

	m_vertices[0] = plane.GetUpLeft().getX(); m_vertices[1] = plane.GetUpLeft().getY(); m_vertices[2] = plane.GetUpLeft().getZ();
	m_vertices[3] = color.getX(); m_vertices[4] = color.getY(); m_vertices[5] = color.getZ();
	m_vertices[6] = plane.GetUpRight().getX(); m_vertices[7] = plane.GetUpRight().getY(); m_vertices[8] = plane.GetUpRight().getZ();
	m_vertices[9] = color.getX(); m_vertices[10] = color.getY(); m_vertices[11] = color.getZ();
	m_vertices[12] = plane.GetBottomRight().getX(); m_vertices[13] = plane.GetBottomRight().getY(); m_vertices[14] = plane.GetBottomRight().getZ();
	m_vertices[15] = color.getX(); m_vertices[16] = color.getY(); m_vertices[17] = color.getZ();
	m_vertices[18] = plane.GetBottomLeft().getX(); m_vertices[19] = plane.GetBottomLeft().getY(); m_vertices[20] = plane.GetBottomLeft().getZ();
	m_vertices[21] = color.getX(); m_vertices[22] = color.getY(); m_vertices[23] = color.getZ();
}
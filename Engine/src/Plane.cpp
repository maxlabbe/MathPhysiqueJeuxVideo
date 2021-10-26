#include"Plane.h"

Plane::Plane(int normal, Vector3D bottomLeft, Vector3D upRight)
{
	m_normal = normal;
	m_bottomLeft = bottomLeft;
	m_upRight = upRight;

	if (m_bottomLeft.getX() > m_upRight.getX())
	{
		int tmp = m_bottomLeft.getX();
		m_bottomLeft.set(m_upRight.getX(), m_bottomLeft.getY(), m_bottomLeft.getZ());
		m_upRight.set(tmp, m_upRight.getY(), m_upRight.getZ());
	}
	if (m_bottomLeft.getY() > m_upRight.getY())
	{
		int tmp = m_bottomLeft.getY();
		m_bottomLeft.set(m_bottomLeft.getX(), m_upRight.getY(), m_bottomLeft.getZ());
		m_upRight.set(m_upRight.getX(), tmp, m_upRight.getZ());
	}
	if (m_bottomLeft.getZ() > m_upRight.getZ())
	{
		int tmp = m_bottomLeft.getZ();
		m_bottomLeft.set(m_bottomLeft.getX(), m_bottomLeft.getY(), m_upRight.getZ());
		m_upRight.set(m_upRight.getX(), m_upRight.getY(), tmp);
	}

	switch (normal)
	{
		case 0:
			m_bottomRight = Vector3D(m_bottomLeft.getX(), m_upRight.getY(), m_bottomLeft.getZ());
			m_upLeft = Vector3D(m_bottomLeft.getX(), m_bottomLeft.getY(), m_upRight.getZ());
			break;
		case 1:
			m_bottomRight = Vector3D(m_bottomLeft.getX(), m_bottomLeft.getY(), m_upRight.getZ());
			m_upLeft = Vector3D(m_upRight.getX(), m_bottomLeft.getY(), m_bottomLeft.getZ());
			break;
		case 2:
			m_bottomRight = Vector3D(m_upRight.getX(), m_bottomLeft.getY(), m_bottomLeft.getZ());
			m_upLeft = Vector3D(m_bottomLeft.getX(), m_upRight.getY(), m_bottomLeft.getZ());
			break;
		default:
			break;
	}
}
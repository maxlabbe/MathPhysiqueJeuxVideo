#ifndef PLANE_H
#define PLANE_H

#include"Vector3D.h"

class Plane
{
public:

	/// <summary>
	/// Creates a rectangular plane with a normal and 2 points.
	/// The normal is one of the three axes x, y or z.
	/// </summary>
	/// <param name="normal">int : normal of the plane, 0 = x, 1 = y, 2 = z</param>
	/// <param name="bottomLeft">Vector3D : bottomLeft point of the rectangle</param>
	/// <param name="upRight">Vector3D : upRight point of the rectangle</param>
	Plane(int normal, Vector3D bottomLeft, Vector3D upRight);

	// Getters

	int GetNormal() { return m_normal; }
	Vector3D GetBottomLeft() { return m_bottomLeft; }
	Vector3D GetUpRight() { return m_upRight; }
	Vector3D GetUpLeft() { return m_upLeft; }
	Vector3D GetBottomRight() { return m_bottomRight; }

private:

	// int : normal of the plane, 0 = x, 1 = y, 2 = z
	int m_normal;

	// Bottom left corner of the rectangle
	Vector3D m_bottomLeft;

	// Up right corner of the rectangle
	Vector3D m_upRight;

	// Bottom right corner of the rectangle
	Vector3D m_bottomRight;

	// Up left corner of the rectangle
	Vector3D m_upLeft;

};

#endif

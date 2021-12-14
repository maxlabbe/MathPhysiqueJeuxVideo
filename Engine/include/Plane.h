#ifndef PLANE_H
#define PLANE_H

#include <MathTools/Vector3D.h>
#include <Primitive.h>

class Plane : public Primitive
{
public:

	/// <summary>
	/// Creates a rectangular plane with a normal an origin and 2 axes.
	/// </summary>
	/// <param name="normal">plane's normal</param>
	/// <param name="position">position of the origin of the plane</param>
	/// <param name="axesLength">length of the axes</param>
	Plane(Vector3D normal, Vector3D position, Vector3D height, Vector3D width, float offset, Matrix4 transformMatrix);

	// Getters
	Vector3D GetNormal() { return m_normal; }
	Vector3D GetPosition() { return m_position; }
	Vector3D GetAxesLength() { return m_height; }
	Vector3D GetUpLeft() { return m_position + m_height; };
	Vector3D GetUpRight() { return m_position + m_height + m_width; };
	Vector3D GetBottomLeft() { return m_position; };
	Vector3D GetBottomRight() { return m_position + m_width; };

	/// <summary>
	/// Give the distance of an object and the plane
	/// </summary>
	/// <param name="point"> The object that we want the distance from</param>
	/// <returns>float : the distance </returns>
	float GetDistance(Vector3D point);



private:

	// Vector3D : normal of the plane, 0 = x, 1 = y, 2 = z
	Vector3D m_normal;

	// Vector3D : position of the axe's origin point in reel world (0,0,0)
	Vector3D m_position;

	// Vector3D : height of the plane
	Vector3D m_height;

	// Vector3D : width of the plane
	Vector3D m_width;

	//Offset that sign the plane
	float m_offset;

};

#endif

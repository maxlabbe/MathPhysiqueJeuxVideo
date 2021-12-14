#ifndef OCTREE_H
#define OCTREE_H

#include <vector>

#include "Common.h"
#include "MathTools/Vector3D.h"
#include "BoundingSphere.h"

class Octree
{
private:

	// the structure for the bounds of an octree node
	typedef struct BoundsStruct {
		// center of the bounds
		Vector3D m_center;

		// half height of the bounds (y axis)
		float m_halfHeight;

		// half width of the bounds (x axis)
		float m_halfWidth;

		// depth of the bounds (z axis)
		float m_halfDepth;

		// check if the bounding sphere intersects with the bounds
		bool intersects(BoundingSphere* sphere)
		{
			Vector3D centerSphere = sphere->getCenter();
			return abs(m_center.getX() - centerSphere.getX()) < m_halfWidth + sphere->getRadius()
				&& abs(m_center.getY() - centerSphere.getY()) < m_halfHeight + sphere->getRadius()
				&& abs(m_center.getZ() - centerSphere.getZ()) < m_halfDepth + sphere->getRadius();
		}

		bool intersects(Plane* plane)
		{
			Vector3D halfSizes = plane->GetAxesLength().multiplyByScalar(0.5f);
			Vector3D centerPlane = plane->GetPosition() + halfSizes;
			return abs(m_center.getX() - centerPlane.getX()) < m_halfWidth + halfSizes.getX()
				&& abs(m_center.getY() - centerPlane.getY()) < m_halfHeight + halfSizes.getY()
				&& abs(m_center.getZ() - centerPlane.getZ()) < m_halfDepth + halfSizes.getZ();
		}
	} Bounds;

	// bounds
	Bounds m_bounds;

	// level of the node
	int m_level;

	// vector containing the node children
	vector<Octree*> m_children;

	// vector containing the objects
	vector<BoundingSphere*> m_objects;

	// vector containing the planes of the scene
	vector<Plane*> m_planes;

	// max number of object by node
	int const m_maxObjects = 5;

	// max number of level in the tree
	int const m_maxLevels = 10;

public:

	/// <summary>
	/// Ctor
	/// Create a personnalize octree with bounds
	/// </summary>
	/// <param name="level"> int: level depth of the node </param>
	/// <param name="bounds"> Bounds: bounds of the node </param>
	Octree(int level, Bounds bounds);

	/// <summary>
	/// Clear the node
	/// </summary>
	void clear();

	/// <summary>
	/// Insert a bounding sphere into the tree
	/// </summary>
	/// <param name="sphere"> BoundingSphere*: the bounding sphere to add to the tree </param>
	void insert(BoundingSphere* sphere);

	/// <summary>
	/// Split the node into 8 smaller nodes
	/// </summary>
	void split();

	/// <summary>
	/// Retrieve a vector of all the leaves containing objects
	/// </summary>
	/// <param name="returnedVector"> vector: vector containing the leaves of the tree </param>
	/// <returns> Vector containing the leaves with objects </returns>
	vector<Octree*> retreiveLeavesWithObjects(vector<Octree*> returnedVector);

	void AddPlane(Plane* plane);
};

#endif

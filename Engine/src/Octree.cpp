#include "Octree.h"

Octree::Octree(int level, Bounds bounds): m_level(level), m_bounds(bounds), m_children(vector<Octree*>()) {}

void Octree::clear()
{
	m_objects.clear();
	m_planes.clear();

	for (auto child : m_children)
	{
		if (child != nullptr)
		{
			child->clear();
		}
	}
	m_children.clear();
}

void Octree::insert(BoundingSphere* sphere)
{
	if (m_bounds.intersects(sphere))
	{
		if (m_children.empty())
		{
			if (m_objects.size() + m_planes.size() >= m_maxObjects && m_level < m_maxLevels)
			{
				split();

				for (auto child : m_children)
				{
					for (auto object : m_objects)
					{
						child->insert(object);
					}

					for (auto plane : m_planes)
					{
						child->AddPlane(plane);
					}

					child->insert(sphere);
				}
			}
			else
			{
				m_objects.push_back(sphere);
			}
		}
		else
		{
			for (auto child : m_children)
			{
				child->insert(sphere);
			}
		}
	}
}

void Octree::split()
{
	Vector3D center = m_bounds.m_center;
	float halfHeight = m_bounds.m_halfHeight/2.0f;
	float halfWidth = m_bounds.m_halfWidth/2.0f;
	float halfDepth = m_bounds.m_halfDepth/2.0f;

	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() + halfWidth, center.getY() + halfHeight, center.getZ() + halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() + halfWidth, center.getY() + halfHeight, center.getZ() - halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() + halfWidth, center.getY() - halfHeight, center.getZ() + halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() + halfWidth, center.getY() - halfHeight, center.getZ() - halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() - halfWidth, center.getY() + halfHeight, center.getZ() + halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() - halfWidth, center.getY() + halfHeight, center.getZ() - halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() - halfWidth, center.getY() - halfHeight, center.getZ() - halfDepth), halfHeight, halfWidth, halfDepth }));
	m_children.push_back(new Octree(m_level + 1, { Vector3D(center.getX() - halfWidth, center.getY() - halfHeight, center.getZ() + halfDepth), halfHeight, halfWidth, halfDepth }));
}

void Octree::retreiveLeavesWithObjects(vector<Octree*>& returnedVector)
{
	if (m_children.empty())
	{
		// if there is more than one object
		if (m_objects.size() > 0)
		{
			returnedVector.push_back(this);
		}
	}
	else
	{
		for (auto child : m_children)
		{
			child->retreiveLeavesWithObjects(returnedVector);
		}
	}
}

void Octree::AddPlane(Plane* plane)
{
	if (m_bounds.intersects(plane))
	{
		if (m_children.empty())
		{
			if (m_objects.size() + m_planes.size() >= m_maxObjects  && m_level < m_maxLevels)
			{
				split();

				for (auto child : m_children)
				{
					for (auto p : m_planes)
					{
						child->AddPlane(p);
					}

					child->AddPlane(plane);

					for (auto object : m_objects)
					{
						child->insert(object);
					}
				}
			}
			else
			{
				m_planes.push_back(plane);
			}
		}
		else
		{
			for (auto child : m_children)
			{
				child->AddPlane(plane);
			}
		}
	}
}

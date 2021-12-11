#include "Octree.h"

Octree::Octree(int level, Bounds bounds): m_level(level), m_bounds(bounds), m_children(vector<Octree*>()) {}

void Octree::clear()
{
	m_objects.clear();

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
			if (m_objects.size() >= m_maxObjects && m_level < m_maxLevels)
			{
				split();

				for (auto child : m_children)
				{
					for (auto object : m_objects)
					{
						child->insert(object);
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

vector<Octree*> Octree::retreiveLeavesWithObjects(vector<Octree*> returnedVector)
{
	if (m_children.empty())
	{
		if (!m_objects.empty())
		{
			returnedVector.push_back(this);
		}
	}
	else
	{
		vector<Octree*> tmp;

		for (auto child : m_children)
		{
			tmp = child->retreiveLeavesWithObjects(returnedVector);
			returnedVector.insert(tmp.end(), tmp.begin(), tmp.end());
		}
	}

	return returnedVector;
}

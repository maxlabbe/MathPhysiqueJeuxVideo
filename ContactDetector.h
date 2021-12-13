#pragma once
#include <Box.h>
#include <Plane.h>
#include <vector>
class ContactDetector
{
	static void DetectContacts(Box obj1, Plane obj2)
	{
		vector<Vector3D> listBoxVertices;
		float width = obj1.GetHalfSizes().getX();
		float height = obj1.GetHalfSizes().getY();
		float depth = obj1.GetHalfSizes().getZ();
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(-width, -height, -depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(+width, -height, -depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(+width, +height, -depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(-width, +height, -depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(-width, -height, +depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(+width, -height, +depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(+width, +height, +depth)));
		listBoxVertices.push_back(obj1.LocalToWorld(Vector3D(-width, +height, +depth)));

		vector<Vector3D> contacts;

		for (Vector3D point : listBoxVertices)
		{
			if (obj2.GetDistance(point) < 0)
			{
				contacts.push_back(point);
			}
		}

		//Une fois tous les point récuperer, on calcul le point de contact et on créer le contact.
	};
};


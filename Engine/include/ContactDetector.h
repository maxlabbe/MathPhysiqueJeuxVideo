#pragma once
#include <Box.h>
#include <Plane.h>
#include <Contact.h>
#include <CollisionData.h>
#include <vector>
class ContactDetector
{
public:

	static void GenerateContacts(Box box, Plane plane, CollisionData* contacts)
	{
		vector<Vector3D> listBoxVertices;
		float width = box.GetHalfSizes().getX();
		float height = box.GetHalfSizes().getY();
		float depth = box.GetHalfSizes().getZ();
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(-width, -height, -depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(+width, -height, -depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(+width, +height, -depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(-width, +height, -depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(-width, -height, +depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(+width, -height, +depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(+width, +height, +depth)));
		listBoxVertices.push_back(box.LocalToWorld(Vector3D(-width, +height, +depth)));

		
		for (Vector3D point : listBoxVertices)
		{
			float distance = plane.GetDistance(point);
			if (distance < 0)
			{
				Vector3D contactPoint(point + plane.GetNormal().multiplyByScalar(abs(distance)/2));
				Vector3D contactPointNormal = plane.GetNormal().multiplyByScalar(abs(distance) / 2);
				float interpenetration = abs(distance);
				Contact contact(contactPoint, contactPointNormal, interpenetration);
				contacts->AddContacts(contact);
			}
		}
		//Une fois tous les point récuperer, on calcul le point de contact et on créer le contact.
	};
};


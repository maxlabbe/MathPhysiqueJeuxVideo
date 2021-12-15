#pragma once
#include <Box.h>
#include <Plane.h>
#include <Contact.h>
#include <CollisionData.h>
#include <vector>
class ContactDetector
{
public:

	/// <summary>
	/// Generate a contact between a box and a plane when it detect one
	/// </summary>
	/// <param name="box">The box which is in contact with the plane</param>
	/// <param name="plane">The plane in contact with the box</param>
	/// <param name="contacts"> The data about the collision</param>
	static void GenerateContacts(Box box, Plane plane, CollisionData* contacts)
	{
		//Compute the vertices of the box
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

		// See which point of the box is in contact with the plane
		for (Vector3D point : listBoxVertices)
		{
			float distance = plane.GetDistance(point);

			// Let the box interpenetrate the plane a little bit to make the computation easier
			if (distance < 0)
			{
				Vector3D contactPoint(point + plane.GetNormal().multiplyByScalar(abs(distance)/2));
				Vector3D contactPointNormal = plane.GetNormal().multiplyByScalar(abs(distance) / 2);
				float interpenetration = abs(distance);
				Contact contact(contactPoint, contactPointNormal, interpenetration);
				contacts->AddContacts(contact);
			}
		}
	};
};


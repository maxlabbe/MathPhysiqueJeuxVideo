#pragma once

#include <list>
#include "Particle.h"
#include "Vector3D.h"/*
#include "Matrix3.h"
#include "Matrix4.h"
#include "Quaternion.h"
*/ // à ajouter quand elles seront créées


class RigidBody
{
private:

	Particle particle;
	list<Vector3D> listSommet;

public:

	void SetListSommet(list<Vector3D> sommets) { listSommet = sommets; }

	list<Vector3D> GetListSommet() { return listSommet; }


};


#ifndef RB_FORCEGENERATOR_H
#define RB_FORCEGENERATOR_H
#include <Common.h>
#include <RigidBody.h>
class IRB_ForceGenerator
{
private:
	//Vector3D m_applicationPoint;

public:
	/*Vector3D GetApplicationPoint();
	void SetApplicationPoint(Vector3D applicationPoint);*/
	virtual void updateForce(RigidBody* rigidBody, Vector3D apllicationPoint, float duration) = 0;
};

#endif
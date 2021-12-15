#ifndef LOGIC_H
#define LOGIC_H

#include<vector>
#include<chrono>
#include<set>

#include "Camera.h"
#include"InputsHandler.h"
#include"Display.h"
#include"World.h"
#include"DisplayablePlane.h"
#include"Displayable.h"
#include"DisplayableRigidBody.h"
#include"MathTools/Quaternion.h"
#include"RigidBody.h"
#include"ForceRegisterRigidBody.h"
#include"RB_GravityGenerator.h"
#include <Octree.h>
#include <ContactDetector.h>


class Logic
{
public :

	/// <summary>
	/// Logic constructor
	/// </summary>
	/// <param name="window"> window which the logic is call in </param>
	/// <param name="inputsHandler"> input that the logic need to update actions </param>
	Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display);

	/// <summary>
	/// Update the logic depend on the inuts
	/// </summary>
	void updateLogic();

	/// <summary>
	/// The camera of the scene
	/// </summary>
	/// <returns> Camera* : the scene's camera </returns>
	Camera* getCamera() { return m_camera; }

private :

	// The inputs 
	InputsHandler& m_inputsHandler;

	// The display
	Display& m_display;

	// The scene'window
	GLFWwindow* m_window;

	// The scene's camera
	Camera* m_camera;

	// Rigidbodies on scene
	vector<RigidBody*> m_rigidbodies;

	// Bounding spheres on scene
	vector<BoundingSphere*> m_boundingSpheres;
	
	vector<Displayable*>* m_displayables;

	// Force register
	ForceRegisterRigidBody m_forceRegister;

	// The last time the logic was update
	chrono::steady_clock::time_point m_lastTime;

	// flag if the rigtht click is the first one
	bool m_firstRightClick;

	// flag if the left click is the first one
	bool m_firstLeftClick;

	// flag that indicate if the little projectile is selected
	bool m_littleBody;

	// flag that indicate if the medium projectile is selected
	bool m_mediumBody;

	// flag that indicate if the big projectile is selected
	bool m_bigBody;

	// Planes that make the room
	vector<Plane*> m_planes;

	// Real collisions in the world
	vector<CollisionData*> m_collisions;

	bool m_collisionDetected = false;

	/// <summary>
	/// Move the camera
	/// </summary>
	void moveCamera();

	/// <summary>
	/// Update the type of projectile the player want
	/// </summary>
	void updateProjectileType();

	/// <summary>
	/// Shoot a projectile
	/// </summary>
	void shoot();

	/// <summary>
	/// Update the physic of the rigidbodies in the scene
	/// </summary>
	void updateBodies();

	/// <summary>
	/// Add a projectile of the projectile list
	/// </summary>
	/// <param name="initPos"> Vector3D : the initial position of the projectile </param>
	/// <param name="initVelocity"> Vector3D : the initial velocity of the projectile </param>
	/// <param name="gravity"> float : The gravity associated to the projectile</param>
	/// <param name="lifespan"> float : life in ms of the projectile </param>
	void addBody(Vector3D initPos, Vector3D linearVelocity, float height, float width, float depth, float mass, float gravity, float lifespan = 4000.0);

	void DetectAndDisplayCollision();

	void CreateBox()
	{
		Vector3D normal(0, 0, -1);
		Vector3D position(-20, -20, 20);
		Vector3D planeHeight(0, 40, 0);
		Vector3D planeWidth(40, 0, 0);
		float offset = 20;
		Plane* front = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());

		normal = Vector3D(1, 0, 0);
		position = Vector3D(-20, -20, -20);
		planeHeight = Vector3D(0, 40, 0);
		planeWidth = Vector3D(0, 0, 40);
		Plane* left = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());
		

		normal = Vector3D(0, 0, 1);
		position = Vector3D(20, -20, -20);
		planeHeight = Vector3D(0, 40, 0);
		planeWidth = Vector3D(-40, 0, 0);
		Plane* back = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());
		

		normal = Vector3D(-1, 0, 0);
		position = Vector3D(20, -20, 20);
		planeHeight = Vector3D(0, 40, 0);
		planeWidth = Vector3D(0, 0, -40);
		Plane* right = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());

		normal = Vector3D(0, -1, 0);
		position = Vector3D(-20, 20, 20);
		planeHeight = Vector3D(0, 0, -40);
		planeWidth = Vector3D(40, 0, 0);
		Plane* top = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());

		normal = Vector3D(0, 1, 0);
		position = Vector3D(-20, -20, -20);
		planeHeight = Vector3D(0, 0, 40);
		planeWidth = Vector3D(40, 0, 0);
		Plane* bottom = new Plane(normal, position, planeHeight, planeWidth, offset, Matrix4());
		

		m_planes.push_back(front);
		m_planes.push_back(left);
		m_planes.push_back(back);
		m_planes.push_back(right);
		m_planes.push_back(top);
		m_planes.push_back(bottom);

		m_displayables->push_back(new DisplayablePlane(*front, Vector3D(0.22, 0.32, 0.89)));
		m_displayables->push_back(new DisplayablePlane(*left, Vector3D(0.34, 0.88, 0.29)));
		m_displayables->push_back(new DisplayablePlane(*back, Vector3D(0.93, 0.21, 0.21)));
		m_displayables->push_back(new DisplayablePlane(*right, Vector3D(0.64, 0.42, 0.30)));
		m_displayables->push_back(new DisplayablePlane(*top, Vector3D(0.96, 0.44, 0.22)));
		m_displayables->push_back(new DisplayablePlane(*bottom, Vector3D(0.74, 0.25, 0.92)));
	}
};

#endif

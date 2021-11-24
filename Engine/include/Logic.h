#ifndef LOGIC_H
#define LOGIC_H

#include<vector>
#include<chrono>

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

};

#endif

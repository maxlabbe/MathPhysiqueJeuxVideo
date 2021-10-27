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

class Logic
{
public :

	/// <summary>
	/// Logic constructor
	/// </summary>
	/// <param name="window"> window which the logic is call in </param>
	/// <param name="inputsHandler"> input that the logic need to update actions </param>
	Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display, World& world);

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

	// The game world
	World m_world;

	// The last time the logic was update
	chrono::steady_clock::time_point m_lastTime;

	// flag if the rigtht click is the first one
	bool m_firstRightClick;

	// flag if the left click is the first one
	bool m_firstLeftClick;

	/// <summary>
	/// Move the camera
	/// </summary>
	void moveCamera();

	/// <summary>
	/// Update the game world
	/// </summary>
	void updateWorld(float duration);


};

#endif

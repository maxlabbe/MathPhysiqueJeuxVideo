#ifndef DISPLAY_H
#define DISPLAY_H


#include <vector>
#include "Particle.h"
#include"DisplayableLine.h"
#include"shaderClass.h"
#include"Camera.h"
#include<GLFW/glfw3.h>
#include"Logic.h"

class Display
{

public :

	/// <summary>
	/// Display constructor
	/// </summary>
	/// <param name="window"> GLFWwindow : window within the scene is displayed </param>
	/// <param name="camera"> Camera* : camera wich in the scene is displayed</param>
	/// <param name="logic"> Logic& : game logic to display </param>
	/// <param name="shader"> Shader& : shader that will draw the objects </param>
	Display(GLFWwindow* window, Camera* camera, Logic& logic, Shader& shader);

	/// <summary>
	/// Add a displayable object
	/// </summary>
	/// <param name=""> Displayable* : the displayable object </param>
	void addDisplayable(Displayable*);

	/// <summary>
	/// Update the display
	/// </summary>
	void updateDisplay();

private :

	// All displayable objects
	vector<Displayable*> m_displayables;

	// The window within the scene is displayed
	GLFWwindow* m_window;

	// The shaders that draw all the objects
	Shader m_shader;

	// Camera which on the scene is displayed
	Camera* m_camera;

	// The game logic
	Logic& m_logic;
};


#endif

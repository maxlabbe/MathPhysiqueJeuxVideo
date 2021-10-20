#ifndef DISPLAY_H
#define DISPLAY_H


#include <vector>
#include "Particle.h"
#include"DisplayableLine.h"
#include"shaderClass.h"
#include"Camera.h"
#include<GLFW/glfw3.h>

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
	Display(GLFWwindow* window, Shader& shader);

	/// <summary>
	/// Add a vector of displayables to the list of objects to display
	/// </summary>
	/// <param name=""> vector<Displayable*> : the displayables list </param>
	void AddDisplayables(vector<Displayable*>*);

	/// <summary>
	/// Remove the vector of displayables from the list of objects to display
	/// </summary>
	/// <param name=""></param>
	void RemoveDisplayables(vector<Displayable*>*);

	/// <summary>
	/// Update the display
	/// </summary>
	void UpdateDisplay();

	/// <summary>
	/// Delete all the objects (buffers, shaders) created. To call at the end of using the class.
	/// </summary>
	void ClearDisplay();

	/// Setters

	void setCamera(Camera* camera) { m_camera = camera; }


private :

	// All displayable objects
	vector<vector<Displayable*>*> m_displayables;

	// The window within the scene is displayed
	GLFWwindow* m_window;

	// The shaders that draw all the objects
	Shader m_shader;

	// Camera which on the scene is displayed
	Camera* m_camera;

};


#endif

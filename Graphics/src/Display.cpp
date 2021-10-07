#include <thread>

#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"
#include "Display.h"
#include "DisplayableParticle.h"
#include <mutex>

mutex displayables_mutex;

Display::Display(GLFWwindow* window, Camera* camera, Logic& logic, Shader& shader) : m_logic(logic), m_shader(shader)
{
	m_camera = camera;
	m_window = window;

	int width, height;
	

	/* Coordinate system */
	// x axis = red
	// y axis = green
	// z axis = blue
	DisplayableLine* dlx = new DisplayableLine(Vector3D(-1, 0, 0), Vector3D(1, 0, 0), Vector3D(0.9, 0.0, 0.0));
	addDisplayable(dlx);
	DisplayableLine* dly = new DisplayableLine(Vector3D(0, -1, 0), Vector3D(0, 1, 0), Vector3D(0.0, 0.9, 0.0));
	addDisplayable(dly);
	DisplayableLine* dlz = new DisplayableLine(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Vector3D(0.0, 0.0, 0.9));
	addDisplayable(dlz);
}

void Display::addDisplayable(Displayable* d)
{
	m_displayables.push_back(d);
}

void Display::updateDisplay()
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Clean the back buffer and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Tell OpenGL which Shader Program we want to use
	m_shader.Activate();

	// Update camera (FOV angle, nearPlane, farPlane, shader, shaderMatrixVarName)
	m_camera->Matrix(45.0f, 0.1f, 100.0f, m_shader, "camMatrix");

	// Iterates over all displayables and displays them
	for (auto it = std::begin(m_displayables); it != std::end(m_displayables); ++it)
	{
		(*it)->display();
	}

	// Iterates over all projectiles and displays them
	vector<Displayable*> projectiles = m_logic.getDisplayables();
	for (auto it = std::begin(projectiles); it != std::end(projectiles); ++it)
	{
		(*it)->display();
	}
	// Swap the back buffer with the front buffer
	glfwSwapBuffers(m_window);

	// Take care of all GLFW events
	glfwPollEvents();
	
}





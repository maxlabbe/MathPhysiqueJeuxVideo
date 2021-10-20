#include <thread>

#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"
#include "Display.h"
#include "DisplayableParticle.h"
#include <mutex>

mutex displayables_mutex;

Display::Display(GLFWwindow* window, Shader& shader) : m_shader(shader)
{
	m_window = window;

	int width, height;
	

	/* Coordinate system */
	// x axis = red
	// y axis = green
	// z axis = blue
	DisplayableLine* dlx = new DisplayableLine(Vector3D(-1, 0, 0), Vector3D(1, 0, 0), Vector3D(0.9, 0.0, 0.0), true);
	DisplayableLine* dly = new DisplayableLine(Vector3D(0, -1, 0), Vector3D(0, 1, 0), Vector3D(0.0, 0.9, 0.0), true);
	DisplayableLine* dlz = new DisplayableLine(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Vector3D(0.0, 0.0, 0.9), true);

	vector<Displayable*>* axes = new vector<Displayable*>;
	axes->push_back(dlx);
	axes->push_back(dly);
	axes->push_back(dlz);

	AddDisplayables(axes);
}

void Display::AddDisplayables(vector<Displayable*>* displayables)
{
	cout << "YES" << endl;
	m_displayables.push_back(displayables);
	for (vector<Displayable*>* d : m_displayables)
	{
		cout << d->size() << endl;
	}
}

void Display::RemoveDisplayables(vector<Displayable*>* displayables)
{
	remove(m_displayables.begin(), m_displayables.end(), displayables);
}

void Display::UpdateDisplay()
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
	for (auto vectors_it = std::begin(m_displayables); vectors_it != std::end(m_displayables); ++vectors_it)
	{
		for (auto displayables_it = std::begin(*(*vectors_it)); displayables_it != std::end(*(*vectors_it)); ++displayables_it)
		{
			(*displayables_it)->Display();
		}
	}

	// Swap the back buffer with the front buffer
	glfwSwapBuffers(m_window);

	// Take care of all GLFW events
	glfwPollEvents();
	
}

void Display::ClearDisplay() {
	for (auto vectors_it = std::begin(m_displayables); vectors_it != std::end(m_displayables); ++vectors_it)
	{
		for (auto displayables_it = std::begin(*(*vectors_it)); displayables_it != std::end(*(*vectors_it)); ++displayables_it)
		{
			(*displayables_it)->Delete();
		}
	}
	m_shader.Delete();
}





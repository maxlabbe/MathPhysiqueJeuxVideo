#include <thread>

#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"
#include "Display.h"
#include"InputsHandler.h"
#include "DisplayableParticle.h"
#include <mutex>

mutex displayables_mutex;

void Display::addDisplayable(Displayable* d)
{
	lock_guard<mutex> guard(displayables_mutex);
	displayables.push_back(d);
}

// Main loop
void Display::mainLoop()
{
	// Initialize GLFW
	glfwInit();
	// GLFW version : 3.3.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// GLFW profile : Core = modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a window (width, height, name, fullscreen, smthg_not_important)
	GLFWwindow* window = glfwCreateWindow(this->width, this->height, window_title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// Configures OpenGL
	gladLoadGL();

	// Area of the window where OpenGL renders
	glViewport(0, 0, this->width, this->height);

	// Generates Shader object using shaders files
	this->shader = Shader("noTex.vert", "noTex.frag");

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);
	
	this->inputs = InputsHandler(window, camera, this);

	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shader.Activate();
		// Handle camera
		inputs.handleInputs();
		camera->Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
		// Iterates over all displayables and displays them

		lock_guard<mutex> guard(displayables_mutex);
		for (auto it = std::begin(displayables); it != std::end(displayables); ++it)
		{
			(*it)->display();
		}
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
	// Delete all the objects we've created
	for (auto it = std::begin(displayables); it != std::end(displayables); ++it)
	{
		(*it)->Delete();
	}
	shader.Delete();
	// Delete window and terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();
}

// Constructor

Display::Display 
(
	unsigned int width, unsigned int height, 
	char * window_title, 
	string vertexShaderFile, 
	string fragmentShaderFile
)
{
	this->width = width;
	this->height = height;
	this->vertexShaderFile = vertexShaderFile;
	this->fragmentShaderFile = fragmentShaderFile;
	this->window_title = window_title;

	// Initialize the camera : width, height of screen, position, direction
	this->camera = new Camera(this->width, this->height, glm::vec3(0, 0, 0), glm::vec3(-2.0f, -2.0f, -5.0f), glm::vec3(0, 1, 0));
}

Camera* Display::GetCamera()
{
	return camera;
}

GLFWwindow* Display::GetWindow()
{
	return window;
}
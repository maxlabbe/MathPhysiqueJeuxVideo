#include <thread>

#include "Common.h"
#include "Vector3D.h"
#include "Particle.h"
#include "Display.h"
#include "DisplayableParticle.h"
#include <mutex>

mutex displayables_mutex;

void Display::addDisplayable(Displayable* d)
{
	lock_guard<mutex> guard(displayables_mutex);
	m_displayables.push_back(d);
}

// Main loop
void Display::mainLoop()
{
	bool firstRightClick = true;
	bool firstLeftClick = true;
	// Initialize GLFW
	glfwInit();
	// GLFW version : 3.3.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// GLFW profile : Core = modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(m_width, m_height, m_window_title, NULL, NULL);
	
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);

	// Configures OpenGL
	gladLoadGL();

	// Area of the window where OpenGL renders
	glViewport(0, 0, this->m_width, this->m_height);

	// Generates Shader object using shaders files
	this->m_shader = Shader("noTex.vert", "noTex.frag");

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(m_window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		m_shader.Activate();
		
		if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * m_camera->Orientation;
		}
		if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * -glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up));
		}
		if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * -m_camera->Orientation;
		}
		if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up));
		}
		if (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * m_camera->Up;
		}
		if (glfwGetKey(m_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		{
			m_camera->Position += m_camera->speed * -m_camera->Up;
		}

		
		if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{
			// Hides mouse cursor
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

			// Prevents camera from jumping on the first click
			if (firstRightClick)
			{
				glfwSetCursorPos(m_window, (m_camera->width / 2), (m_camera->height / 2));
				firstRightClick = false;
			}

			// Stores the coordinates of the cursor
			double mouseX;
			double mouseY;
			// Fetches the coordinates of the cursor
			glfwGetCursorPos(m_window, &mouseX, &mouseY);

			// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
			// and then "transforms" them into degrees 
			float rotX = m_camera->sensitivity * (float)(mouseY - (m_camera->height / 2)) / m_camera->height;
			float rotY = m_camera->sensitivity * (float)(mouseX - (m_camera->width / 2)) / m_camera->width;

			// Calculates upcoming vertical change in the Orientation
			glm::vec3 newOrientation = glm::rotate(m_camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up)));

			// Decides whether or not the next vertical Orientation is legal or not
			// TODO : correct
			/*if(!(glm::angle(newOrientation, Up) >= glm::radians(90.0f) || glm::angle(newOrientation, Up) <= glm::radians(-90.0f)))
			{
				Orientation = newOrientation;
			}*/
			m_camera->Orientation = newOrientation;

			// Rotates the Orientation left and right
			m_camera->Orientation = glm::rotate(m_camera->Orientation, glm::radians(-rotY), m_camera->Up);

			// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
			glfwSetCursorPos(m_window, (m_camera->width / 2), (m_camera->height / 2));
		}
		else if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
		{
			// Unhides cursor since camera is not looking around anymore
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			// Makes sure the next time the camera looks around it doesn't jump
			firstRightClick = true;
		}

		float g = 0.1f;
		if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			if (firstLeftClick)
			{
				firstLeftClick = false;
				Vector3D position(m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);
				Vector3D velocity(m_camera->Orientation.x, m_camera->Orientation.y, m_camera->Orientation.z);
				Particle p = Particle(1.0f, position, velocity, Vector3D(0, -1 * g, 0), 1.001f);
				DisplayableParticle* dp = new DisplayableParticle(p, 0.01f); // Radius = 1 cm, static = true;
				addDisplayable(dp);
				std::thread th(&Display::moveParticle, this, p);
				th.detach();
			}
		}

		if (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		{
			firstLeftClick = true;
		}

		m_camera->Matrix(45.0f, 0.1f, 100.0f, m_shader, "camMatrix");
		// Iterates over all displayables and displays them

		lock_guard<mutex> guard(displayables_mutex);
		for (auto it = std::begin(m_displayables); it != std::end(m_displayables); ++it)
		{
			(*it)->display();
		}
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(m_window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
	// Delete all the objects we've created
	for (auto it = std::begin(m_displayables); it != std::end(m_displayables); ++it)
	{
		(*it)->Delete();
	}
	m_shader.Delete();
	// Delete window and terminate GLFW
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

// Constructor

Display::Display
(
	unsigned int window_width,
	unsigned int window_height,
	char* window_title,
	char* vertexShaderFile,
	char* fragmentShaderFile
)
{
	m_width = window_width;
	m_height = window_height;
	m_camera = new Camera(window_width, window_height, glm::vec3(0, 0, 0), glm::vec3(-2.0f, -2.0f, -5.0f), glm::vec3(0, 1, 0));
	m_window_title = window_title;
	
}

Camera* Display::GetCamera()
{
	return m_camera;
}

GLFWwindow* Display::GetWindow()
{
	return m_window;
}

void Display::moveParticle(Particle& p)
{
	auto start = chrono::high_resolution_clock::now();
	auto veryStart = chrono::high_resolution_clock::now();
	auto current = chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diffTime = current - start;
	int pos_print_frequence = 1;
	int count = 0;
	while (diffTime.count() < 4000.0)
	{
		auto current = chrono::high_resolution_clock::now();
		std::chrono::duration<float, std::milli> currentTime = current - start;
		current = chrono::high_resolution_clock::now();
		diffTime = current - veryStart;
		float time = diffTime.count();
		if (time > 10)
		{
			p.integrate(currentTime.count()/1000);
			start = chrono::high_resolution_clock::now();
		}
		
		if (count > pos_print_frequence)
		{
			//start = chrono::high_resolution_clock::now();
			count = 0;
			Particle print_p = Particle(1.0f, p.getPosition(), Vector3D(), Vector3D(), 1.001f);
			DisplayableParticle* d_print_p = new DisplayableParticle(print_p, 0.01f, true); // Radius = 1 cm
			addDisplayable(d_print_p);
		}
		std::this_thread::sleep_for(30ms); // About 30 fps
		count++;
	}
}


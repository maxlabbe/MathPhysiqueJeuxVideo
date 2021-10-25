#include "Logic.h"

Logic::Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display, World& world) : m_window(window), m_inputsHandler(inputsHandler), m_display(display), m_world(world)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	m_camera = new Camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0, 1, 0));
	display.setCamera(m_camera);
	m_lastTime = chrono::high_resolution_clock::now();
	m_firstLeftClick = true;
	m_firstRightClick = true;

	// Planes (à mettre dans la classe World)
	vector<Displayable*>* planes = new vector<Displayable*>;
	DisplayablePlane* plane = new DisplayablePlane(m_world.GetPlane());
	//planes->push_back(plane);
	m_display.AddDisplayables(planes);

}

void Logic::updateLogic()
{
	moveCamera();
}

void Logic::moveCamera()
{
	// Move the camera forward if the forward input is true
	if (m_inputsHandler.MoveForward())
	{
		m_camera->position += m_camera->speed * m_camera->orientation;
	}

	// Move the camera backward if the backward input is true
	if (m_inputsHandler.MoveBack())
	{
		m_camera->position += m_camera->speed * -m_camera->orientation;
	}

	// Move the camera left if the left input is true
	if (m_inputsHandler.MoveLeft())
	{
		m_camera->position += m_camera->speed * -glm::normalize(glm::cross(m_camera->orientation, m_camera->up));
	}

	// Move the camera right if the right input is true
	if (m_inputsHandler.MoveRight())
	{
		m_camera->position += m_camera->speed * glm::normalize(glm::cross(m_camera->orientation, m_camera->up));
	}

	// Move the camera up if the up input is true
	if (m_inputsHandler.MoveUp())
	{
		m_camera->position += m_camera->speed * m_camera->up;
	}

	// Move the camera down if the down input is true
	if (m_inputsHandler.MoveDown())
	{
		m_camera->position += m_camera->speed * -m_camera->up;
	}

	// Allow direction modifications if the direction key is pressed
	if (m_inputsHandler.ChangeCameraDirection())
	{
		// Hides mouse cursor
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = m_camera->sensitivity * (float)(m_inputsHandler.getMouseY() - (m_camera->height / 2)) / m_camera->height;
		float rotY = m_camera->sensitivity * (float)(m_inputsHandler.getMouseX() - (m_camera->width / 2)) / m_camera->width;

		// Calculates upcoming vertical change in the orientation
		glm::vec3 newOrientation = glm::rotate(m_camera->orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_camera->orientation, m_camera->up)));

		m_camera->orientation = newOrientation;
		// Rotates the Orientation left and right
		m_camera->orientation = glm::rotate(m_camera->orientation, glm::radians(-rotY), m_camera->up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(m_window, (m_camera->width / 2), (m_camera->height / 2));
	}
}


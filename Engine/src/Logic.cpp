#include "Logic.h"

Logic::Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display, World& world) : m_window(window), m_inputsHandler(inputsHandler), m_display(display), m_world(world)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	m_camera = new Camera(width, height, glm::vec3(0.0f, 1.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0, 1, 0));
	display.setCamera(m_camera);
	m_lastTime = chrono::high_resolution_clock::now();
	m_firstLeftClick = true;
	m_firstRightClick = true;

	m_display.AddDisplayables(m_world.GetDisplayables());

}

void Logic::updateLogic()
{
	// Compute the difference between current time and the last time the physic was update
	auto current = chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diffTime = current - m_lastTime;

	moveCamera();
	updateWorld(diffTime.count());

	m_lastTime = current;
}

void Logic::moveCamera()
{
	Vector3D blobPos = m_world.getMainParticlePosition();
	glm::vec3 newCamPos = glm::vec3(blobPos.getX(), blobPos.getY(), blobPos.getZ());
	newCamPos = newCamPos - (m_camera->orientation * 10.0f);
	m_camera->position = newCamPos;

	//// Allow direction modifications if the direction key is pressed
	//if (m_inputsHandler.ChangeCameraDirection())
	//{

	//	// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
	//	// and then "transforms" them into degrees 
	//	float rotX = m_camera->sensitivity * (float)(m_inputsHandler.getMouseY() - (m_camera->height / 2)) / m_camera->height;
	//	float rotY = m_camera->sensitivity * (float)(m_inputsHandler.getMouseX() - (m_camera->width / 2)) / m_camera->width;

	//	// Calculates upcoming vertical change in the orientation
	//	glm::vec3 newOrientation = glm::rotate(m_camera->orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_camera->orientation, m_camera->up)));

	//	m_camera->orientation = newOrientation;
	//	// Rotates the Orientation left and right
	//	m_camera->orientation = glm::rotate(m_camera->orientation, glm::radians(-rotY), m_camera->up);

	//	// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
	//	glfwSetCursorPos(m_window, (m_camera->width / 2), (m_camera->height / 2));
	//}
}

void Logic::updateWorld(float duration)
{
	float mvtCoeff = 5;
	bool move = false;
	Vector3D newSpeed = Vector3D();
	Vector3D camUp = Vector3D(m_camera->up.x, m_camera->up.y, m_camera->up.z);
	Vector3D camDir = Vector3D(m_camera->orientation.x, m_camera->orientation.y, m_camera->orientation.z);

	// Move the blob

	// Move the camera forward if the forward input is true
	if (m_inputsHandler.MoveForward())
	{
		newSpeed = newSpeed + camDir;
		move = true;
	}
	// Move the camera backward if the backward input is true
	if (m_inputsHandler.MoveBack())
	{
		newSpeed = newSpeed - camDir;
		move = true;
	}
	// Move the camera left if the left input is true
	if (m_inputsHandler.MoveLeft())
	{
		newSpeed = newSpeed + (camUp.crossProduct(camDir));
		move = true;
	}
	// Move the camera right if the right input is true
	if (m_inputsHandler.MoveRight())
	{
		newSpeed = newSpeed - (camUp.crossProduct(camDir));
		move = true;
	}
	// Move the camera up if the up input is true
	if (m_inputsHandler.MoveUp())
	{
		newSpeed = newSpeed + camUp;
		move = true;
	}
	// Move the camera down if the down input is true
	if (m_inputsHandler.MoveDown())
	{
		newSpeed = newSpeed - camUp;
		move = true;
	}
	if (move)
	{
		newSpeed = newSpeed.normalize();
		m_world.moveMainParticle(mvtCoeff * newSpeed);
	}
	m_world.updateWorld(duration);
}

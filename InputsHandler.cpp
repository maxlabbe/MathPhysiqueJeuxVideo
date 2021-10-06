#include"InputsHandler.h"

InputsHandler::InputsHandler(GLFWwindow* window) : m_window(window)
{
	glfwGetWindowSize(m_window, &m_width, &m_height);

	m_keyA = false;
	m_keyW = false;
	m_keyS = false;
	m_keyD = false;
	m_keySpace = false;
	m_keyLeftCtrl = false;

	m_mouseButtonRight = false;
	m_mouseButtonLeft = false;
	m_firstRightClick = false;

	m_keyJ = false;
	m_keyK = true;
	m_keyL = false;
}

void InputsHandler::UpdateInputs()
{
	/* ####### Key Inputs ####### */
	m_keyW = (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS);
	m_keyA = (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS);
	m_keyS = (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS);
	m_keyD = (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS);
	m_keySpace = (glfwGetKey(m_window, GLFW_KEY_SPACE) == GLFW_PRESS);
	m_keyLeftCtrl = (glfwGetKey(m_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
	m_keyJ = (glfwGetKey(m_window, GLFW_KEY_J) == GLFW_PRESS);
	m_keyK = (glfwGetKey(m_window, GLFW_KEY_K) == GLFW_PRESS);
	m_keyL = (glfwGetKey(m_window, GLFW_KEY_L) == GLFW_PRESS);

	/* ####### Mouse Inputs ####### */
	// Fetches the coordinates of the cursor
	glfwGetCursorPos(m_window, &m_mouseX, &m_mouseY);

	// Handle right click
	m_mouseButtonRight = (glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS);
	
	// Handle left click
	m_mouseButtonLeft =	(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);

	// Fetches the coordinates of the cursor
	glfwGetCursorPos(m_window, &m_mouseX, &m_mouseY);
}

bool InputsHandler::MoveForward()
{
	return m_keyW;
}

bool InputsHandler::MoveBack()
{
	return m_keyS;
}

bool InputsHandler::MoveUp()
{
	return m_keySpace;
}

bool InputsHandler::MoveDown()
{
	return m_keyLeftCtrl;
}

bool InputsHandler::MoveLeft()
{
	return m_keyA;
}

bool InputsHandler::MoveRight()
{
	return m_keyD;
}

bool InputsHandler::pressJ()
{
	return m_keyJ;
}
bool InputsHandler::pressK()
{
	return m_keyK;
}
bool InputsHandler::pressL()
{
	return m_keyL;
}

bool InputsHandler::ChangeCameraDirection()
{
	return m_mouseButtonRight;
}



bool InputsHandler::pressLeft()
{
	return m_mouseButtonLeft;
}

bool InputsHandler::pressRight()
{
	return m_mouseButtonRight;
}

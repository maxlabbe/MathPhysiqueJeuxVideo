#include"InputsHandler.h"
#include"Display.h"
#include"DisplayableParticle.h"

// InputsHandler::InputsHandler(Display* display) : display(display) {}
InputsHandler::InputsHandler(GLFWwindow* window, Camera* camera, Display* display) : window(window), camera(camera), display(display) {}

void InputsHandler::handleInputs()
{
	handleKeyInputs();
	handleRightClick();
	handleLeftClick();
}

void InputsHandler::handleKeyInputs()
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera->Position += camera->speed * camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->Position += camera->speed * -glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->Position += camera->speed * -camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->Position += camera->speed * glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		camera->Position += camera->speed * camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		camera->Position += camera->speed * -camera->Up;
	}
}

void InputsHandler::handleRightClick()
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		// Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (firstRightClick)
		{
			glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
			firstRightClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = camera->sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
		float rotY = camera->sensitivity * (float)(mouseX - (camera->width / 2)) / camera->width;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(camera->Orientation,camera->Up)));

		// Decides whether or not the next vertical Orientation is legal or not
		// TODO : correct
		/*if(!(glm::angle(newOrientation, Up) >= glm::radians(90.0f) || glm::angle(newOrientation, Up) <= glm::radians(-90.0f)))
		{
			Orientation = newOrientation;
		}*/
		camera->Orientation = newOrientation;

		// Rotates the Orientation left and right
		camera->Orientation = glm::rotate(camera->Orientation, glm::radians(-rotY), camera->Up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		firstRightClick = true;
	}
}

void InputsHandler::handleLeftClick()
{
	float g = 0.1f;
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		if (firstLeftClick)
		{
			firstLeftClick = false;
			Vector3D position(camera->Position.x, camera->Position.y, camera->Position.z);
			Vector3D velocity(camera->Orientation.x, camera->Orientation.y, camera->Orientation.z);
			Particle p = Particle(1.0f, position, velocity, Vector3D(0, -1 * g, 0), 1.001f);
			DisplayableParticle* dp = new DisplayableParticle(p, 0.01f, true); // Radius = 1 cm, static = true;
			display->addDisplayable(dp);
			cout << "Click " << position << " " << velocity << endl;
		}
		
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		firstLeftClick = true;
	}
}
#include "Logic.h"

Logic::Logic(GLFWwindow* window, InputsHandler& inputsHandler) : m_window(window), m_inputsHandler(inputsHandler)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	m_camera = new Camera(width, height, glm::vec3(2.0f, 1.0f, 2.0f), glm::vec3(-2.0f, -2.0f, -5.0f), glm::vec3(0, 1, 0));
	m_lastTime = chrono::high_resolution_clock::now();
	m_firstLeftClick = true;
	m_firstRightClick = true;
	m_littleProjectile = true;
	m_mediumProjectile = false;
	m_bigProjectile = false;
}

void Logic::updateLogic()
{
	moveCamera();
	updateProjectileType();
	shoot();
	updateProjectiles();
}

vector<Displayable*> Logic::getDisplayables()
{
	vector<Displayable*> displayables;
	for (Projectile projectile : m_projectiles)
	{
		for (Displayable* displayable : projectile.getTrace())
			displayables.push_back(displayable);
	}
	return displayables;
}

void Logic::moveCamera()
{
	if (m_inputsHandler.MoveForward())
	{
		m_camera->Position += m_camera->speed * m_camera->Orientation;
	}
	if (m_inputsHandler.MoveBack())
	{
		m_camera->Position += m_camera->speed * -m_camera->Orientation;
	}
	if (m_inputsHandler.MoveLeft())
	{
		m_camera->Position += m_camera->speed * -glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up));
	}
	if (m_inputsHandler.MoveRight())
	{
		m_camera->Position += m_camera->speed * glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up));
	}
	if (m_inputsHandler.MoveUp())
	{
		m_camera->Position += m_camera->speed * m_camera->Up;
	}
	if (m_inputsHandler.MoveDown())
	{
		m_camera->Position += m_camera->speed * -m_camera->Up;
	}
	if (m_inputsHandler.ChangeCameraDirection())
	{
		// Hides mouse cursor
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = m_camera->sensitivity * (float)(m_inputsHandler.getMouseY() - (m_camera->height / 2)) / m_camera->height;
		float rotY = m_camera->sensitivity * (float)(m_inputsHandler.getMouseX() - (m_camera->width / 2)) / m_camera->width;
		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(m_camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_camera->Orientation, m_camera->Up)));
		// Decides whether or not the next vertical Orientation is legal or not
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
}

void Logic::updateProjectileType()
{
	if (m_inputsHandler.pressJ())
	{
		m_littleProjectile = true;
		m_mediumProjectile = false;
		m_bigProjectile = false;
	}
	if (m_inputsHandler.pressK())
	{
		m_littleProjectile = false;
		m_mediumProjectile = true;
		m_bigProjectile = false;
	}
	if (m_inputsHandler.pressL())
	{
		m_littleProjectile = false;
		m_mediumProjectile = false;
		m_bigProjectile = true;
	}
}

void Logic::shoot()
{
	if (m_inputsHandler.pressLeft())
	{
		if (m_firstLeftClick)
		{
			m_firstLeftClick = false;
			Vector3D position(m_camera->Position.x, m_camera->Position.y, m_camera->Position.z);
			Vector3D velocity(m_camera->Orientation.x, m_camera->Orientation.y, m_camera->Orientation.z);
			float gravity = 0;
			cout << m_littleProjectile;
			if (m_littleProjectile)
			{
				velocity = velocity.multiplyByScalar(0.5);
				gravity = 1.0f;
			}

			if (m_mediumProjectile)
			{
				gravity = 0.2f;
			}

			if (m_bigProjectile)
			{
				velocity = velocity.multiplyByScalar(0.1f);
				gravity = 0.4f;
			}

			addProjectile(position, velocity, gravity);
		}
		
	} 
	else
	{
		m_firstLeftClick = true;
	}
}

void Logic::updateProjectiles()
{
	auto current = chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diffTime = current - m_lastTime;

	if (diffTime.count() > 16.0f)
	{
		for (auto it = std::begin(m_projectiles); it != std::end(m_projectiles); ++it)
		{
			(*it).update(diffTime.count());
		}
		m_lastTime = current;
	}
}

void Logic::addProjectile(Vector3D initPos, Vector3D initVelocity, float gravity, float lifespan)
{
	Projectile p(initPos, initVelocity, gravity, lifespan);
	m_projectiles.push_back(p);
}


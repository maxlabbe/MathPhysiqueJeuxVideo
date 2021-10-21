#include "Logic.h"

Logic::Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display) : m_window(window), m_inputsHandler(inputsHandler), m_display(display)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	m_camera = new Camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0, 1, 0));
	display.setCamera(m_camera);
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

void Logic::updateProjectileType()
{
	// Select the litle projectile if J is press
	if (m_inputsHandler.pressJ())
	{
		m_littleProjectile = true;
		m_mediumProjectile = false;
		m_bigProjectile = false;
	}

	// Select the medium projectile if K is press
	if (m_inputsHandler.pressK())
	{
		m_littleProjectile = false;
		m_mediumProjectile = true;
		m_bigProjectile = false;
	}

	// Select the big projectile if L is press
	if (m_inputsHandler.pressL())
	{
		m_littleProjectile = false;
		m_mediumProjectile = false;
		m_bigProjectile = true;
	}
}

void Logic::shoot()
{
	// If the mousse's left button is press create a projectile
	if (m_inputsHandler.pressLeft())
	{
		// Avoid the creation of other projectile of the button is hold
		if (m_firstLeftClick)
		{
			m_firstLeftClick = false;

			// The projectile start with the position of the camera and a velocity in the same direction of the camera
			Vector3D position(m_camera->position.x, m_camera->position.y, m_camera->position.z);
			Vector3D velocity(m_camera->orientation.x, m_camera->orientation.y, m_camera->orientation.z);

			float gravity = 0;

			// Change velocity and gravity depend on the projectile's type
			if (m_littleProjectile)
			{
				velocity = 4.0 * velocity;
				gravity = 0.5f;
			}
			if (m_mediumProjectile)
			{
				velocity = 2.0 * velocity;
				gravity = 1.0f;
			}
			if (m_bigProjectile)
			{
				velocity = 1 * velocity;
				gravity = 2.0f;
			}
			cout << "Position initiale : " << position << " | Vitesse initiale : " << velocity << " : " << velocity.norm() << " m/s" << endl;
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
	// Compute the difference between current time and the last time the physic was update
	auto current = chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diffTime = current - m_lastTime;
	
	// Update the physic of each projectile
	for (auto it = std::begin(m_projectiles); it != std::end(m_projectiles); ++it)
	{
		(*it).update(diffTime.count());
	}
	m_lastTime = current;
}

void Logic::addProjectile(Vector3D initPos, Vector3D initVelocity, float gravity, float lifespan)
{
	Projectile p(initPos, initVelocity, gravity, lifespan);
	
	if (m_projectiles.size() > 9) {
		for (Displayable* d : *(*m_projectiles.begin()).getTrace())
		{
			d->Delete();
		}
		m_display.RemoveDisplayables((*m_projectiles.begin()).getTrace());
		m_projectiles.erase(m_projectiles.begin());
	}
			
	m_projectiles.push_back(p);
	m_display.AddDisplayables(p.getTrace());
}


#include "Logic.h"

Logic::Logic(GLFWwindow* window, InputsHandler& inputsHandler, Display& display) : m_window(window), m_inputsHandler(inputsHandler), m_display(display)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	m_camera = new Camera(width, height, glm::vec3(0.0f, 1.0f, 10.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0, 1, 0));
	display.setCamera(m_camera);
	m_lastTime = chrono::high_resolution_clock::now();
	m_firstLeftClick = true;
	m_firstRightClick = true;

	m_displayables = new vector<Displayable*>();
	m_display.AddDisplayables(m_displayables);
}

void Logic::updateLogic()
{
	moveCamera();
	updateProjectileType();
	shoot();
	updateBodies();
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
		m_littleBody = true;
		m_mediumBody = false;
		m_bigBody = false;
	}

	// Select the medium projectile if K is press
	if (m_inputsHandler.pressK())
	{
		m_littleBody = false;
		m_mediumBody = true;
		m_bigBody = false;
	}

	// Select the big projectile if L is press
	if (m_inputsHandler.pressL())
	{
		m_littleBody = false;
		m_mediumBody = false;
		m_bigBody = true;
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
			Vector3D linearVelocity(m_camera->orientation.x, m_camera->orientation.y, m_camera->orientation.z);
			float height = 1;
			float width = 1; 
			float depth = 1; 
			float mass = 1;  
			float gravity = 1;

			// Change velocity and gravity depend on the projectile's type
			if (m_littleBody)
			{
				linearVelocity = 2 * linearVelocity;
				height = 1;
				width = 1;
				depth = 1;
				mass = 1;
				gravity = 1;
			}
			if (m_mediumBody)
			{
				linearVelocity = 4 * linearVelocity;
				height = 2;
				width = 2;
				depth = 2;
				mass = 5;
				gravity = 1;
			}
			if (m_bigBody)
			{
				linearVelocity = 1.0f * linearVelocity;
				height = 3;
				width = 3;
				depth = 3;
				mass = 10;
				gravity = 1;
			}
			cout << "Position initiale : " << position << " | Vitesse initiale : " << linearVelocity << " : " << linearVelocity.norm() << " m/s" << endl;
			addBody(position, linearVelocity, height, width, depth, mass, gravity);
		}

	}
	else
	{
		m_firstLeftClick = true;
	}
}

void Logic::updateBodies()
{
	// Compute the difference between current time and the last time the physic was update
	auto current = chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diffTime = current - m_lastTime;

	// Update the physic each 16ms (1/60)
	if (diffTime.count() > 16.0f)
	{
		// Update the physic of each projectile
		for (auto it = std::begin(m_rigidbodies); it != std::end(m_rigidbodies); ++it)
		{
			(*it)->updateValues(diffTime.count()/1000.0f);

			Particle* massCenter = new Particle((*it)->GetMass(), (*it)->GetMassCenter(), Vector3D(), Vector3D(), Vector3D(), 0.1);
			Displayable* displayableCenter = new DisplayableParticle(*massCenter);
			m_displayables->push_back(displayableCenter);
		}
		m_lastTime = current;
	}

}

void Logic::addBody(Vector3D initPos, Vector3D linearVelocity, float height, float width, float depth, float mass, float gravity, float lifespan)
{
	Vector3D angularVelocity(1.0f, 0, 0);
	Quaternion initialOrientation(1, 0, 0 ,0);
	array<array<float, 3>, 3> inertiaMatrix;

	inertiaMatrix[0] = { (1.0f / 12.0f) * mass * (height * height + depth * depth), 0 ,0 };
	inertiaMatrix[1] = { 0, (1.0f / 12.0f) * mass * (height * height + width * width) , 0 };
	inertiaMatrix[2] = { 0 , 0, (1.0f / 12.0f) * mass * (height * height + width * width) };
	Matrix3 inertiaTensor(inertiaMatrix);


	RigidBody* body = new RigidBody(height, width, depth, mass, initPos, linearVelocity, angularVelocity, initialOrientation,inertiaTensor, 1.0f, 1.0f);

	m_rigidbodies.push_back(body);

	vector<int> edges = {
		0, 1,
		0, 4,
		0, 3,
		1, 5,
		1, 2,
		2, 6,
		2, 3,
		3, 7,
		4, 5,
		4, 7,
		5, 6,
		6, 7
	};

	Displayable* displayableRigidBody = new DisplayableRigidBody(body, edges);
	m_displayables->push_back(displayableRigidBody);
	
	/*Projectile p(initPos, initVelocity, gravity, lifespan);
	if (m_projectiles.size() > 9)
		m_projectiles.erase(m_projectiles.begin());
	m_projectiles.push_back(p);*/
}
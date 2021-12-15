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
	m_planes = vector<Plane*>();
	CreateBox();
	m_display.AddDisplayables(m_displayables);
	m_boundingSpheres = vector<BoundingSphere*>();
	m_forceRegister = ForceRegisterRigidBody();
	vector<CollisionData*> m_collisions;
}

void Logic::updateLogic()
{
	moveCamera();
	
	// On arrèrte la simulation si une collision est détecter
	if (!m_collisionDetected)
	{
		updateProjectileType();
		shoot();
		updateBodies();
		DetectAndDisplayCollision();
	}
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
				gravity = 0.1;
			}
			if (m_mediumBody)
			{
				linearVelocity = 4 * linearVelocity;
				height = 2;
				width = 2;
				depth = 2;
				mass = 5;
				gravity = 0.1;
			}
			if (m_bigBody)
			{
				linearVelocity = 1.0f * linearVelocity;
				height = 3;
				width = 3;
				depth = 3;
				mass = 10;
				gravity = 0.1;
			}
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

	m_forceRegister.updateAllForces(diffTime.count() / 1000.0f);

	// Update the physic each 16ms (1/60)
	if (diffTime.count() > 16.0f)
	{
		// Update the physic of each projectile
		for (auto it = std::begin(m_rigidbodies); it != std::end(m_rigidbodies); ++it)
		{
			(*it)->updateValues(diffTime.count()/1000.0f);

			//Particle* massCenter = new Particle((*it)->GetMass(), (*it)->GetMassCenter(), Vector3D(), Vector3D(), Vector3D(), 0.1);
			//Displayable* displayableCenter = new DisplayableParticle(*massCenter);
			//m_displayables->push_back(displayableCenter);
		}
		m_lastTime = current;
	}

}

void Logic::addBody(Vector3D initPos, Vector3D linearVelocity, float height, float width, float depth, float mass, float gravity, float lifespan)
{
	//Create the attribut of the rigidbody
	Vector3D angularVelocity(1.0f, 1.0f, 0);
	Quaternion initialOrientation(1, 0, 0 ,0);
	array<array<float, 3>, 3> inertiaMatrix;

	inertiaMatrix[0] = { (1.0f / 12.0f) * mass * (height * height + depth * depth), 0 ,0 };
	inertiaMatrix[1] = { 0, (1.0f / 12.0f) * mass * (height * height + width * width) , 0 };
	inertiaMatrix[2] = { 0 , 0, (1.0f / 12.0f) * mass * (height * height + width * width) };
	Matrix3 inertiaTensor(inertiaMatrix);
	list<Vector3D> m_listSummit;

	// List of the vertices to draw the object
	m_listSummit.push_back(Vector3D( - width / 2,  - height / 2, - depth / 2));
	m_listSummit.push_back(Vector3D( + width / 2,  - height / 2, - depth / 2));
	m_listSummit.push_back(Vector3D( + width / 2,  + height / 2, - depth / 2));
	m_listSummit.push_back(Vector3D( - width / 2,  + height / 2, - depth / 2));
	m_listSummit.push_back(Vector3D( - width / 2,  - height / 2, + depth / 2));
	m_listSummit.push_back(Vector3D( + width / 2,  - height / 2, + depth / 2));
	m_listSummit.push_back(Vector3D( + width / 2,  + height / 2, + depth / 2));
	m_listSummit.push_back(Vector3D( - width / 2,  + height / 2, + depth / 2));

	RigidBody* body = new RigidBody(m_listSummit, mass, initPos, linearVelocity, angularVelocity, initialOrientation,inertiaTensor, 1.0f, 1.0f);

	// Create the bounding spher for the narrow phase
	BoundingSphere* boundingSphere = new BoundingSphere(body);

	//Add the objects and tools to the logic
	m_rigidbodies.push_back(body);
	m_boundingSpheres.push_back(boundingSphere);
	RB_GravityGenerator* gravityGen = new RB_GravityGenerator(gravity);
	m_forceRegister.registerForce(body, &body->GetMassCenter(), gravityGen);

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
}

void Logic::DetectAndDisplayCollision()
{
	// first level of the octree
	int firstLevel = 1;

	//Create the octree with larger boundaries than those of the scene
	Octree octree(firstLevel, { Vector3D(), 30.0f, 30.0f, 30.0f });
	
	// Add the planes to the octree
	for (Plane* plane : m_planes)
	{
		octree.AddPlane(plane);
	}

	// Add the bounding spheres to the octree
	for (BoundingSphere* boundingSphere : m_boundingSpheres)
	{
		octree.insert(boundingSphere);
	}

	// Take the octree's leaves
	vector<Octree*> octreeLeaves;
	octree.retreiveLeavesWithObjects(octreeLeaves);

	// For each leaf we detect if there is a pseudo collision
	vector<pair<Box*, Plane*>> pseudoCollisions;
	for (auto leaf : octreeLeaves)
	{
		for (BoundingSphere* sphere : leaf->GetBoundingSpheres())
		{
			for (Plane* plane : leaf->GetPlanes())
			{
				if (sphere->collides(plane))
				{
					Box* box = new Box(sphere->getRigidBody(), sphere->getRigidBody()->GetIdentityMatrix(), *std::next(sphere->getRigidBody()->GetListSommet().begin(), 6));
					pseudoCollisions.push_back(pair<Box*, Plane*>(box, plane));
				}
			}
		}
	}

	// Create a contacts for each real collision detected
	for (auto pseudoCollision : pseudoCollisions)
	{
		CollisionData* collisionData = new CollisionData();
		ContactDetector::GenerateContacts(*pseudoCollision.first, *pseudoCollision.second, collisionData);
		m_collisions.push_back(collisionData);
	}

	// Display the contacts
	for (auto collision : m_collisions)
	{
		for (auto contact : collision->GetContacts())
		{
			contact.DisplayContact();
			m_collisionDetected = true;
		}
	}

	// Clear the tools to detect contact
	octree.clear();
	octreeLeaves.clear();
	m_collisions.clear();
}
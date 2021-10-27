#include"World.h"

World::World(Plane& plane) : m_plane(plane) 
{
	DisplayablePlane* dPlane = new DisplayablePlane(plane);
	m_displayables = new vector<Displayable*>;
	//m_displayables->push_back(dPlane);

	m_forceRegister = ForceRegister();
	createBlob(1.0, 0.1, 0.1, 5.0, 1.0);
	m_detector = ColisionDetector(m_blob, vector<ParticleLink>());

}

void World::createBlob(float gravity, float dragK1, float dragK2, float springK, float springL)
{
	Particle* p1 = new Particle(1.0f, Vector3D(0, 0, 0), Vector3D(0, 20, 0), Vector3D(), Vector3D());

	// Special color for the main particle
	m_blob.push_back(p1);
	DisplayableParticle* dp = new DisplayableParticle(*p1, false, new Vector3D(0.6, 0.6, 0.6));
	m_displayables->push_back(dp);


	Particle* p2 = new Particle(5.0f, Vector3D(0, 0, 2), Vector3D(), Vector3D(), Vector3D());
	Particle* p3 = new Particle(1.0f, Vector3D(-1, 1.5, 1), Vector3D(), Vector3D(), Vector3D());
	//Particle* p4 = new Particle(1.0f, Vector3D(1, 1, -1), Vector3D(), Vector3D(), Vector3D());
	//Particle* p5 = new Particle(1.0f, Vector3D(1, 2, -1), Vector3D(), Vector3D(), Vector3D());
	AddParticle(p2);
	AddParticle(p3);
	/*AddParticle(p4);
	AddParticle(p5);*/

	for (Particle* particle1 : m_blob)
	{
		// Drag force
		DragGenerator* drag = new DragGenerator(dragK1, dragK2);
		m_forceRegister.registerForce(particle1, drag);
		// Gravity force
		GravityGenerator* gravityGen = new GravityGenerator(gravity);
		//m_forceRegister.registerForce(particle1, gravityGen);
		// Particle spring force
		for (Particle* particle2 : m_blob)
		{
			if (particle1 != particle2)
			{
				ParticleSpring* ps12 = new ParticleSpring(*particle2, springK, springL);
				m_forceRegister.registerForce(particle1, ps12);
			}
		}
	}	

	m_mainParticle = p1;
}

void World::moveMainParticle(Vector3D velocity)
{
	m_mainParticle->setVelocity(velocity);
}

void World::updateWorld(float duration)
{
	m_forceRegister.updateAllForces(duration/1000);
	
	for (Particle* particle : m_blob)
	{
		particle->integrate(duration/1000);
	}
	detecteAndResolveColisions(duration / 1000);
}

void World::AddParticle(Particle* particle) 
{
	m_blob.push_back(particle);
	DisplayableParticle* dp = new DisplayableParticle(*particle);
	m_displayables->push_back(dp);
}

void World::detecteAndResolveColisions(float duration)
{
	ColisionDetector colisionDetector = ColisionDetector(m_blob, vector<ParticleLink>());
	vector<ParticleContact*> contacts = colisionDetector.detectCollisions();
	int iterations = contacts.size();
	ParticleContactResolver resolver(iterations);
	resolver.resolveContact(contacts, duration);
}
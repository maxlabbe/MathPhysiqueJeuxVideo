#include"World.h"

World::World(Plane& plane) : m_plane(plane) 
{
	DisplayablePlane* dPlane = new DisplayablePlane(plane);
	m_displayables = new vector<Displayable*>;
	//m_displayables->push_back(dPlane);

	m_forceRegister = ForceRegister();

	// Blob creation
	Particle* p1 = new Particle(1.0f, Vector3D(0, 0, 0), Vector3D(0, 0, 2), Vector3D(), Vector3D());
	Particle* p2 = new Particle(1.0f, Vector3D(0, 0, 2), Vector3D(0, 0, -1), Vector3D(), Vector3D());
	Particle* p3 = new Particle(1.0f, Vector3D(1, 1.5, -0.5), Vector3D(), Vector3D(), Vector3D());
	Particle* p4 = new Particle(1.0f, Vector3D(1, 1, -1), Vector3D(), Vector3D(), Vector3D());
	Particle* p5 = new Particle(1.0f, Vector3D(1, 2, -1), Vector3D(), Vector3D(), Vector3D());
	AddParticle(p1);
	AddParticle(p2);
	AddParticle(p3);
	/*AddParticle(p4);
	AddParticle(p5);*/

	// Spring forces
	ParticleSpring* ps12 = new ParticleSpring(*p2, 4.0f, 1.0f);
	m_forceRegister.registerForce(p1, ps12);
	ParticleSpring* ps21 = new ParticleSpring(*p1, 4.0f, 1.0f);
	m_forceRegister.registerForce(p2, ps21);

	

	AnchoredSpring* as31 = new AnchoredSpring(p1->getPositionPtr(), 4.0f, 1.0f);
	m_forceRegister.registerForce(p3, as31);

	// Drag forces
	DragGenerator* drag = new DragGenerator(0.1f, 0.1f);
	m_forceRegister.registerForce(p3, drag);
	/*ParticleSpring* ps23 = new ParticleSpring(*p3);
	m_forceRegister.registerForce(p2, ps23);
	ParticleSpring* ps34 = new ParticleSpring(*p4);
	m_forceRegister.registerForce(p3, ps34);
	ParticleSpring* ps45 = new ParticleSpring(*p5);
	m_forceRegister.registerForce(p1, ps45);*/

	// Gravity force
	//for (Particle* particle : m_blob)
	//{
	//	GravityGenerator* gg = new GravityGenerator();
	//	m_forceRegister.registerForce(particle, gg);
	//}


}

void World::updateWorld(float duration)
{
	m_forceRegister.updateAllForces(duration/1000);
	for (Particle* particle : m_blob)
	{
		particle->integrate(duration/1000);
	}
}

void World::AddParticle(Particle* particle) 
{
	m_blob.push_back(particle);
	DisplayableParticle* dp = new DisplayableParticle(*particle, 0.5);
	m_displayables->push_back(dp);
}
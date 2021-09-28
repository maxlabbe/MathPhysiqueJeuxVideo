#ifndef LOGIC_H
#define LOGIC_H

#include<vector>
#include<chrono>

#include "Camera.h"
#include"InputsHandler.h"
#include"Projectile.h"

class Logic
{
public :

	Logic(GLFWwindow* window, InputsHandler& inputsHandler);
	void updateLogic();
	vector<Displayable*> getDisplayables();

	Camera* getCamera() { return m_camera; }

private :

	InputsHandler& m_inputsHandler;
	GLFWwindow* m_window;
	Camera* m_camera;

	vector<Projectile> m_projectiles;
	chrono::steady_clock::time_point m_lastTime;
	bool m_firstRightClick;
	bool m_firstLeftClick;
	bool m_littleProjectile;
	bool m_mediumProjectile;
	bool m_bigProjectile;

	void moveCamera();
	void updateProjectileType();
	void shoot();
	void updateProjectiles();
	void addProjectile(Vector3D initPos, Vector3D initVelocity, float gravity, float lifespan = 4000.0);

};

#endif

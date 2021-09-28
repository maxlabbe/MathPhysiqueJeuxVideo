#ifndef DISPLAY_H
#define DISPLAY_H


#include <vector>
#include "Particle.h"
#include "Displayable.h"
#include"shaderClass.h"
#include"Camera.h"
#include<GLFW/glfw3.h>

class Display
{

public :

	void addDisplayable(Displayable*);
	void mainLoop();
	Camera* GetCamera();
	GLFWwindow* GetWindow();
	void moveParticle(Particle& p);

	// Constructors 

	Display
	(
		unsigned int window_width,
		unsigned int window_height,
		char* window_title,
		char* vertexShaderFile = "noTex.vert",
		char* fragmentShaderFile = "noTex.frag"
	);

private :

	vector<Displayable*> m_displayables;
	unsigned int m_width;
	unsigned int m_height;
	GLFWwindow* m_window;
	Shader m_shader;
	Camera* m_camera;
	char* m_window_title;
	//Particle m_p;
};


#endif

#ifndef DISPLAY_H
#define DISPLAY_H


#include <vector>
#include "Particle.h"
#include"DisplayableLine.h"
#include"shaderClass.h"
#include"Camera.h"
#include<GLFW/glfw3.h>
#include"Logic.h"

class Display
{

public :

	// Constructors 

	Display
	(
		GLFWwindow* window,
		Camera* camera,
		Logic& logic,
		Shader& shader
	);

	void addDisplayable(Displayable*);
	void updateDisplay();

private :

	vector<Displayable*> m_displayables;
	GLFWwindow* m_window;
	Shader m_shader;
	Camera* m_camera;
	Logic& m_logic;
};


#endif

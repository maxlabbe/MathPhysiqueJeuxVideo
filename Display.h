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
	Camera GetCamera();
	GLFWwindow* GetWindow();

	// Constructors 

	Display
	(
		unsigned int window_width, 
		unsigned int window_height,
		char * window_title,
		string vertexShaderFile="noTex.vert", 
		string fragmentShaderFile="noTex.frag"
	);

private :

	vector<Displayable*> displayables;
	unsigned int width;
	unsigned int height;
	GLFWwindow* window;
	Shader shader;
	Camera camera;
	string vertexShaderFile;
	string fragmentShaderFile;
	char* window_title;
};


#endif

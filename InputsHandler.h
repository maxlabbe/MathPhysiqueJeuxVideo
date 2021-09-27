#ifndef INPUTS_HANDLER_H
#define INPUTS_HANDLER_H

#include"Camera.h"

class Display;


class InputsHandler
{

public :

	InputsHandler(GLFWwindow* window, Camera* camera, Display* display);
	InputsHandler() {};
	void handleInputs();
	void handleKeyInputs();
	void handleRightClick();
	bool handleLeftClick();
	bool handleLeftClickDepressed();

private :



	// Prevents the camera from jumping around when first clicking right click
	bool firstRightClick = true;
	bool firstLeftClick = false;
	Display* display;
	Camera* camera;
	GLFWwindow* window;
};

#endif


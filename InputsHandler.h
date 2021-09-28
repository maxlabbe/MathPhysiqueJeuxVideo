#ifndef INPUTS_HANDLER_H
#define INPUTS_HANDLER_H

#include<GLFW/glfw3.h>
#include"Common.h"

class InputsHandler
{
public :

	InputsHandler(GLFWwindow* window);

	void UpdateInputs();

	double getMouseX() { return m_mouseX; }
	double getMouseY() { return m_mouseY; }

	bool MoveForward();
	bool MoveBack();
	bool MoveUp();
	bool MoveDown();
	bool MoveLeft();
	bool MoveRight();
	
	bool ChangeCameraDirection();
	
	bool Shoot();

	bool pressLeft();
	bool pressRight();

	bool pressJ();
	bool pressK();
	bool pressL();


private:

	GLFWwindow* m_window;
	int m_width;
	int m_height;
	double m_mouseX;
	double m_mouseY;

	bool m_keyA;
	bool m_keyW;
	bool m_keyS;
	bool m_keyD;
	bool m_keyJ;
	bool m_keyK;
	bool m_keyL;
	bool m_keySpace;
	bool m_keyLeftCtrl;

	bool m_mouseButtonRight;
	bool m_mouseButtonLeft;
	bool m_firstRightClick;
	bool m_firstLeftClick;
};

#endif

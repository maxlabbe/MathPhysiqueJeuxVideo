#ifndef INPUTS_HANDLER_H
#define INPUTS_HANDLER_H

#include<GLFW/glfw3.h>
#include"Common.h"

class InputsHandler
{
public :

	/// <summary>
	/// Inputs handler constructor
	/// </summary>
	/// <param name="window"> GLFWwindow* : window which the programm capture the input </param>
	InputsHandler(GLFWwindow* window);

	/// <summary>
	/// Update all the inputs
	/// </summary>
	void UpdateInputs();

	/// <summary>
	/// Return the mousse's x coodonate in the window
	/// </summary>
	/// <returns> double : the x coordonate </returns>
	double getMouseX() { return m_mouseX; }

	/// <summary>
	/// the mousse's y coodonate in the window
	/// </summary>
	/// <returns> double : the y coordonate </returns>
	double getMouseY() { return m_mouseY; }

	/// <summary>
	/// return true if the forward key is press
	/// </summary>
	/// <returns> bool : true if the forward key is press, else false </returns>
	bool MoveForward();

	/// <summary>
	/// return true if the backward key is press
	/// </summary>
	/// <returns> bool : true if the backward key is press, else false </returns>
	bool MoveBack();

	/// <summary>
	/// return true if the up key is press
	/// </summary>
	/// <returns> bool : true if the up key is press, else false </returns>
	bool MoveUp();

	/// <summary>
	/// return true if the down key is press
	/// </summary>
	/// <returns> bool : true if the down key is press, else false </returns>
	bool MoveDown();

	/// <summary>
	/// return true if the foleftrward key is press
	/// </summary>
	/// <returns> bool : true if the left key is press, else false </returns>
	bool MoveLeft();

	/// <summary>
	/// return true if the right key is press
	/// </summary>
	/// <returns> bool : true if the right key is press, else false </returns>
	bool MoveRight();
	
	/// <summary>
	/// return true if the change camera key is press
	/// </summary>
	/// <returns> bool : true if the change camera key is press, else false </returns>
	bool ChangeCameraDirection();

	/// <summary>
	/// return true if the left button on the mousse is press
	/// </summary>
	/// <returns> bool : true if the left button key is press, else false </returns>
	bool pressLeft();

	/// <summary>
	/// return true if the right button on the mousse is press
	/// </summary>
	/// <returns> bool : true if the right button key is press, else false </returns>
	bool pressRight();

	/// <summary>
	/// return true if the J button is press
	/// </summary>
	/// <returns> bool : true if the J button key is press, else false </returns>
	bool pressJ();

	/// <summary>
	/// return true if the K button is press
	/// </summary>
	/// <returns> bool : true if the K button key is press, else false </returns>
	bool pressK();

	/// <summary>
	/// return true if the L button is press
	/// </summary>
	/// <returns> bool : true if the L button key is press, else false </returns>
	bool pressL();


private:

	// Window which the scene is display
	GLFWwindow* m_window;

	// width of the window
	int m_width;

	// height of the window
	int m_height;

	// mousse  coordonate
	double m_mouseX;

	// mousse y coordonate
	double m_mouseY;

	// flag if A is press left
	bool m_keyA;

	// flag if W is press forward
	bool m_keyW;

	// flag if S is press backward
	bool m_keyS;

	// flag if D is press right
	bool m_keyD;

	// flag if J is press
	bool m_keyJ;

	// flag if K is press
	bool m_keyK;

	// flag if L is press
	bool m_keyL;

	// flag if space is press up
	bool m_keySpace;

	// flag if ctrl is press down
	bool m_keyLeftCtrl;

	// flag if left button on the mousse is press
	bool m_mouseButtonRight;

	// flag if left button n the mouss is press
	bool m_mouseButtonLeft;

	// flag if it's the first click on the right button on the mousse
	bool m_firstRightClick;
};

#endif

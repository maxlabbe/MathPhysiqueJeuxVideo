#include"Display.h"
#include"DisplayableParticle.h"
#include"DisplayableLine.h"
#include"Particle.h"
#include <thread>
#include <windows.h>

bool leftclick(Display* display)
{
	if (glfwGetMouseButton(display->GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Display* display = new Display(800, 800, "MPJV");
	//InputsHandler inputs(display->GetWindow(), display->GetCamera(), display);

	float g = 0.1f;

	/* Coordinate system */
	// x axis = red
	// y axis = green
	// z axis = blue
	DisplayableLine* dlx = new DisplayableLine(Vector3D(-1, 0, 0), Vector3D(1, 0, 0), Vector3D(0.9, 0.0, 0.0));
	display->addDisplayable(dlx);
	DisplayableLine* dly = new DisplayableLine(Vector3D(0, -1, 0), Vector3D(0, 1, 0), Vector3D(0.0, 0.9, 0.0));
	display->addDisplayable(dly);
	DisplayableLine* dlz = new DisplayableLine(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Vector3D(0.0, 0.0, 0.9));
	display->addDisplayable(dlz);
	//std::thread th(&Display::mainLoop, display);
	display->mainLoop();
	// th.join();

	return 0;
}


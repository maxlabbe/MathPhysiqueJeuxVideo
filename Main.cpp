#include"Display.h"
#include"DisplayableParticle.h"
#include"DisplayableLine.h"
#include"Particle.h"
#include <thread>
#include <windows.h>

int main()
{
	Display* display = new Display(800, 800, "MPJV");

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

	// Display thread
	std::thread th(&Display::mainLoop, display);

	while (true)
	{
		bool firstClick = false;
		if (glfwGetMouseButton(display->GetWindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{

			// Prevents camera from jumping on the first click
			if (!firstClick)
			{
				firstClick = true;
				Vector3D position(display->GetCamera().Position.x, display->GetCamera().Position.y, display->GetCamera().Position.z);
				Vector3D velocity(display->GetCamera().Orientation.x, display->GetCamera().Orientation.y, display->GetCamera().Orientation.z);
				Particle p = Particle(1.0f, position, velocity, Vector3D(0, -1 * g, 0), 1.001f);
				DisplayableParticle* dp = new DisplayableParticle(p, 0.01f); // Radius = 1 cm
				display->addDisplayable(dp);

				auto start = chrono::high_resolution_clock::now();
				auto current = chrono::high_resolution_clock::now();
				std::chrono::duration<float, std::milli> diffTime = current - start;
				int pos_print_frequence = 1;
				int count = 0;
				while (diffTime.count() < 4000.0)
				{
					current = chrono::high_resolution_clock::now();
					diffTime = current - start;
					float time = diffTime.count();
					p.integrate(time / 1000.0);
					cout << "Position : " << p.getPosition() << " | Time : " << time / 1000.0 << "seconds" << endl;
					if (count > pos_print_frequence)
					{
						count = 0;
						Particle print_p = Particle(1.0f, p.getPosition(), Vector3D(), Vector3D(), 1.001f);
						DisplayableParticle* d_print_p = new DisplayableParticle(print_p, 0.01f, true); // Radius = 1 cm
						display->addDisplayable(d_print_p);
					}
					std::this_thread::sleep_for(30ms); // About 30 fps
					count++;
				}
			}
		}
		else if ()
		{
			// Makes sure the next time the camera looks around it doesn't jump
			firstClick = false;

		}				
	}
	
	th.join();

	return 0;
}


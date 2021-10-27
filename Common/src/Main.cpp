#include"DisplayableParticle.h"
#include"Particle.h"
#include"Logic.h"
#include <thread>
#include <windows.h>


int main()
{
	/* #### INITIALIZE THE WINDOW ##### */

	int width = 800;
	int height = 800;

	// Initialize GLFW
	glfwInit();

	// GLFW version : 3.3.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// GLFW profile : Core = modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "MathsPhysiqueJeuxVideo", NULL, NULL);

	// Raise an error is the window is not initialized
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	// Make the current thread the current context of the window
	glfwMakeContextCurrent(window);

	// Configures OpenGL
	gladLoadGL();

	// Area of the window where OpenGL renders
	glViewport(0, 0, width, height);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Create the inputs, logics and display of the game
	InputsHandler inputsHandler(window);
	Display display(window, Shader("./Graphics/src/default.vert", "./Graphics/src/default.frag"));
	World world(Particle(5.9f * pow(10, 24), Vector3D(0, -1001, 0), Vector3D(), Vector3D(), Vector3D(), 1000.0f));
	Logic logic(window, inputsHandler, display, world);
	

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		inputsHandler.UpdateInputs();
		for (int i = 0; i < 10; i++)
		{
			logic.updateLogic();
		}
		
		display.UpdateDisplay();
	}

	// Delete all the objects created for the display
	display.ClearDisplay();

	// Delete window and terminate GLFW
	glfwDestroyWindow(window);

	glfwTerminate();

	return 0;
}


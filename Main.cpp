#include"Display.h"
#include"DisplayableParticle.h"
#include"Particle.h"
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
	//glfwGetWindowSize(window, &width, &height);
	// Configures OpenGL
	gladLoadGL();
	// Area of the window where OpenGL renders
	glViewport(0, 0, width, height);
	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);



	InputsHandler inputsHandler(window);
	Logic logic(window, inputsHandler);
	Display display(window, logic.getCamera(), logic, Shader("default.vert", "default.frag"));

	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		inputsHandler.UpdateInputs();
		logic.updateLogic();
		display.updateDisplay();
	}

	// Delete window and terminate GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}


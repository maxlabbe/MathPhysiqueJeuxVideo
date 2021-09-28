#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include"Common.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"

class Camera
{
public:
	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation;
	glm::vec3 Up;

	// Stores the width and height of the window
	int width;
	int height;

	// Adjust the speed of the camera and it's sensitivity when looking around
	float speed = 0.003f;
	float sensitivity = 50.0f;

	/// <summary>
	/// Camera constructor
	/// </summary>
	/// <param name="width">int : window's width</param>
	/// <param name="height"> int : window's height </param>
	/// <param name="position"> glm::vec3 : camera's position </param>
	/// <param name="orientation"> glm::vec3 : camera's orientation </param>
	/// <param name="up"></param>
	Camera(int camWidth, int camHeight, glm::vec3 camPosition, glm::vec3 camOrientation, glm::vec3 vectorUp);

	/// <summary>
	/// Updates and exports the camera matrix to the Vertex Shader 
	/// </summary>
	/// <param name="FOVdeg"> float : field of view in degree </param>
	/// <param name="nearPlane"> float : nearest distance where the  object is visible </param>
	/// <param name="farPlane"> float : farthest distance where the  object is visible </param>
	/// <param name="shader"> Shader& : shader that will draw the objects seen by the camera </param>
	/// <param name="uniform">const char* : shader's variable's name that will draw what is seen by the camera</param>
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
};
#endif

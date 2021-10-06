#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

/// <summary>
///	Reads a text file and outputs a string with everything in the text file.
/// </summary>
/// <param name="filename">const char* : name or path of the file.</param>
/// <returns>std::string : content of the text file</returns>
std::string get_file_contents(const char* filename);

/// <summary>
/// Handles an GL Shader program with a vertex shader and a fragment shader.
/// The vertex shader links vertices to draw the object.
/// The fragment shader handles the color of the object.
/// </summary>
class Shader
{
public:
	// Reference ID of the Shader Program
	GLuint ID;
	
	/// <summary>
	/// Constructor that builds a shader program with two files.
	/// </summary>
	/// <param name="vertexFile">const char* : path to the vertex shader code file</param>
	/// <param name="fragmentFile">const char* : path to the fragment shader code file</param>
	Shader(const char* vertexFile, const char* fragmentFile);

	/// <summary>
	/// Activates the Shader Program, makes GL use it.
	/// </summary>
	void Activate();

	/// <summary>
	/// Deletes the Shader Program
	/// </summary>
	void Delete();

private:
	
	/// <summary>
	/// Checks if the different Shaders have compiled properly
	/// </summary>
	/// <param name="shader">unsigned int : ID of the shader to check</param>
	/// <param name="type">const char* : type of the shader</param>
	void compileErrors(unsigned int shader, const char* type);
};
#endif

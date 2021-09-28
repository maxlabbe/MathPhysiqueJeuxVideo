#version 330 core

// Like the default but with no tex

// Outputs colors in RGBA
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec3 color;

void main()
{
	FragColor = vec4(color, 1.0f);
}
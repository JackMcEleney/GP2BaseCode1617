#version 410
layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec4 vertexColors;

out vec4 vertexColorsOut;

uniform mat4 MVP;

void main()
{
	vertexColorsOut = vertexColors;
	gl_Position = MVP *vec4(vertexPosition, 1.0);
}
#version 410
layout(location=0) in vec3 vertexPosition;
layout(location=1) in vec4 vertexColors;
layout(location=2) in vec2 vertexTextureCoords;

out vec4 vertexColorsOut;
out vec2 vertexTextureCoordsOut;

uniform mat4 MVP;

void main()
{
	vertexColorsOut = vertexColors;
	vertexTextureCoordsOut = vertexTextureCoords;
	gl_Position = MVP *vec4(vertexPosition, 1.0);
}
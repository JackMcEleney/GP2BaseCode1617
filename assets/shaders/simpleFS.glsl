#version 410

out vec4 FragColor;
uniform vec4 Colors = vec4 (1.0f, 1.0f, 1.0f, 1.0f);

in vec4 vertexColorsOut;

uniform sampler2D diffuseSampler;

void main ()
{
	FragColor = vertexColorsOut*Colors;
}
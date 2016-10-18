#version 410

out vec4 FragColor;
uniform vec4 Colors = vec4 (1.0f, 1.0f, 1.0f, 1.0f);

in vec4 vertexColorsOut;
in vec2 vertexTextureCoordsOut;

uniform sampler2D diffuseSampler;

void main ()
{
	FragColor = texture(diffuseSampler, vertexTextureCoordsOut);
}
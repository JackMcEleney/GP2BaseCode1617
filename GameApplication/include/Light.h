#ifndef LIGHT_H
#define LIGHT_H

#include "Common.h"

struct Light
{
	vec4 DiffuseColour;
	vec4 SpecularColour;

	vec3 Direction;
};

#endif
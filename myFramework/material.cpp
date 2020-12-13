#include <myFramework/material.h>

Material::Material(const char* _imagepath)
{
	// Load the texture using the texture loader
	textureloader = new Textureloader(_imagepath);
}

Material::~Material()
{
}
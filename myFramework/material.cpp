#include <myFramework/material.h>

Material::Material(const char* _imagepath)
{
	// Load the texture using any two methods
	//GLuint Texture = loadBMP_custom(_imagepath);
	texture = loadDDS(_imagepath);
}

Material::~Material()
{
}
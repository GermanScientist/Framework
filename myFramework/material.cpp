#include <myFramework/material.h>

Material::Material()
{
	// Load the texture using the texture loader
	textureloader = new Textureloader();
}

Material::~Material()
{
	delete textureloader;
}
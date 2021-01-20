#include <myFramework/material.h>

//Constructor
Material::Material()
{
	texture = -1;

	//Load shaders
	shader = new Shader();

	// Load the texture using the texture loader
	textureloader = new Textureloader();
}

//Destructor
Material::~Material()
{
	//Deletes texture loader
	delete textureloader;

	//Deletes shader
	delete shader;
}
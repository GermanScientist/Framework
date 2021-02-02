#include <myFramework/cube.h>

//Constructor
Cube::Cube(const char* _imagepath)
{
	//Get the type of the entity
	type = "Cube";

	//Create material
	material = new Material();
	material->loadDDS(_imagepath);
	material->getShader()->load3DShaders();

	mesh = new Mesh();
	mesh->generateCubeBuffers();
}

//Destructor
Cube::~Cube()
{
	delete material;
	delete mesh;
}
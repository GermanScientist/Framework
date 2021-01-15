#include <myFramework/cube.h>

//Constructor
Cube::Cube(const char* _imagepath)
{
	//Create material
	material = new Material();
	material->loadDDS(_imagepath);
	material->getShader()->load3DShaders();

	mesh = new Mesh();
	mesh->generateBuffers("Cube");
}

//Destructor
Cube::~Cube()
{
	delete material;
	delete mesh;
}
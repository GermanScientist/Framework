#include <myFramework/model.h>

//Constructor
Model::Model(const char* _path, const char* _imagepath)
{
	//Create material
	material = new Material();
	material->loadDDS(_imagepath);
	material->getShader()->load3DShaders();

	//Create the mesh
	mesh = new Mesh();
	mesh->loadObject(_path);
	mesh->generateBuffers("OBJ");
}

//Destructor
Model::~Model()
{
	delete material;
	delete mesh;
}
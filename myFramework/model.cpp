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
	bool loaded = loadOBJ(_path, vertices, uvs, normals);
	mesh->generateBuffers(vertices, uvs, normals);
}

//Destructor
Model::~Model()
{
	delete material;
	delete mesh;
}
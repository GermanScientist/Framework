#include <myFramework/model.h>

//Constructor
Model::Model(const char* _path, const char* _imagepath)
{
	//Create material
	material = new Material();
	material->loadDDS(_imagepath);
	material->load3DShaders();

	// Read our .obj file
	bool res = loadOBJ(_path, vertices, uvs, normals);

	//Create the mesh
	mesh = new Mesh();
	mesh->generateBuffers(vertices, uvs, normals);
}

//Destructor
Model::~Model()
{
	delete material;
	delete mesh;
}
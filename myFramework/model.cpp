#include <myFramework/model.h>

//Constructor
Model::Model()
{
	//Create material
	material = new Material();

	//Create the mesh
	mesh = new Mesh();
}

//Destructor
Model::~Model()
{
	delete material;
	delete mesh;
}

//Loads a texture for the model
void Model::loadTexture(const char* _imagepath)
{
	material->loadDDS(_imagepath);
	material->getShader()->load3DShaders();
}

//Loads a color for the model
void Model::loadColor(std::string _color)
{
}

//Loads an object for the model
void Model::loadObject(const char* _path)
{
	bool loaded = loadOBJ(_path, vertices, uvs, normals);
	mesh->generateBuffers(vertices, uvs, normals);
}

//Loads a cube for the model
void Model::loadCube()
{
}

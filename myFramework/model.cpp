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
	this->vertices = {
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f,-1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f,-1.0f, 1.0f)
	};

	// Two UV coordinatesfor each vertex. They were created withe Blender.
	this->uvs = {
		glm::vec2(0.000059f, 1.0f - 0.000004f),
		glm::vec2(0.000103f, 1.0f - 0.336048f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(1.000023f, 1.0f - 0.000013f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.999958f, 1.0f - 0.336064f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.336024f, 1.0f - 0.671877f),
		glm::vec2(0.667969f, 1.0f - 0.671889f),
		glm::vec2(1.000023f, 1.0f - 0.000013f),
		glm::vec2(0.668104f, 1.0f - 0.000013f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.000059f, 1.0f - 0.000004f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(0.336098f, 1.0f - 0.000071f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(0.336024f, 1.0f - 0.671877f),
		glm::vec2(1.000004f, 1.0f - 0.671847f),
		glm::vec2(0.999958f, 1.0f - 0.336064f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.668104f, 1.0f - 0.000013f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(0.667979f, 1.0f - 0.335851f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(0.668104f, 1.0f - 0.000013f),
		glm::vec2(0.336098f, 1.0f - 0.000071f),
		glm::vec2(0.000103f, 1.0f - 0.336048f),
		glm::vec2(0.000004f, 1.0f - 0.671870f),
		glm::vec2(0.336024f, 1.0f - 0.671877f),
		glm::vec2(0.000103f, 1.0f - 0.336048f),
		glm::vec2(0.336024f, 1.0f - 0.671877f),
		glm::vec2(0.335973f, 1.0f - 0.335903f),
		glm::vec2(0.667969f, 1.0f - 0.671889f),
		glm::vec2(1.000004f, 1.0f - 0.671847f),
		glm::vec2(0.667979f, 1.0f - 0.335851f)
	};

	this->normals = {
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, -1.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, -1.0f)
	};

	mesh->generateBuffers(vertices, uvs, normals);
}

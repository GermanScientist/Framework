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
		glm::vec3(1.0f, 1.0f, -1.0f),
		glm::vec3(1.0f, -1.0f, -1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(1.0f, -1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, -1.0f, 1.0f)
	};

	this->uvs = {
		glm::vec2(0.477862f, 0.942278f),
		glm::vec2(0.264834f, 0.729250f),
		glm::vec2(0.477862f, 0.729250f),
		glm::vec2(0.230402f, 0.595736f),

		glm::vec2(0.014082f, 0.379416f),
		glm::vec2(0.230402f, 0.379416f),
		glm::vec2(0.961710f, 0.594812f),
		glm::vec2(0.769216f, 0.402318f),

		glm::vec2(0.961710f, 0.402318f),
		glm::vec2(0.465031f, 0.260543f),
		glm::vec2(0.277666f, 0.073178f),
		glm::vec2(0.465031f, 0.073178f),

		glm::vec2(0.475174f, 0.613379f),
		glm::vec2(0.267523f, 0.405729f),
		glm::vec2(0.475174f, 0.405729f),
		glm::vec2(0.703759f, 0.596956f),

		glm::vec2(0.528954f, 0.422151f),
		glm::vec2(0.703759f, 0.422151f),
		glm::vec2(0.264834f, 0.942278f),
		glm::vec2(0.014082f, 0.595736f),

		glm::vec2(0.769216f, 0.594812f),
		glm::vec2(0.277666f, 0.260543f),
		glm::vec2(0.267523f, 0.613379f),
		glm::vec2(0.528954f, 0.596956f)
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

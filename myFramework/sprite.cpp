#include <myFramework/sprite.h>

//Constructor
Sprite::Sprite(const std::string& _imagepath)
{
	//Create a material
	material = new Material();
	material->loadTGA(_imagepath);
	material->getShader()->load2DShaders();

	mesh = new Mesh();

	//Vertex buffer data
	//Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	//A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	mesh->vertices = {
		glm::vec3(0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f),
		glm::vec3(-0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f),
		glm::vec3(-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f),

		glm::vec3(-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f),
		glm::vec3(0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f),
		glm::vec3(0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f)
	};

	//UV buffer data
	//Two UV coordinates for each vertex.
	mesh->uvs = {
		glm::vec2(1.0f, 1.0f),
		glm::vec2(0.0f, 1.0f),
		glm::vec2(0.0f, 0.0f),

		glm::vec2(0.0f, 0.0f),
		glm::vec2(1.0f, 0.0f),
		glm::vec2(1.0f, 1.0f)
	};

	mesh->normals = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f)
	};

	mesh->generateMesh();
}

//Destructor
Sprite::~Sprite()
{
	delete material;
	delete mesh;
}
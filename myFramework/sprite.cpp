#include <myFramework/sprite.h>

//Constructor
Sprite::Sprite(const std::string& _imagepath)
{
	//Get the type of the entity
	type = "Sprite";

	//Create a material
	material = new Material();
	material->loadTGA(_imagepath);
	material->getShader()->load2DShaders();

	//Vertex buffer data
	//Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	//A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	std::vector<GLfloat> vertexBufferdata = {
		0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f,
		-0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f,
		-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,

		-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,
		 0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,
		 0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f
	};

	//UV buffer data
	//Two UV coordinates for each vertex.
	std::vector<GLfloat> uvBufferdata = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	mesh = new Mesh();
	mesh->generateBuffers(vertexBufferdata, uvBufferdata);
}

//Destructor
Sprite::~Sprite()
{
	delete material;
	delete mesh;
}
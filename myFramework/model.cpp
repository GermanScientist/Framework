#include <myFramework/model.h>

//Constructor
Model::Model(const char* _path, const char* _imagepath)
{
	//Create material
	material = new Material();
	material->loadDDS(_imagepath);
	material->load3DShaders();

	// these will be set correctly in loadTGA()
	width = 0;
	height = 0;

	//Generate and bind vertex arrays
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	// Read our .obj file
	bool res = loadOBJ(_path, vertices, uvs, normals);

	//Generate buffers
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
}

//Destructor
Model::~Model()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteBuffers(1, &vertexArrayID);

	delete material;
}
#include <myFramework/mesh.h>

//Constructor
Mesh::Mesh()
{
	vertexbuffer = -1;
	uvbuffer = -1;
	normalbuffer = -1;

	vertexArrayID = -1;
}

//Destructor
Mesh::~Mesh()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteBuffers(1, &vertexArrayID);
}

//Generate the buffers for the object
void Mesh::generateMesh() {

	//Generate and bind vertex arrays
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	
	//Load the object to the VBO
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
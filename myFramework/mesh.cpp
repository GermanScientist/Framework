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
void Mesh::generateBuffers(std::vector<glm::vec3>& _vertices, std::vector<glm::vec2>& _uvs, std::vector<glm::vec3>& _normals) {

	this->vertices = _vertices;
	this->uvs = _uvs;
	this->normals = _normals;
	
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

//Generate the buffers for the object
void Mesh::generateBuffers(std::vector<GLfloat>& _vertexBufferdata, std::vector<GLfloat>& _uvBufferdata) {

	this->vertexBufferdata = _vertexBufferdata;
	this->uvBufferdata = _uvBufferdata;

	//Generate and bind vertex arrays
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);

	//Generate buffers
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexBufferdata.size() * sizeof(GLfloat), &vertexBufferdata[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvBufferdata.size() * sizeof(GLfloat), &uvBufferdata[0], GL_STATIC_DRAW);
}